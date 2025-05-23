/**************************************************************************

Filename    :   D3D1x_HAL.cpp
Content     :   
Created     :   Mar 2011
Authors     :   Bart Muzzin

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/
//#include "pch.h"

#include "Kernel/SF_Debug.h"
#include "Kernel/SF_Random.h"
#include "D3D1x_HAL.h"
#include "Kernel/SF_HeapNew.h"
#include <d3dx9.h>

#include <stdio.h>

//#if SF_CC_MSVC >= 1600 // MSVC 2010
//#include <crtdefs.h>
//#else
//#include <xutility>
//#endif // SF_CC_MSVC >= 1600 // MSVC 2010

namespace Scaleform { namespace Render { namespace D3D1x {

#if !defined(SF_BUILD_SHIPPING)
LPD3DPERF_BEGINEVENT PixMarker::BeginEventFn =0;
LPD3DPERF_ENDEVENT   PixMarker::EndEventFn   =0;
#endif

static PixMarker MaskMarker(0, false);
static PixMarker RenderTargetMarker(0, false);
static PixMarker FilterMarker(0, false);

// ***** HAL_D3D1x

HAL::HAL(ThreadCommandQueue* commandQueue)
:   Render::HAL(commandQueue),
    pDevice(0),
    pDeviceContext(0),
    pRenderTargetView(0), 
    pDepthStencilView(0),
    Cache(Memory::GetGlobalHeap(), MeshCacheParams::PC_Defaults),
    FSManager(&Profiler),
    ShaderData(getThis()),
    PrevBatchType(PrimitiveBatch::DP_None),
    // Mask/Stencil vars
    StencilChecked(false), StencilAvailable(false), 
    DepthBufferAvailable(false),
    FillFlags(0),
    RasterMode(RasterMode_Default),
    CurrentConstantBuffer(0)

{
#if !defined(SF_BUILD_SHIPPING)
    HMODULE hdll = LoadLibrary( "D3D9.dll" );
    if (hdll)
    {
        PixMarker::BeginEventFn = (LPD3DPERF_BEGINEVENT)GetProcAddress( hdll, "D3DPERF_BeginEvent" );
        PixMarker::EndEventFn   = (LPD3DPERF_ENDEVENT)GetProcAddress( hdll, "D3DPERF_EndEvent" );
    }
#endif
}

HAL::~HAL()
{
    ShutdownHAL();
}

PrimitiveFill*  HAL::CreatePrimitiveFill(const PrimitiveFillData &data)
{
    return SF_HEAP_NEW(pHeap) PrimitiveFill(data);
}

// Should merge this with VSConstantsUpdateBuffer.
class MatrixUpdateAdapter_Base
{
public:
    MatrixUpdateAdapter_Base( HAL* hal ) : pHAL(hal), pConstantBuffer(0), Rows(0)
    {
        pConstantBuffer = hal->getNextConstantBuffer();
        if ( pConstantBuffer && 
            SUCCEEDED( D3D1xMapBuffer(hal->pDeviceContext, pConstantBuffer, 0, D3D1x(MAP_WRITE_DISCARD), 0, &MappedBuffer ) ))
        {
            Rows = (float*)MappedBuffer.pData;
        }
    }
    float* GetDestination() const 
    { 
        return Rows;
    }

    void Apply() const
    {
        if ( !Rows || !pConstantBuffer ) 
            return;
        D3D1xUnmapBuffer(pHAL->pDeviceContext, pConstantBuffer, 0);       
        pHAL->pDeviceContext->VSSetConstantBuffers(0, 1, &pConstantBuffer );
    }
private:
    HAL*                        pHAL;
    ID3D1x(Buffer)*             pConstantBuffer;
    D3D1x(MAPPED_BUFFER)        MappedBuffer;
    float*                      Rows;  
};

template< class _MatrixType >
class MatrixUpdateAdapter_Meshes : public MatrixUpdateAdapter_Base
{
public:
    MatrixUpdateAdapter_Meshes( HAL* hal, const Primitive::MeshEntry* meshes, unsigned count, unsigned matricesPerMesh ) : 
      MatrixUpdateAdapter_Base(hal), Count(count), MatricesPerMesh(matricesPerMesh), Meshes(meshes) { }

    typedef _MatrixType MatrixType;

    unsigned        GetCount() const { return Count; }
    unsigned        GetElementsPerTransform() const { return 4; } // always 4, even for 2D case.
    unsigned        GetMatricesPerMesh() const { return MatricesPerMesh; }
    const Matrix2F& GetVertexMatrix(unsigned i ) const { return Meshes[i].pMesh->VertexMatrix; }
    const HMatrix&  GetHMatrix(unsigned i) const { return Meshes[i].M; }

private:
    unsigned Count;
    unsigned MatricesPerMesh;
    const Primitive::MeshEntry* Meshes;
};

template< class _MatrixType >
class MatrixUpdateAdapter_Matrices : public MatrixUpdateAdapter_Base
{
public:
    MatrixUpdateAdapter_Matrices( HAL* hal, const StrideArray<const HMatrix>& matrixArray, unsigned matricesPerMesh, const Matrix2F & vertexMatrix ) : 
      MatrixUpdateAdapter_Base(hal), MatrixArray(matrixArray), MatricesPerMesh(matricesPerMesh), VertexMatrix(vertexMatrix) { }

    typedef _MatrixType MatrixType;

    unsigned        GetCount() const { return (unsigned)MatrixArray.GetSize(); }
    unsigned        GetElementsPerTransform() const { return 4; } // always 4, even for 2D case.
    unsigned        GetMatricesPerMesh() const { return MatricesPerMesh; }
    const Matrix2F& GetVertexMatrix(unsigned i ) const { SF_UNUSED(i); return VertexMatrix; }
    const HMatrix&  GetHMatrix(unsigned i) const { return MatrixArray[i]; }

private:
    // Hide warnings (this class is never assigned to).
    MatrixUpdateAdapter_Matrices & operator=( const MatrixUpdateAdapter_Matrices & k )
    { SF_ASSERT(0); return *this; }

    const StrideArray<const HMatrix>& MatrixArray;
    unsigned MatricesPerMesh;
    const Matrix2F& VertexMatrix;
};

// Class used with ProfileViews to change the rendering method of mask geometry.
class ProfileViewScopedOMChange
{
    bool & DrawingMask;
    ID3D1x(DeviceContext)* pDeviceContext;
    ID3D1x(BlendState)* pBlendState;
    ID3D1x(DepthStencilState)* pDepthStencilState;
    UINT StencilRef;
    ProfileViewScopedOMChange& operator=(const ProfileViewScopedOMChange&) { };
public:
    ProfileViewScopedOMChange(bool & drawingMask, ID3D1x(DeviceContext)* pcontext, ID3D1x(BlendState)* pblendOverride, ID3D1x(DepthStencilState)* pdepthOverride) :
        DrawingMask(drawingMask), pDeviceContext(pcontext), pBlendState(pblendOverride), pDepthStencilState(pdepthOverride)
    {
        DrawingMask = true;
        pDeviceContext->OMGetBlendState(&pBlendState, 0, 0);
        pDeviceContext->OMGetDepthStencilState(&pDepthStencilState, &StencilRef);
        pDeviceContext->OMSetBlendState(pblendOverride, 0, 0xFFFFFFFF);
        pDeviceContext->OMSetDepthStencilState(pdepthOverride, 0);
    }
    ~ProfileViewScopedOMChange()
    {
        pDeviceContext->OMSetBlendState(pBlendState, 0, 0xFFFFFFFF);
        pDeviceContext->OMSetDepthStencilState(pDepthStencilState, StencilRef);
        DrawingMask = false;
    }
};

// Draws a range of pre-cached and preprocessed primitives
void HAL::DrawProcessedPrimitive(Primitive* pprimitive,
                                 PrimitiveBatch* pstart, PrimitiveBatch *pend)
{
    SF_AMP_SCOPE_RENDER_TIMER(__FUNCTION__, Amp_Profile_Level_High);
    PixMarker event(__FUNCTIONW__);

    if (!checkState(HS_InDisplay, __FUNCTION__) ||
        !pprimitive->GetMeshCount() )
        return;

    // If in overdraw profile mode, and this primitive is part of a mask, draw it in color mode.
    static bool drawingMask = false;
    if ( !Profiler.ShouldDrawMask() && !drawingMask && (HALState & HS_DrawingMask) )
    {
        ProfileViewScopedOMChange change(drawingMask, pDeviceContext, BlendStates[GetBlendType(Blend_None, Write_None)], DepthStencilStates[StencilMode_Disabled]);
        DrawProcessedPrimitive(pprimitive, pstart, pend);
    }

    SF_ASSERT(pend != 0);

    Primitive::MeshEntry* meshes = &pprimitive->Meshes[0];
    PrimitiveBatch* pbatch = pstart ? pstart : pprimitive->Batches.GetFirst();

    // Assuption: all meshes within a batch are 2D or 3D.
    bool            has3D = pbatch->GetMeshCount() > 0 ? meshes[0].M.Has3D() : false;

    if ( has3D )
        drawProcessedPrimitive<Matrix4F>(pprimitive, pbatch, pend);
    else
        drawProcessedPrimitive<Matrix2F>(pprimitive, pbatch, pend);
}

template< class MatrixType >
void HAL::drawProcessedPrimitive(Primitive* pprimitive,
                                 PrimitiveBatch* pbatch, PrimitiveBatch *pend)
{
    Primitive::MeshEntry* meshes = &pprimitive->Meshes[0];
    bool shaderManagerSuccess = SManager.ApplyPrimitiveFill(pprimitive->pFill);
    unsigned bidx = 0;
    while (pbatch != pend)
    {
        // pBatchMesh can be null in case of error, such as VB/IB lock failure.
        MeshCacheItem* pmesh = (MeshCacheItem*)pbatch->GetCacheItem();
        unsigned       meshIndex = pbatch->GetMeshIndex();

        if (pmesh)
        {
            Profiler.SetBatch((UPInt)pprimitive, bidx);

            bool primSuccess = SManager.ApplyPrimitiveBatchFill(pprimitive->pFill->GetType(), FillFlags, pbatch->pFormat, pbatch->Type);

            if (shaderManagerSuccess && (HALState & HS_ViewValid) && primSuccess)
            {
                SF_ASSERT((pbatch->Type != PrimitiveBatch::DP_Failed) &&
                          (pbatch->Type != PrimitiveBatch::DP_Virtual));

                // Draw the object with cached mesh.
                UPInt   indexOffset = pmesh->IBAllocOffset / sizeof (IndexType);

                ID3D1x(Buffer)* pb = (pmesh->pVertexBuffer->GetHWBuffer());
                UINT offset = (UINT)pmesh->VBAllocOffset;
                pDeviceContext->IASetIndexBuffer(pmesh->pIndexBuffer->GetHWBuffer(), sizeof(IndexType) == 2 ? DXGI_FORMAT_R16_UINT : DXGI_FORMAT_R32_UINT, 0 );
                pDeviceContext->IASetVertexBuffers(0, 1, &pb, &(pbatch->pFormat->Size), &offset );

                if (pbatch->Type != PrimitiveBatch::DP_Instanced)
                {
                    applyMatrixConstants(MatrixUpdateAdapter_Meshes<MatrixType>(
                        this,
                        meshes + meshIndex, 
                        pbatch->GetMeshCount(), 
                        pprimitive->MatricesPerMesh));

                    pDeviceContext->DrawIndexed( pmesh->IndexCount, (UINT)indexOffset, 0 );

                    AccumulatedStats.Meshes += pmesh->MeshCount;
                    AccumulatedStats.Triangles += pmesh->IndexCount / 3;
                }
                else
                {
                    StrideArray<const HMatrix> matrixArray(&meshes[meshIndex].M, pbatch->GetMeshCount(), sizeof(Primitive::MeshEntry));

                    applyMatrixConstants(MatrixUpdateAdapter_Matrices<MatrixType>(
                            this,
                            matrixArray, 
                            pprimitive->MatricesPerMesh, 
                            meshes[meshIndex].pMesh->VertexMatrix));

                    pDeviceContext->DrawIndexedInstanced( pmesh->IndexCount, pbatch->GetMeshCount(), (UINT)indexOffset, 0, 0 );

                    AccumulatedStats.Meshes += pbatch->GetMeshCount();
                    AccumulatedStats.Triangles += (pmesh->IndexCount / 3) * pbatch->GetMeshCount();
                }

                AccumulatedStats.Primitives++;
            }

            pmesh->MoveToCacheListFront(MCL_ThisFrame);
        }
        
        pbatch = pbatch->GetNext();
        ++bidx;
    }
}


class VSConstantsUpdateBuffer
{
public:

    enum {
        MaxInstances = (20 < SF_RENDER_D3D1x_INSTANCE_MATRICES) ?
                       20 : SF_RENDER_D3D1x_INSTANCE_MATRICES,
        MaxInstanceData = SF_RENDER_D3D1x_ROWS_PER_INSTANCE
    };

    VSConstantsUpdateBuffer(HAL* hal, const ProfileViews* profiler)
        : pHAL(hal), Profiler(profiler), InstanceCount(0), TextureCount(0), 
          pConstantBuffer(0), Rows(0)
    {
        pConstantBuffer = hal->getNextConstantBuffer();
        if ( pConstantBuffer && 
             SUCCEEDED( D3D1xMapBuffer(hal->pDeviceContext, pConstantBuffer, 0, D3D1x(MAP_WRITE_DISCARD), 0, &MappedBuffer ) ))
        {
            Rows = (float*)MappedBuffer.pData;
        }
    }


    static const int ept = 4;

    template< class MatrixType >
    void    SetInstanceData(const StrideArray<HMatrix>& matrices,
                            unsigned startIndex,
                            unsigned count, unsigned textureCount,
                            const Matrix2F& vertexMatrix)
    {        
        if ( !Rows ) return;

        InstanceCount = count;
        TextureCount  = textureCount;
       
        for (unsigned i = 0; i < InstanceCount; i++)
        {            
            const HMatrix& hm = matrices[startIndex + i];
            unsigned       k = (ept + (textureCount+1) * 2) * i;
            HAL::calculateTransform<MatrixType>(vertexMatrix, hm, pHAL->GetMatrices(), (float(*)[4])&Rows[k*4]);

            Profiler->GetCxform(hm.GetCxform()).GetAsFloat2x4((float(*)[4])&Rows[(k+ept)*4]);
        }
    }

    void    SetTextureData(const Matrix2F* matrices,
                           const unsigned *indices, unsigned count)
    {
        if ( !Rows ) return;
        for (unsigned i = 0; i < InstanceCount; i++)
        {
            unsigned k = (ept + (TextureCount+1) * 2) * i;

            if (count)
            {
                const Matrix2F& m0 = matrices[indices[0]];
                m0.GetAsFloat2x4((float(*)[4])&Rows[(k+ept+2)*4]);
                if (count > 1)
                {
                    const Matrix2F& m1 = matrices[indices[1]];
                    m1.GetAsFloat2x4((float(*)[4])&Rows[(k+ept+4)*4]);
                }
            }
        }
    }

    void    Apply()
    {
        if ( !Rows || !pConstantBuffer ) 
            return;
        D3D1xUnmapBuffer( pHAL->pDeviceContext, pConstantBuffer, 0);
        pHAL->pDeviceContext->VSSetConstantBuffers(0, 1, &pConstantBuffer);
    }

private:
    HAL*                        pHAL;
    const ProfileViews*         Profiler;
    unsigned                    InstanceCount;
    unsigned                    TextureCount;
    ID3D1x(Buffer)*             pConstantBuffer;
    D3D1x(MAPPED_BUFFER)        MappedBuffer;
    float*                      Rows;
};



void HAL::DrawProcessedComplexMeshes(ComplexMesh* complexMesh,
                                     const StrideArray<HMatrix>& matrices)
{    
    SF_AMP_SCOPE_RENDER_TIMER(__FUNCTION__, Amp_Profile_Level_High);
    PixMarker event(__FUNCTIONW__);

    typedef ComplexMesh::FillRecord   FillRecord;
    typedef PrimitiveBatch::BatchType BatchType;
 
    MeshCacheItem* pmesh = (MeshCacheItem*)complexMesh->GetCacheItem();
    if (!checkState(HS_InDisplay, __FUNCTION__) || !pmesh)
        return;

    // If in overdraw profile mode, and this primitive is part of a mask, draw it in color mode.
    static bool drawingMask = false;
    if ( !Profiler.ShouldDrawMask() && !drawingMask && (HALState & HS_DrawingMask) )
    {
        ProfileViewScopedOMChange change(drawingMask, pDeviceContext, BlendStates[GetBlendType(Blend_None, Write_None)], DepthStencilStates[StencilMode_Disabled]);
        DrawProcessedComplexMeshes(complexMesh, matrices);
    }

    const FillRecord* fillRecords   = complexMesh->GetFillRecords();
    unsigned    fillCount           = complexMesh->GetFillRecordCount();
    unsigned    instanceCount       = (unsigned)matrices.GetSize();
    unsigned    indexBufferOffset   = (unsigned)(pmesh->IBAllocOffset / sizeof(IndexType));
    unsigned    vertexSize          = 0;     // 0 => VertexBuffer wasn't applied yet.
    unsigned    vertexBaseIndex     = 0;
    unsigned    formatIndex;
    bool        has3D = instanceCount >= 0 ? matrices[0].Has3D() : false;
    BatchType   batchType;

    if (instanceCount <= 1)
    {
        batchType = PrimitiveBatch::DP_Single;
        formatIndex = 0;
    }
    else
    {
        batchType = PrimitiveBatch::DP_Instanced;
        formatIndex = 1;
    }

    pDeviceContext->IASetIndexBuffer(pmesh->pIndexBuffer->GetHWBuffer(), sizeof(IndexType) == 2 ? DXGI_FORMAT_R16_UINT : DXGI_FORMAT_R32_UINT, 0);

    for (unsigned fillIndex = 0; fillIndex < fillCount; fillIndex++)
    {
        const FillRecord& fr = fillRecords[fillIndex];

        Profiler.SetBatch((unsigned)complexMesh, fillIndex);

        // Apply fill.
        if (!SManager.ApplyPrimitiveFill(fr.pFill) ||
            !SManager.ApplyPrimitiveBatchFill(fr.pFill->GetType(), FillFlags, fr.pFormats[formatIndex], batchType))
            continue;

        // Modify stream source only when VertexSize changes.
        if (fr.pFormats[formatIndex]->Size != vertexSize)
        {
            vertexSize            = fr.pFormats[formatIndex]->Size;
            vertexBaseIndex       = 0;
            ID3D1x(Buffer)* pb    = pmesh->pVertexBuffer->GetHWBuffer();

            UINT byteOffset = (UINT)(fr.VertexByteOffset + pmesh->VBAllocOffset);
            pDeviceContext->IASetVertexBuffers(0, 1, &pb, &vertexSize, &byteOffset);
        }
        else
        {
            // Identical size vertex meshes should be allocated consecutively,
            // as this is needed for SetStreamSource optimization to work.
            SF_ASSERT(fr.VertexByteOffset == (fillRecords[fillIndex-1].VertexByteOffset +
                      vertexSize * fillRecords[fillIndex-1].VertexCount));
        }

        UByte textureCount = fr.pFill->GetTextureCount();

        // Single mesh.
        if (instanceCount == 1)
        {
            VSConstantsUpdateBuffer vsConstants(this,&Profiler);
            if ( has3D )
                vsConstants.SetInstanceData<Matrix4F>(matrices, 0, instanceCount, textureCount, complexMesh->GetVertexMatrix());
            else
                vsConstants.SetInstanceData<Matrix2F>(matrices, 0, instanceCount, textureCount, complexMesh->GetVertexMatrix());

            if (textureCount)
                vsConstants.SetTextureData(complexMesh->GetFillMatrixCache(), fr.FillMatrixIndex, textureCount);
            vsConstants.Apply();
         
            pDeviceContext->DrawIndexed(fr.IndexCount, fr.IndexOffset + indexBufferOffset, vertexBaseIndex);

            AccumulatedStats.Triangles += (fr.IndexCount / 3) * instanceCount;
            AccumulatedStats.Meshes += instanceCount;
            AccumulatedStats.Primitives++;
        }
        else
        {
            // If number of instances doesn't fit one buffer, so we must iterate in blocks,
            // updating instance count every time.
            unsigned instanceLeft = instanceCount;
            unsigned instanceIndex, drawCount;

            for (instanceIndex = 0; instanceLeft > 0;
                 instanceIndex += drawCount, instanceLeft-= drawCount)
            {
                drawCount = instanceLeft;
                if (drawCount > VSConstantsUpdateBuffer::MaxInstances)
                    drawCount = VSConstantsUpdateBuffer::MaxInstances;

                VSConstantsUpdateBuffer vsConstants(this,&Profiler);
                if ( has3D )
                    vsConstants.SetInstanceData<Matrix4F>(matrices, instanceIndex, drawCount, textureCount, complexMesh->GetVertexMatrix());
                else
                    vsConstants.SetInstanceData<Matrix2F>(matrices, instanceIndex, drawCount, textureCount, complexMesh->GetVertexMatrix());

                if (textureCount)
                    vsConstants.SetTextureData(complexMesh->GetFillMatrixCache(), fr.FillMatrixIndex, textureCount);
                vsConstants.Apply();
                
                pDeviceContext->DrawIndexedInstanced(fr.IndexCount, drawCount, fr.IndexOffset + indexBufferOffset, (INT)vertexBaseIndex, 0);
                
                AccumulatedStats.Triangles += (fr.IndexCount / 3) * drawCount;
                AccumulatedStats.Meshes += drawCount;
                AccumulatedStats.Primitives++;
            }
        }

        vertexBaseIndex += fr.VertexCount;

    } // for (fill record)
  
    pmesh->MoveToCacheListFront(MCL_ThisFrame);
}

template< class MatrixUpdateAdapter >
void HAL::applyMatrixConstants(const MatrixUpdateAdapter & input )
{
    const unsigned count           = input.GetCount();
    const unsigned ept             = input.GetElementsPerTransform();
    const unsigned matricesPerMesh = input.GetMatricesPerMesh();
    const float*   rows            = input.GetDestination();

    unsigned i;
    for (i = 0; i < count; i++)
    {
        const HMatrix &hm           = input.GetHMatrix(i);
        const Matrix2F vertexMatrix = input.GetVertexMatrix(i);

        calculateTransform<MatrixUpdateAdapter::MatrixType>(vertexMatrix, hm, Matrices, (float (*)[4])rows);
        rows += 4 * ept;
        Profiler.GetCxform(hm.GetCxform()).GetAsFloat2x4((float (*)[4])rows);
        rows += 4 * 2;

        if (matricesPerMesh > 1)
        {
            // TBD: Do texture coordinates need to be adjusted
            //      by the VertexMatrix? What else?
            // Old renderer just passed the values through...
            Matrix  tm0(vertexMatrix, hm.GetTextureMatrix(0));
            tm0.GetAsFloat2x4((float (*)[4])rows);
            rows += 4 * 2;

            if (matricesPerMesh > 2)
            {
                Matrix tm1(vertexMatrix, hm.GetTextureMatrix(1));
                tm1.GetAsFloat2x4((float (*)[4])rows);
                rows += 4 * 2;
            }
        }
    }
    input.Apply();
}

// Explicit instantiation for 2D matrices.
template<>
void HAL::calculateTransform<Matrix2F>(const Matrix & m, const HMatrix& hm, const MatrixState & mstate, float (* dest)[4])
{
    // Get as 2D, and just set the remainder to identity.
    Matrix4F mtx(Matrix2F(m, hm.GetMatrix2D(), mstate.UserView));
    mtx.GetAsFloat4x4(dest);
}

// Explicit instantiation for 4D matrices.
template<>
void HAL::calculateTransform<Matrix4F>(const Matrix & m, const HMatrix& hm, const MatrixState & mstate, float (* dest)[4])
{
    Matrix4F m4d(Matrix4F(mstate.GetUVP(), hm.GetMatrix3D()), m);
    m4d.GetAsFloat4x4(dest);
}

void HAL::applyRawMatrixConstants(const Matrix& m, const Cxform& cx)
{
    Matrix4F  mat(Matrix2F(m, Matrices.UserView));
    ID3D1x(Buffer)* pcb = getNextConstantBuffer();
    D3D1x(MAPPED_BUFFER) mappedResource;
    D3D1xMapBuffer( pDeviceContext, pcb, 0, D3D1x(MAP_WRITE_DISCARD), 0, &mappedResource);
    

    mat.GetAsFloat4x4((float (*)[4])mappedResource.pData);
    cx.GetAsFloat2x4(&(((float (*)[4])mappedResource.pData)[4]));

    D3D1xUnmapBuffer( pDeviceContext, pcb, 0 );
    pDeviceContext->VSSetConstantBuffers(0, 1, &pcb );
}

void HAL::applyRawMatrixConstants(const Matrix& m, const Cxform& cx, const Matrix& tm)
{
    Matrix4F  mat(Matrix2F(m, Matrices.UserView));
    ID3D1x(Buffer)* pcb = getNextConstantBuffer();
    D3D1x(MAPPED_BUFFER) mappedResource;
    D3D1xMapBuffer( pDeviceContext, pcb, 0, D3D1x(MAP_WRITE_DISCARD), 0, &mappedResource);
    
    mat.GetAsFloat4x4((float (*)[4])mappedResource.pData);
    cx.GetAsFloat2x4(&(((float (*)[4])mappedResource.pData)[4]));
    tm.GetAsFloat2x4(&(((float (*)[4])mappedResource.pData)[6]));

    D3D1xUnmapBuffer( pDeviceContext, pcb, 0 );
    pDeviceContext->VSSetConstantBuffers(0, 1, &pcb );
}

//--------------------------------------------------------------------
// *** Mask / Stencil support
//--------------------------------------------------------------------

// Mask support is implemented as a stack, enabling for a number of optimizations:
//
// 1. Large "Clipped" marks are clipped to a custom viewport, allowing to save on
//    fill-rate when rendering both the mask and its content. The mask area threshold
//    that triggers this behavior is determined externally.
//      - Clipped masks can be nested, but not batched. When erased, clipped masks
//        clear the clipped intersection area.
// 2. Small masks can be Batched, having multiple mask areas with multiple mask
//    content items inside.
//      - Small masks can contain clipped masks either regular or clipped masks.
// 3. Mask area dimensions are provided as HMatrix, which maps a unit rectangle {0,0,1,1}
//    to a mask bounding rectangle. This rectangle can be rotated (non-axis aligned),
//    allowing for more efficient fill.
// 4. PopMask stack optimization is implemented that does not erase nested masks; 
//    Stencil Reference value is changed instead. Erase of a mask only becomes
//    necessary if another PushMask_BeginSubmit is called, in which case previous
//    mask bounding rectangles are erased. This setup avoids often unnecessary erase 
//    operations when drawing content following a nested mask.
//      - To implement this MaskStack keeps a previous "stale" MaskPrimitive
//        located above the MaskStackTop.

void HAL::PushMask_BeginSubmit(MaskPrimitive* prim)
{
    MaskMarker.Begin(__FUNCTIONW__);

    if (!checkState(HS_InDisplay, __FUNCTION__))
        return;

    Profiler.SetDrawMode(1);

    if (!StencilAvailable && !DepthBufferAvailable)
    {
        if (!checkMaskBufferCaps())
            return;
    }

    // Immediately disable color target writes.
    unsigned writeOff = GetBlendType(Blend_Normal, Write_None);
    pDeviceContext->OMSetBlendState(BlendStates[writeOff], 0, 0xFFFFFFFF );

    bool viewportValid = (HALState & HS_ViewValid) != 0;
    DWORD maxStencilValue = (DWORD)MaskStackTop;

    // Erase previous mask if it existed above our current stack top.
    if ((MaskStackTop && (MaskStack.GetSize() > MaskStackTop) && viewportValid) && (StencilAvailable))
    {
        // Erase rectangles of these matrices; must be done even for clipped masks.
        // Any stencil of value greater then MaskStackTop should be set to it;
        // i.e. replace when (MaskStackTop < stencil value).
        pDeviceContext->OMSetDepthStencilState(DepthStencilStates[StencilMode_Available_ClearMasksAbove], maxStencilValue);
        MaskPrimitive* erasePrim = MaskStack[MaskStackTop].pPrimitive;
        drawMaskClearRectangles(erasePrim->GetMaskAreaMatrices(), erasePrim->GetMaskCount());
    }

    MaskStack.Resize(MaskStackTop+1);
    MaskStackEntry &e = MaskStack[MaskStackTop];
    e.pPrimitive       = prim;
    e.OldViewportValid = viewportValid;
    e.OldViewRect      = ViewRect; // TBD: Must assign
    MaskStackTop++;

    HALState |= HS_DrawingMask;

    if (prim->IsClipped() && viewportValid)
    {
        // Apply new viewport clipping.
        const Matrix2F &m = prim->GetMaskAreaMatrix(0).GetMatrix2D();
        // Clipped matrices are always in View coordinate space, to allow
        // matrix to be use for erase operation above. This means that we don't
        // have to do an EncloseTransform.
        SF_ASSERT((m.Shx() == 0.0f) && (m.Shy() == 0.0f));
        Rect<int>  boundClip((int)m.Tx(), (int)m.Ty(),
                             (int)(m.Tx() + m.Sx()), (int)(m.Ty() + m.Sy()));
        boundClip.Offset(VP.Left, VP.Top);
        
        if (!ViewRect.IntersectRect(&ViewRect, boundClip))
        {
            ViewRect.Clear();
            HALState &= ~HS_ViewValid;
            viewportValid = false;
        }
        updateViewport();
        
        // Clear full viewport area, which has been resized to our smaller bounds.
        if ((MaskStackTop == 1) && viewportValid)
        {
            // TODO: these actually clear the entire view.
            if (StencilAvailable)
                pDeviceContext->ClearDepthStencilView(pDepthStencilView, D3D1x(CLEAR_STENCIL), 1.0, 0);
            else if (DepthBufferAvailable)
                pDeviceContext->ClearDepthStencilView(pDepthStencilView, D3D1x(CLEAR_DEPTH), 1.0f, 0); // Z -> 1.0f
        }
    }

    else if ((MaskStackTop == 1) && viewportValid)
    {
        // Clear view rectangles.
        if (StencilAvailable)
        {
            // Unconditionally overwrite stencil rectangles with REF value of 0.
            pDeviceContext->OMSetDepthStencilState(DepthStencilStates[StencilMode_Available_ClearMasks], maxStencilValue);
            drawMaskClearRectangles(prim->GetMaskAreaMatrices(), prim->GetMaskCount());
        }
        else
        {
            // Depth clears bounds. Don't use drawMaskClearRectangles yet as it doesn't
            // set proper Z.
            UPInt maskCount = prim->GetMaskCount();
            for (UPInt i = 0; i< maskCount; i++)
            {
                const Matrix2F &m = prim->GetMaskAreaMatrix(i).GetMatrix2D();
                RectF           bounds(m.EncloseTransform(RectF(1.0f)));
                Rect<int>       boundClip((int)bounds.x1, (int)bounds.y1,
                                          (int)bounds.x2, (int)bounds.y2);
                boundClip.Offset(VP.Left, VP.Top);

                if (boundClip.IntersectRect(&boundClip, ViewRect))
                {
                    // TODO: this actually clears the entire surface.
                    // D3DRECT r = { boundClip.x1, boundClip.y1, boundClip.x2, boundClip.y2 };
                    pDeviceContext->ClearDepthStencilView(pDepthStencilView, D3D1x(CLEAR_DEPTH), 1.0f, 0); // Z -> 1.0f
                }
            }
        }
    }


    if (StencilAvailable)
    {
        pDeviceContext->OMSetDepthStencilState(DepthStencilStates[StencilMode_Available_WriteMask], (DWORD)(MaskStackTop-1));
    }
    else if (DepthBufferAvailable)
    {
        if (MaskStackTop == 1)
        {
            // Set the correct render states in order to not modify the color buffer
            // but write the default Z-value everywhere. According to the shader code: should be 0.
            pDeviceContext->OMSetDepthStencilState(DepthStencilStates[StencilMode_DepthOnly_WriteMask], (DWORD)(MaskStackTop-1));
        }
        else
        {
            // No color write. Incr/Decr not supported.
            pDeviceContext->OMSetDepthStencilState(DepthStencilStates[StencilMode_Unavailable], (DWORD)(MaskStackTop-1));
        }
    }
    ++AccumulatedStats.Masks;
}


void HAL::EndMaskSubmit()
{
    Profiler.SetDrawMode(0);

    if (!checkState(HS_InDisplay|HS_DrawingMask, __FUNCTION__))
        return;
    HALState &= ~HS_DrawingMask;    
    SF_ASSERT(MaskStackTop);

    // Set the blend mode back to the top of the stack, or normal if there was no stack.
    UPInt size = BlendModeStack.GetSize();
    applyBlendMode( size > 0 ? BlendModeStack[size-1] : Blend_Normal);

    if (StencilAvailable)
    {
        // We draw only where the (MaskStackTop <= stencil), i.e. where the latest mask was drawn.
        // However, we don't change the stencil buffer
        pDeviceContext->OMSetDepthStencilState(DepthStencilStates[StencilMode_Available_TestMask], (DWORD)MaskStackTop);
    }
    else if (DepthBufferAvailable)
    {
        // Disable the Z-write and write only where the mask had written
        pDeviceContext->OMSetDepthStencilState(DepthStencilStates[StencilMode_DepthOnly_TestMask], 0);
    }
    MaskMarker.End();
}


void HAL::PopMask()
{
    PixMarker event(__FUNCTIONW__);

    if (!checkState(HS_InDisplay, __FUNCTION__))
        return;

    if (!StencilAvailable && !DepthBufferAvailable)
        return;
    SF_ASSERT(MaskStackTop);
    MaskStackTop--;

    if (MaskStack[MaskStackTop].pPrimitive->IsClipped())
    {
        // Restore viewport
        ViewRect = MaskStack[MaskStackTop].OldViewRect;

        if (MaskStack[MaskStackTop].OldViewportValid)
            HALState |= HS_ViewValid;
        else
            HALState &= ~HS_ViewValid;
        updateViewport();
    }

    // Disable mask or decrement stencil reference value.
    if (StencilAvailable)
    {
        if (MaskStackTop == 0)
            pDeviceContext->OMSetDepthStencilState(DepthStencilStates[StencilMode_Disabled], 0);
        else
            pDeviceContext->OMSetDepthStencilState(DepthStencilStates[StencilMode_Available_TestMask], (UINT)MaskStackTop);
    }
    else if (DepthBufferAvailable)
    {
        pDeviceContext->OMSetDepthStencilState(DepthStencilStates[StencilMode_DepthOnly_TestMask], (UINT)MaskStackTop);
    }
    MaskMarker.End();
}


bool HAL::checkMaskBufferCaps()
{
    if (!StencilChecked)
    {
        StencilAvailable = 0;
        DepthBufferAvailable = 0;

        // Test for depth-stencil presence.
        Ptr<ID3D1x(DepthStencilView)> depthStencilTarget;
        Ptr<ID3D1x(RenderTargetView)> renderTarget; // Note: not strictly necessary, but causes PIX to crash if NULL.
        pDeviceContext->OMGetRenderTargets(1, &renderTarget.GetRawRef(), &depthStencilTarget.GetRawRef() );

        if (depthStencilTarget)
        {
            D3D1x(DEPTH_STENCIL_VIEW_DESC) desc;
            depthStencilTarget->GetDesc(&desc);
            switch(desc.Format)
            {
                case DXGI_FORMAT_D32_FLOAT_S8X24_UINT:
                case DXGI_FORMAT_D24_UNORM_S8_UINT:
                    StencilAvailable = 1;
                    DepthBufferAvailable = 1;
                    break;

                case DXGI_FORMAT_D16_UNORM:
                case DXGI_FORMAT_D32_FLOAT:
                    DepthBufferAvailable = 1;
                    break;
            }
        }
        StencilChecked = 1;
    }

    if (!StencilAvailable && !DepthBufferAvailable)
    {
#ifdef SF_BUILD_DEBUG
        static bool StencilWarned = 0;
        if (!StencilWarned)
        {
            SF_DEBUG_WARNING(1, "RendererHAL::PushMask_BeginSubmit used, but stencil is not available");
            StencilWarned = 1;
        }
#endif
        return false;
    }
    return true;
}


void HAL::drawMaskClearRectangles(const HMatrix* matrices, UPInt count)
{
    PixMarker event(__FUNCTIONW__);
    if (!SManager.ApplyClearMaskFill())
    {
        return;
    }

    // This operation is used to clear bounds for masks.
    // Potential issue: Since our bounds are exact, right/bottom pixels may not
    // be drawn due to HW fill rules.
    //  - This shouldn't matter if a mask is tessellated within bounds of those
    //    coordinates, since same rules are applied to those render shapes.
    //  - EdgeAA must be turned off for masks, as that would extrude the bounds.
    static const UINT stride = sizeof(VertexXY16iAlpha);
    static const UINT offset = 0;
    ID3D1x(Buffer) * pb = Cache.pMaskEraseBatchVertexBuffer.GetPtr();
    pDeviceContext->IASetVertexBuffers(0, 1, &pb, &stride, &offset );

    // Draw the object with cached mesh.
    unsigned drawRangeCount = 0;
    for (UPInt i = 0; i < count; i+= (UPInt)drawRangeCount)
    {
        drawRangeCount = Alg::Min<unsigned>((unsigned)count, MeshCache::MaxEraseBatchCount);
        StrideArray<const HMatrix> argMatrices(matrices + i, drawRangeCount, sizeof(HMatrix));
        applyMatrixConstants(MatrixUpdateAdapter_Matrices<Matrix2F>(this, argMatrices, 1, Matrix2F::Identity));

        pDeviceContext->Draw((UINT)drawRangeCount * 6, 0);

        AccumulatedStats.Meshes += drawRangeCount;
        AccumulatedStats.Triangles += drawRangeCount * 2;
        AccumulatedStats.Primitives++;
    }
}

//--------------------------------------------------------------------
// Background clear helper, expects viewport coordinates.
void HAL::clearSolidRectangle(const Rect<int>& r, Color color)
{
    color = Profiler.GetClearColor(color);
    if ( !Profiler.ShouldDrawMask() )
        pDeviceContext->OMSetBlendState(BlendStates[Blend_None], 0, 0xFFFFFFFF );

    PixMarker event(__FUNCTIONW__);

    // Note: cannot do HW clears in DX10/11, because they clear the entire buffer.
    if (!SManager.ApplySolidColorFill(color))
        return;

    Matrix2F m((float)r.Width(), 0.0f, (float)r.x1,
               0.0f, (float)r.Height(), (float)r.y1);

    applyRawMatrixConstants(m, Cxform::Identity);
    ID3D1x(Buffer)* pb = Cache.pMaskEraseBatchVertexBuffer.GetPtr();
    static const unsigned stride = sizeof(VertexXY16iAlpha);
    static const unsigned offset = 0;
    pDeviceContext->IASetVertexBuffers(0, 1, &pb, &stride, &offset );
    pDeviceContext->Draw( 6, 0 );

    if ( !Profiler.ShouldDrawMask() )
        applyBlendMode(BlendModeStack.GetSize()>=1 ? BlendModeStack.Back() : Blend_None);
}



//--------------------------------------------------------------------
// *** BlendMode Stack support
//--------------------------------------------------------------------

// Structure describing color combines applied for a given blend mode.
struct BlendModeDescAlpha
{
    D3D1x(BLEND_OP)  BlendOp;
    D3D1x(BLEND)     SrcArg, DestArg;
    D3D1x(BLEND)     SrcAlphaArg, DestAlphaArg;
};

bool HAL::createBlendStates()
{
    static BlendModeDescAlpha acmodes[Blend_Count] =
    {
        { D3D1x(BLEND_OP_ADD),         D3D1x(BLEND_SRC_ALPHA),  D3D1x(BLEND_INV_SRC_ALPHA), D3D1x(BLEND_ONE),        D3D1x(BLEND_INV_SRC_ALPHA) },  // None
        { D3D1x(BLEND_OP_ADD),         D3D1x(BLEND_SRC_ALPHA),  D3D1x(BLEND_INV_SRC_ALPHA), D3D1x(BLEND_ONE),        D3D1x(BLEND_INV_SRC_ALPHA) },  // Normal
        { D3D1x(BLEND_OP_ADD),         D3D1x(BLEND_SRC_ALPHA),  D3D1x(BLEND_INV_SRC_ALPHA), D3D1x(BLEND_ONE),        D3D1x(BLEND_INV_SRC_ALPHA) },  // Layer

        { D3D1x(BLEND_OP_ADD),         D3D1x(BLEND_DEST_COLOR), D3D1x(BLEND_ZERO),          D3D1x(BLEND_DEST_COLOR), D3D1x(BLEND_ZERO) },           // Multiply
        // (For multiply, should src be pre-multiplied by its inverse alpha?)

        { D3D1x(BLEND_OP_ADD),         D3D1x(BLEND_SRC_ALPHA),  D3D1x(BLEND_INV_SRC_ALPHA), D3D1x(BLEND_ONE),        D3D1x(BLEND_INV_SRC_ALPHA) },  // Screen *??

        { D3D1x(BLEND_OP_MAX),         D3D1x(BLEND_SRC_ALPHA),  D3D1x(BLEND_ONE),           D3D1x(BLEND_SRC_ALPHA),  D3D1x(BLEND_ONE) },            // Lighten
        { D3D1x(BLEND_OP_MIN),         D3D1x(BLEND_SRC_ALPHA),  D3D1x(BLEND_ONE),           D3D1x(BLEND_SRC_ALPHA),  D3D1x(BLEND_ONE) },            // Darken

        { D3D1x(BLEND_OP_ADD),         D3D1x(BLEND_SRC_ALPHA),  D3D1x(BLEND_INV_SRC_ALPHA), D3D1x(BLEND_ONE),        D3D1x(BLEND_INV_SRC_ALPHA) },  // Difference *??

        { D3D1x(BLEND_OP_ADD),         D3D1x(BLEND_SRC_ALPHA),  D3D1x(BLEND_ONE),           D3D1x(BLEND_ZERO),       D3D1x(BLEND_ONE) },            // Add
        { D3D1x(BLEND_OP_REV_SUBTRACT), D3D1x(BLEND_SRC_ALPHA),  D3D1x(BLEND_ONE),           D3D1x(BLEND_ZERO),       D3D1x(BLEND_ONE) },            // Subtract

        { D3D1x(BLEND_OP_ADD),         D3D1x(BLEND_SRC_ALPHA),  D3D1x(BLEND_INV_SRC_ALPHA), D3D1x(BLEND_ONE),        D3D1x(BLEND_INV_SRC_ALPHA) },  // Invert *??

        { D3D1x(BLEND_OP_ADD),         D3D1x(BLEND_ZERO),       D3D1x(BLEND_ZERO),          D3D1x(BLEND_ONE),        D3D1x(BLEND_ONE) },            // Alpha *??
        { D3D1x(BLEND_OP_ADD),         D3D1x(BLEND_ZERO),       D3D1x(BLEND_ZERO),          D3D1x(BLEND_ONE),        D3D1x(BLEND_ONE) },            // Erase *??
        { D3D1x(BLEND_OP_ADD),         D3D1x(BLEND_SRC_ALPHA),  D3D1x(BLEND_INV_SRC_ALPHA), D3D1x(BLEND_ONE),        D3D1x(BLEND_INV_SRC_ALPHA) },  // Overlay *??
        { D3D1x(BLEND_OP_ADD),         D3D1x(BLEND_SRC_ALPHA),  D3D1x(BLEND_INV_SRC_ALPHA), D3D1x(BLEND_ONE),        D3D1x(BLEND_INV_SRC_ALPHA) },  // Hardlight *??
    };

    memset(BlendStates, 0, sizeof BlendStates);
    for (unsigned i = 0; i < BlendTypeCount; ++i )
    {
        D3D1x(BLEND_DESC) desc;

        memset(&desc, 0, sizeof desc);
        unsigned mode = i;
        bool sourceAc = false;

#if (SF_D3D_VERSION == 11)
        D3D11_RENDER_TARGET_BLEND_DESC& rt0 = desc.RenderTarget[0];
        if ( i >= Blend_Count*2 )
        {
            // Anything above normal blends has write mask disabled.
            rt0.BlendEnable            = FALSE;
            rt0.RenderTargetWriteMask  = 0;
        }
        else 
        {
            rt0.BlendEnable           = TRUE;
            rt0.RenderTargetWriteMask = D3D1x(COLOR_WRITE_ENABLE_ALL);
            if ( i >= Blend_Count )
            {
                mode -= Blend_Count;
                sourceAc = true;
            }
        }
        mode %= Blend_Count;
#else
        D3D10_BLEND_DESC& rt0 = desc;
        if ( i >= Blend_Count*2 )
        {
            // Anything above normal blends has write mask disabled.
            rt0.BlendEnable[0]           = FALSE;
            rt0.RenderTargetWriteMask[0] = 0;
        }
        else
        {
            rt0.BlendEnable[0]           = TRUE;
            rt0.RenderTargetWriteMask[0] = D3D1x(COLOR_WRITE_ENABLE_ALL);
            if ( i >= Blend_Count )
            {
                mode -= Blend_Count;
                sourceAc = true;
            }
        }
        mode %= Blend_Count;
#endif

        // Set the most common values, then override them.
        rt0.BlendOp        = D3D1x(BLEND_OP_ADD);
        rt0.SrcBlend       = D3D1x(BLEND_SRC_ALPHA);
        rt0.DestBlend      = D3D1x(BLEND_INV_SRC_ALPHA);
        rt0.BlendOpAlpha   = D3D1x(BLEND_OP_ADD);
        rt0.SrcBlendAlpha  = D3D1x(BLEND_ONE);
        rt0.DestBlendAlpha = D3D1x(BLEND_INV_SRC_ALPHA);

        switch(mode)
        {
        case Blend_Multiply:
            rt0.SrcBlend    = D3D1x(BLEND_DEST_COLOR);
            rt0.DestBlend   = D3D1x(BLEND_ZERO);
            break;

        case Blend_Lighten: 
            rt0.BlendOp     = D3D1x(BLEND_OP_MAX);
            rt0.DestBlend   = D3D1x(BLEND_ONE);
            break;

        case Blend_Darken: 
            rt0.BlendOp     = D3D1x(BLEND_OP_MIN);
            rt0.DestBlend   = D3D1x(BLEND_ONE);
            break;

        case Blend_Add: 
            rt0.DestBlend   = D3D1x(BLEND_ONE);
            break;
        case Blend_Subtract:
            rt0.BlendOp     = D3D1x(BLEND_OP_REV_SUBTRACT);
            rt0.DestBlend   = D3D1x(BLEND_ONE);
            break;

        case Blend_Alpha: 
        case Blend_Erase: 
            rt0.SrcBlend    = D3D1x(BLEND_ZERO);
            rt0.DestBlend   = D3D1x(BLEND_ONE);
            break;

        case Blend_Overlay:
            rt0.SrcBlend        = D3D1x(BLEND_SRC_ALPHA);
            rt0.DestBlend       = D3D1x(BLEND_INV_SRC_ALPHA);
            break;

        case Blend_HardLight:
            rt0.SrcBlend    = D3D1x(BLEND_SRC_ALPHA);
            rt0.DestBlend   = D3D1x(BLEND_INV_SRC_ALPHA);
            break;
        }

        if ( sourceAc && rt0.SrcBlend == D3D1x(BLEND_SRC_ALPHA) )
            rt0.SrcBlend        = D3D1x(BLEND_ONE);

        if ( FAILED(pDevice->CreateBlendState(&desc, &BlendStates[i]) ))
            return false;
    }
    return true;
}

void HAL::destroyBlendStates()
{
    for (unsigned i = 0; i < BlendTypeCount; ++i )
    {
        if ( BlendStates[i] )
            BlendStates[i]->Release();
    }
    memset(BlendStates, 0, sizeof BlendStates);
}

bool HAL::createDepthStencilStates()
{
    memset(DepthStencilStates, 0, sizeof DepthStencilStates);
    for ( unsigned state = 0; state < StencilMode_Count; ++state)
    {
        D3D1x(DEPTH_STENCIL_DESC) desc;

        // Set (non-zero) default.
        memset(&desc, 0, sizeof desc);
        desc.DepthFunc                    = D3D1x(COMPARISON_ALWAYS);
        desc.StencilReadMask              = 0xFF;
        desc.StencilWriteMask             = 0xFF;
        desc.FrontFace.StencilFunc        = D3D1x(COMPARISON_ALWAYS);
        desc.FrontFace.StencilDepthFailOp = D3D1x(STENCIL_OP_KEEP);
        desc.FrontFace.StencilFailOp      = D3D1x(STENCIL_OP_KEEP);
        desc.FrontFace.StencilPassOp      = D3D1x(STENCIL_OP_KEEP);

        switch(state)
        {
            case StencilMode_Disabled:
            {
                desc.StencilEnable = FALSE;
                break;
            }

            case StencilMode_Available_ClearMasksAbove:
            {
                desc.StencilEnable                = TRUE;
                desc.FrontFace.StencilFunc        = D3D1x(COMPARISON_LESS_EQUAL);
                desc.FrontFace.StencilPassOp      = D3D1x(STENCIL_OP_REPLACE);
                desc.FrontFace.StencilFailOp      = D3D1x(STENCIL_OP_KEEP);
                desc.FrontFace.StencilDepthFailOp = D3D1x(STENCIL_OP_KEEP);
                break;
            }

            case StencilMode_Available_ClearMasks:
            {
                desc.StencilEnable = TRUE;
                desc.FrontFace.StencilFunc        = D3D1x(COMPARISON_ALWAYS);
                desc.FrontFace.StencilPassOp      = D3D1x(STENCIL_OP_REPLACE);
                desc.FrontFace.StencilDepthFailOp = D3D1x(STENCIL_OP_REPLACE);
                break;
            }

            case StencilMode_Available_WriteMask:
            {
                desc.StencilEnable = TRUE;
                desc.FrontFace.StencilFunc        = D3D1x(COMPARISON_EQUAL);
                desc.FrontFace.StencilPassOp      = D3D1x(STENCIL_OP_INCR);
                desc.FrontFace.StencilDepthFailOp = D3D1x(STENCIL_OP_INCR);
                break;
            }

            case StencilMode_DepthOnly_WriteMask:
            {
                //pDevice->SetRenderState(D3DRS_COLORWRITEENABLE, D3DCOLORWRITEENABLE_ALPHA);
                desc.DepthEnable        = TRUE;
                desc.DepthFunc          = D3D1x(COMPARISON_ALWAYS);
                desc.DepthWriteMask     = D3D1x(DEPTH_WRITE_MASK_ALL);
                break;
            }

            case StencilMode_Available_TestMask:
            {
                desc.StencilEnable           = TRUE;
                desc.FrontFace.StencilFunc   = D3D1x(COMPARISON_LESS_EQUAL);
                desc.FrontFace.StencilPassOp = D3D1x(STENCIL_OP_KEEP);
                break;
            }

            case StencilMode_DepthOnly_TestMask:
            {
                desc.DepthWriteMask         = D3D1x(DEPTH_WRITE_MASK_ALL);
                desc.DepthEnable            = TRUE;
                desc.DepthFunc              = D3D1x(COMPARISON_EQUAL);
                break;
            }

            case StencilMode_Unavailable:
            {
                desc.DepthWriteMask     = D3D1x(DEPTH_WRITE_MASK_ZERO);
                desc.DepthEnable        = FALSE;
                break;
            }
        }

        // Make backface identical to front face.
        memcpy(&desc.BackFace, &desc.FrontFace, sizeof D3D1x(DEPTH_STENCILOP_DESC));

        if (FAILED(pDevice->CreateDepthStencilState(&desc, &DepthStencilStates[state])))
            return false;
    }
    return true;
}

void HAL::destroyDepthStencilStates()
{
    for ( unsigned state = 0; state < StencilMode_Count; ++state)
    {
        if ( DepthStencilStates[state] )
            DepthStencilStates[state]->Release();
    }
    memset(DepthStencilStates, 0, sizeof DepthStencilStates);
}

bool HAL::createRasterStates()
{
    memset(RasterStates, 0, sizeof RasterStates);
    for ( unsigned state = 0; state < RasterMode_Count; ++state )
    {
        D3D1x(RASTERIZER_DESC) rsdesc;
        memset(&rsdesc, 0, sizeof rsdesc);
        rsdesc.CullMode = D3D1x(CULL_NONE);
        switch(state)
        {
            case RasterMode_Wireframe: rsdesc.FillMode = D3D1x(FILL_WIREFRAME); break;
            default:                   rsdesc.FillMode = D3D1x(FILL_SOLID); break;
        }              
        if ( FAILED(pDevice->CreateRasterizerState( &rsdesc, &RasterStates[state] )) )
            return false;
    }
    return true;
}

void HAL::destroyRasterStates()
{
    for ( unsigned state = 0; state < RasterMode_Count; ++state)
    {
        if ( RasterStates[state] )
            RasterStates[state]->Release();
    }
    memset(RasterStates, 0, sizeof RasterStates);
}

bool HAL::createConstantBuffers()
{
    memset(ConstantBuffers, 0, sizeof ConstantBuffers);
    D3D1x(BUFFER_DESC) desc;
    memset(&desc, 0, sizeof desc);
    for ( unsigned b = 0; b < ConstantBufferCount; ++b )
    {
        desc.ByteWidth      = SF_RENDER_D3D1x_INSTANCE_DATAROWS * 4 * sizeof(float);
        desc.Usage          = D3D1x(USAGE_DYNAMIC);
        desc.BindFlags      = D3D1x(BIND_CONSTANT_BUFFER);
        desc.CPUAccessFlags = D3D1x(CPU_ACCESS_WRITE);
        if ( FAILED( pDevice->CreateBuffer( &desc, 0, &ConstantBuffers[b] ) ))
            return false;
    }
    return true;
}

void HAL::destroyConstantBuffers()
{
    for ( unsigned b = 0; b < ConstantBufferCount; ++b )
    {
        if ( ConstantBuffers[b] )
            ConstantBuffers[b]->Release();
    }
    memset(ConstantBuffers, 0, sizeof ConstantBuffers);
}

ID3D1x(Buffer)* HAL::getNextConstantBuffer()
{
    CurrentConstantBuffer++; 
    CurrentConstantBuffer %= ConstantBufferCount; 
    return ConstantBuffers[CurrentConstantBuffer];
}

void HAL::applyBlendMode(BlendMode mode, bool sourceAc, bool forceAc )
{    
    SF_UNUSED(forceAc);
    if (!pDeviceContext)
        return;

    // For debug build
    SF_ASSERT(mode < Blend_Count);
    // For release
    if (mode >= Blend_Count)
        mode = Blend_None;

    mode = Profiler.GetBlendMode(mode);

    // Multiply requires different fill mode, save it in the HAL's fill flags.
    if ( mode == Blend_Multiply || mode == Blend_Darken )
        FillFlags |= FF_Multiply;
    else
        FillFlags &= ~FF_Multiply;

    unsigned blendType = GetBlendType(mode, Write_All, sourceAc);
    pDeviceContext->OMSetBlendState(BlendStates[blendType], 0, 0xFFFFFFFF );
}

RenderTarget* HAL::CreateRenderTarget(Render::Texture* texture, bool needsStencil)
{
    D3D1x::Texture* pt = (D3D1x::Texture*)texture;

    // Cannot render to textures which have multiple HW representations.
    if ( !pt || pt->TextureCount != 1 )
        return 0;
    RenderTarget* prt = pRenderBufferManager->CreateRenderTarget(
        texture->GetSize(), RBuffer_Texture, texture->GetFormat(), texture);   
    if ( !prt )
        return 0;

    Ptr<ID3D1x(RenderTargetView)> prtView;
    ID3D1x(DepthStencilView)* pdsView = 0;
    if ( !prt || FAILED(pDevice->CreateRenderTargetView(pt->pTextures[0].pTexture, 0, &prtView.GetRawRef() )) )
        return 0;
    Ptr<DepthStencilBuffer> pdsb =0;
    if ( needsStencil )
    {
        pdsb = *pRenderBufferManager->CreateDepthStencilBuffer(texture->GetSize());
        if ( pdsb )
        {
            DepthStencilSurface* surf = (D3D1x::DepthStencilSurface*)pdsb->GetSurface();
            if ( surf )
                pdsView = surf->pDepthStencilSurfaceView;
        }
    }
    HALData::UpdateData(prt, prtView, pdsb, pdsView);
    return prt;
}

RenderTarget* HAL::CreateTempRenderTarget(const ImageSize& size, bool needsStencil)
{
    RenderTarget* prt = pRenderBufferManager->CreateTempRenderTarget(size);
    if ( !prt )
        return 0;

    HALData* phd = (HALData*)prt->GetHALData();
    if ( phd && (!needsStencil || phd->pDepthStencilBuffer))
        return prt;

    D3D1x::Texture* pt = (D3D1x::Texture*)prt->GetTexture();

    // Cannot render to textures which have multiple HW representations.
    SF_ASSERT(pt->TextureCount == 1); 
    Ptr<ID3D1x(RenderTargetView)> prtView;
    ID3D1x(DepthStencilView)* pdsView = 0;
    if ( FAILED(pDevice->CreateRenderTargetView(pt->pTextures[0].pTexture, 0, &prtView.GetRawRef() )) )
        return 0;

    Ptr<DepthStencilBuffer> pdsb = 0;
    if ( needsStencil )
    {   
        pdsb = *pRenderBufferManager->CreateDepthStencilBuffer(pt->GetSize());
        if ( pdsb )
        {
            DepthStencilSurface* surf = (D3D1x::DepthStencilSurface*)pdsb->GetSurface();
            if ( surf )
                pdsView = surf->pDepthStencilSurfaceView;
        }
    }

    HALData::UpdateData(prt, prtView, pdsb, pdsView);
    return prt;
}

bool HAL::SetRenderTarget(RenderTarget* ptarget, bool setState)
{
    // Cannot set the bottom level render target if already in display.
    if ( HALState & HS_InDisplay )
        return false;

    // When changing the render target while in a scene, we must flush all drawing.
    if ( HALState & HS_InScene)
        Flush();

    RenderTargetEntry entry;
    HALData* prtdata = (D3D1x::HALData*)ptarget->GetHALData();
    ID3D1x(RenderTargetView)* prtView = (ID3D1x(RenderTargetView)*)prtdata->pRenderSurface;
    ID3D1x(DepthStencilView)* pdsView = (ID3D1x(DepthStencilView)*)prtdata->pDSSurface;

    if ( setState )
    {
        pDeviceContext->OMSetRenderTargets(1, &prtView, pdsView);
        ++AccumulatedStats.RTChanges;
    }

    entry.pRenderTarget = ptarget;

    // Replace the stack entry at the bottom, or if the stack is empty, add one.
    if ( RenderTargetStack.GetSize() > 0 )
        RenderTargetStack[0] = entry;
    else
        RenderTargetStack.PushBack(entry);
    return true;
}

void HAL::PushRenderTarget(const RectF& frameRect, RenderTarget* prt)
{
    RenderTargetMarker.Begin(__FUNCTIONW__);

    HALState |= HS_InRenderTarget;
    RenderTargetEntry entry = {prt, Matrices, ViewRect, VP};
    Matrices.SetUserMatrix(Matrix2F::Identity);

    // Setup the render target/depth stencil on the device.
    if ( !prt )
    {
        SF_DEBUG_WARNING(1, __FUNCTION__ " - invalid render target.");
        RenderTargetStack.PushBack(entry);
        return;
    }
    HALData* phd = (D3D1x::HALData*)prt->GetHALData();

    ID3D1x(DepthStencilView)* pdsView = (ID3D1x(DepthStencilView)*)phd->pDSSurface;
    pDeviceContext->OMSetRenderTargets(1, (ID3D1x(RenderTargetView)**)&phd->pRenderSurface, pdsView);
    StencilChecked = false;
    ++AccumulatedStats.RTChanges;

    float clear[4];
    memset(clear, 0, sizeof clear);
    pDeviceContext->ClearRenderTargetView((ID3D1x(RenderTargetView)*)phd->pRenderSurface, clear);

    // Setup viewport.
    Rect<int> viewRect = prt->GetRect(); // On the render texture, might not be the entire surface.
    const ImageSize& bs = prt->GetBufferSize();
    VP = Viewport(bs.Width, bs.Height, viewRect.x1, viewRect.y1, viewRect.Width(), viewRect.Height());    
    ViewRect.x1 = (int)frameRect.x1;
    ViewRect.y1 = (int)frameRect.y1;
    ViewRect.x2 = (int)frameRect.x2;
    ViewRect.y2 = (int)frameRect.y2;

    // Must offset the 'original' viewrect, otherwise the 3D compensation matrix will be offset.
    Matrices.ViewRectOriginal.Offset(-entry.OldViewport.Left, -entry.OldViewport.Top);
    Matrices.UVPOChanged = true;
    HALState |= HS_ViewValid;
    updateViewport();

    RenderTargetStack.PushBack(entry);
}

void HAL::PopRenderTarget()
{
    RenderTargetEntry& entry = RenderTargetStack.Back();
    RenderTarget* prt = entry.pRenderTarget;
    if ( prt->GetType() == RBuffer_Temporary )
    {
        // Strip off the depth stencil surface/buffer from temporary targets.
        D3D1x::HALData* plasthd = (D3D1x::HALData*)prt->GetHALData();
        if ( plasthd->pDSSurface )
        {
            plasthd->pDSSurface->Release();
            plasthd->pDSSurface = 0;
        }
        plasthd->pDepthStencilBuffer = 0;
    }
    Matrices = entry.OldMatrixState;
    ViewRect = entry.OldViewRect;
    VP = entry.OldViewport;

    // Must reverse the offset of the 'original' viewrect.
    Matrices.ViewRectOriginal.Offset(entry.OldViewport.Left, entry.OldViewport.Top);
    Matrices.UVPOChanged = true;

    RenderTargetStack.PopBack();
    ID3D1x(DepthStencilView)* pds = 0;
    HALData* phd = 0;
    if ( RenderTargetStack.GetSize() > 0 )
    {
        RenderTargetEntry& back = RenderTargetStack.Back();
        phd = (D3D1x::HALData*)back.pRenderTarget->GetHALData();
        pds = (ID3D1x(DepthStencilView)*)phd->pDSSurface;
    }

    if ( RenderTargetStack.GetSize() == 1 )
        HALState &= ~HS_InRenderTarget;

    // Restore the old render target on the device.
    pDeviceContext->OMSetRenderTargets(1, (ID3D1x(RenderTargetView)**)&phd->pRenderSurface, pds );
    ++AccumulatedStats.RTChanges;

    // Reset the viewport to the last render target on the stack.
    HALState |= HS_ViewValid;
    updateViewport();

    RenderTargetMarker.End();
}

bool HAL::createDefaultRenderBuffer()
{
    ImageSize rtSize;

    if ( GetDefaultRenderTarget() )
    {
        RenderTarget* prt = GetDefaultRenderTarget();
        rtSize = prt->GetSize();
    }
    else
    {
        Ptr<ID3D1x(RenderTargetView)> prtView;
        Ptr<ID3D1x(DepthStencilView)> pdsView;
        Ptr<ID3D1x(Texture2D)> prenderTarget;
        Ptr<ID3D1x(Texture2D)> pdepthStencilTarget;
        D3D1x(TEXTURE2D_DESC) rtDesc;
        D3D1x(TEXTURE2D_DESC) dsDesc;


        pDeviceContext->OMGetRenderTargets(1, &prtView.GetRawRef(), &pdsView.GetRawRef());
        prtView->GetResource((ID3D1x(Resource)**)(&prenderTarget.GetRawRef()));
        prenderTarget->GetDesc(&rtDesc);

        rtSize = ImageSize(rtDesc.Width, rtDesc.Height);
        Ptr<RenderTarget> ptarget = *SF_HEAP_AUTO_NEW(this) RenderTarget(0, RBuffer_Default, rtSize );
        Ptr<DepthStencilBuffer> pdsb = 0;
        if (pdsView)
        {
            prtView->GetResource((ID3D1x(Resource)**)(&pdepthStencilTarget.GetRawRef()));
            pdepthStencilTarget->GetDesc(&dsDesc);
            ImageSize dsSize(dsDesc.Width, dsDesc.Height);
            pdsb = *SF_HEAP_AUTO_NEW(this) DepthStencilBuffer(0, dsSize);
        }
        HALData::UpdateData(ptarget, prtView, pdsb, pdsView);

        if ( !SetRenderTarget(ptarget))
            return false;
    }

    return pRenderBufferManager->Initialize(pTextureManager, Image_R8G8B8A8, rtSize);
}

void HAL::PushFilters(FilterPrimitive* prim)
{
    if (!checkState(HS_InDisplay, __FUNCTION__))
        return;

    FilterStackEntry e = {prim, 0};

    // Queue the profiler off of whether masks should be draw or not.
    if ( !Profiler.ShouldDrawMask() )
    {
        Profiler.SetDrawMode(2);

        static const unsigned stride = sizeof(VertexXY16iAlpha);
        static const unsigned offset = 0;
        ID3D1x(Buffer)* pvb = Cache.pMaskEraseBatchVertexBuffer.GetPtr();
        pDeviceContext->IASetVertexBuffers(0, 1, &pvb, &stride, &offset);
        applyRawMatrixConstants(prim->GetFilterAreaMatrix().GetMatrix2D(), Cxform::Identity);
        SManager.ApplySolidColorFill(0xFFFFFFFF);
        pDeviceContext->Draw(6, 0);
        FilterStack.PushBack(e);
        return;
    }

    if ( (HALState & HS_CachedFilter) )
    {
        FilterStack.PushBack(e);
        return;
    }

    // Disable masking from previous target, if this filter primitive doesn't have any masking.
    if ( MaskStackTop != 0 && !prim->GetMaskPresent() )
    {
        if ( StencilAvailable )
            pDeviceContext->OMSetDepthStencilState(DepthStencilStates[StencilMode_Available_TestMask], (UINT)MaskStackTop);
        else if ( DepthBufferAvailable )
            pDeviceContext->OMSetDepthStencilState(DepthStencilStates[StencilMode_DepthOnly_TestMask], (UINT)MaskStackTop);
    }

    FilterMarker.Begin(__FUNCTIONW__);
    HALState |= HS_DrawingFilter;

    if ( prim->GetCacheState() ==  FilterPrimitive::Cache_Uncached )
    {
        // Draw the filter from scratch.
        const Matrix2F& m = e.pPrimitive->GetFilterAreaMatrix().GetMatrix2D();
        e.pRenderTarget = *CreateTempRenderTarget(ImageSize((UInt32)m.Sx(), (UInt32)m.Sy()), prim->GetMaskPresent());
        RectF frameRect(m.Tx(), m.Ty(), m.Tx() + m.Sx(), m.Ty() + m.Sy());
        PushRenderTarget(frameRect, e.pRenderTarget);
        applyBlendMode(BlendModeStack.GetSize()>=1 ? BlendModeStack.Back() : Blend_Normal, false);

        // If this primitive has masking, then clear the entire area to the current mask level, because 
        // the depth stencil target may be different, and thus does not contain the previously written values.
        if ( prim->GetMaskPresent())
        {
            HALData* phd = (HALData*)e.pRenderTarget->GetHALData();
            if (StencilAvailable)
                pDeviceContext->ClearDepthStencilView((ID3D1x(DepthStencilView)*)phd->pDSSurface, D3D1x(CLEAR_STENCIL), 0.0f, (UINT8)MaskStackTop);
            else if (DepthBufferAvailable)
                pDeviceContext->ClearDepthStencilView((ID3D1x(DepthStencilView)*)phd->pDSSurface, D3D1x(CLEAR_DEPTH), 1.0f, (UINT8)MaskStackTop);
        }
    }
    else
    {
        // Drawing a cached filter, ignore all draw calls until the corresponding PopFilters.
        // Keep track of the level at which we need to draw the cached filter, by adding entries to the stack.
        HALState |= HS_CachedFilter;
        CachedFilterIndex = (int)FilterStack.GetSize();
        GetRQProcessor().SetQueueEmitFilter(RenderQueueProcessor::QPF_Filters);
    }
    FilterStack.PushBack(e);
}

void HAL::PopFilters()
{
    ShaderData.BeginScene(); // Uncache FS/VS/VD.
    SManager.BeginScene(); 

    Render::HAL::PopFilters();

    ShaderData.BeginScene(); // Uncache FS/VS/VD.
    SManager.BeginScene(); 

    FilterMarker.End();
}

void HAL::drawUncachedFilter(const FilterStackEntry& e)
{
    const FilterSet* filters = e.pPrimitive->GetFilters();
    unsigned filterCount = filters->GetFilterCount();
    const Filter* filter = 0;
    unsigned pass = 0, passes = 0;

    // Invalid primitive or rendertarget.
    if ( !e.pPrimitive || !e.pRenderTarget )
        return;

    ID3D1x(ShaderResourceView)* clearViews[2];
    memset(clearViews, 0, sizeof clearViews);

    // Bind the render target.
    SF_ASSERT(RenderTargetStack.Back().pRenderTarget == e.pRenderTarget);
    const int MaxTemporaryTextures = 3;
    Ptr<RenderTarget> temporaryTextures[MaxTemporaryTextures];
    memset(temporaryTextures, 0, sizeof temporaryTextures);

    // Fill our the source target.
    ImageSize size = e.pRenderTarget->GetSize();
    temporaryTextures[0] = e.pRenderTarget;

    static const unsigned stride = sizeof(VertexXY16f);
    static const unsigned offset = 0;
    ID3D1x(Buffer)* pvb = Cache.pSquareVertexBuffer.GetPtr();
    pDeviceContext->IASetVertexBuffers(0, 1, &pvb, &stride, &offset);

    const VertexFormat* pvf[3];
    FSManager.MapVertexFormat(PrimFill_Mask, &VertexXY16f::Format, &pvf[0], &pvf[1], &pvf[2] );

    // Overlay mode isn't actually supported, it contains the blend mode for filter sub-targets.
    applyBlendMode(Blend_Overlay, true);

    // Render filter(s).
    unsigned shaders[FilterShaderManager::MaximumFilterPasses];
    for ( unsigned i = 0; i < filterCount; ++i )
    {
        filter = filters->GetFilter(i);
        passes = FSManager.GetFilterPasses(filter, FillFlags, shaders);

        // All shadows (except those hiding the object) need the original texture.
        bool requireSource = false;
        if ( filter->GetFilterType() >= Filter_Shadow &&
             filter->GetFilterType() <= Filter_Blur_End &&
             !(((BlurFilterImpl*)filter)->GetParams().Mode & BlurFilterParams::Mode_HideObject) )
        {
            temporaryTextures[Target_Original] = temporaryTextures[Target_Source];
            requireSource = true;
        }

        // Now actually render the filter.
        for (pass = 0; pass < passes; ++pass)
        {
            // Render the final pass directly to the target surface.
            if (pass == passes-1 && i == filterCount-1)
                break;

            // Create a destination texture if required.
            if ( !temporaryTextures[1] )
            {
                temporaryTextures[1] = *CreateTempRenderTarget(size, false);
            }

            ID3D1x(DepthStencilView)* pds = 0;
            ID3D1x(RenderTargetView)* prtView = (ID3D1x(RenderTargetView)*)((D3D1x::HALData*)temporaryTextures[1]->GetHALData())->pRenderSurface;
            pDeviceContext->OMSetRenderTargets(1, &prtView, pds );
            ++AccumulatedStats.RTChanges;

            float clear[4];
            memset(clear, 0, sizeof clear);
            pDeviceContext->ClearRenderTargetView(prtView, clear);
            
            // Scale to the size of the destination.
            RenderTarget* prt = temporaryTextures[1];
            const Rect<int>& viewRect = prt->GetRect(); // On the render texture, might not be the entire surface.
            const ImageSize& bs = prt->GetBufferSize();
            VP = Viewport(bs.Width, bs.Height, viewRect.x1, viewRect.y1, viewRect.Width(), viewRect.Height());    
            ViewRect = Rect<int>(viewRect.x1, viewRect.y1, viewRect.x2, viewRect.y2);
            HALState |= HS_ViewValid;
            updateViewport();

            Matrix2F mvp = Matrix2F::Scaling(2,-2) * Matrix2F::Translation(-0.5f, -0.5f);                          
            FSManager.SetFilterFill(mvp, Cxform::Identity, filter, temporaryTextures, shaders, pass, passes, pvf[0], &ShaderData);
            pDeviceContext->Draw(6, 0);

            // Must immediately clear the textures from the input bindings, as D3D1x will detect double-bindings
            // when the rendertarget is set, not when the draw call is made as in D3D1x.
            pDeviceContext->PSSetShaderResources( 0, 2, clearViews );

            // If we require the original source, create a new target for the source.
            if ( requireSource && pass == 0)
                temporaryTextures[0] = *CreateTempRenderTarget(size, false);

            // Setup for the next pass.
            Alg::Swap(temporaryTextures[0], temporaryTextures[1]);
        }

        AccumulatedStats.Primitives += passes;
        AccumulatedStats.Meshes     += passes;
    }

    // Cache the 2nd last step so it might be available as a cached filter next time.
    RenderTarget* cacheResults[2] = { temporaryTextures[0], temporaryTextures[2] };
    e.pPrimitive->SetCacheResults(FilterPrimitive::Cache_PreTarget, cacheResults, 2);
    ((D3D1x::HALData*)cacheResults[0]->GetHALData())->CacheID = reinterpret_cast<UPInt>(e.pPrimitive.GetPtr());
    if ( cacheResults[1] )
        ((D3D1x::HALData*)cacheResults[1]->GetHALData())->CacheID = reinterpret_cast<UPInt>(e.pPrimitive.GetPtr());

    // Pop the temporary target, begin rendering to the previous surface.
    PopRenderTarget();

    // Re-[en/dis]able masking from previous target, if available.
    if ( MaskStackTop != 0 )
    {
        if ( StencilAvailable )
            pDeviceContext->OMSetDepthStencilState(DepthStencilStates[StencilMode_Available_TestMask], (UINT)MaskStackTop);
        else if ( DepthBufferAvailable )
            pDeviceContext->OMSetDepthStencilState(DepthStencilStates[StencilMode_DepthOnly_TestMask], (UINT)MaskStackTop);
    }

    // Now actually draw the filtered sub-scene to the target below.
    const Matrix2F& mvp = Matrices.UserView * e.pPrimitive->GetFilterAreaMatrix().GetMatrix2D();
    const Cxform&   cx  = e.pPrimitive->GetFilterAreaMatrix().GetCxform();
    FSManager.SetFilterFill(mvp, cx, filter, temporaryTextures, shaders, pass, passes, pvf[0], &ShaderData);
    applyBlendMode(BlendModeStack.GetSize()>=1 ? BlendModeStack.Back() : Blend_Normal, true);
    pDeviceContext->Draw(6, 0);
    applyBlendMode(BlendModeStack.GetSize()>=1 ? BlendModeStack.Back() : Blend_Normal, false);

    // Must immediately clear the textures from the input bindings, as D3D1x will detect double-bindings
    // when the rendertarget is set, not when the draw call is made.
    pDeviceContext->PSSetShaderResources( 0, 2, clearViews );

    // Cleanup.
    for ( unsigned i = 0; i < MaxTemporaryTextures; ++i )
    {
        if (temporaryTextures[i])
            temporaryTextures[i]->SetInUse(false);
    }
    AccumulatedStats.Filters += filters->GetFilterCount();
}

void HAL::drawCachedFilter(FilterPrimitive* primitive)
{
    static const unsigned stride = sizeof(VertexXY16f);
    static const unsigned offset = 0;
    ID3D1x(Buffer)* pvb = Cache.pSquareVertexBuffer.GetPtr();
    pDeviceContext->IASetVertexBuffers(0, 1, &pvb, &stride, &offset);

    ID3D1x(ShaderResourceView)* clearViews[2];
    memset(clearViews, 0, sizeof clearViews);

    const int MaxTemporaryTextures = 3;
    switch(primitive->GetCacheState())
    {
        // We have one-step from final target. Render it to a final target now.
        case FilterPrimitive::Cache_PreTarget:
        {
            const FilterSet* filters = primitive->GetFilters();
            UPInt filterIndex = filters->GetFilterCount()-1;
            const Filter* filter = filters->GetFilter(filterIndex);
            unsigned shaders[FilterShaderManager::MaximumFilterPasses];
            unsigned passes = FSManager.GetFilterPasses(filter, FillFlags, shaders);
            
            // Fill out the temporary textures from the cached results.
            Ptr<RenderTarget> temporaryTextures[MaxTemporaryTextures];
            memset(temporaryTextures, 0, sizeof temporaryTextures);
            RenderTarget* results[2];
            primitive->GetCacheResults(results, 2);
            temporaryTextures[0] = results[0];
            ImageSize size = temporaryTextures[0]->GetSize();
            temporaryTextures[1] = *CreateTempRenderTarget(size, false);
            temporaryTextures[2] = results[1];
            PushRenderTarget(RectF((float)size.Width,(float)size.Height), temporaryTextures[1]);

            // Render to the target.
            const VertexFormat* pvf[3];
            SManager.MapVertexFormat(PrimFill_Texture, &VertexXY16f::Format, &pvf[0], &pvf[1], &pvf[2] );
            Matrix2F mvp = Matrix2F::Scaling(2,-2) * Matrix2F::Translation(-0.5f, -0.5f);
            const Cxform & cx = primitive->GetFilterAreaMatrix().GetCxform();
            FSManager.SetFilterFill(mvp, cx, filter, temporaryTextures, shaders, passes-1, passes, pvf[0], &ShaderData);
            applyBlendMode(BlendModeStack.GetSize()>=1 ? BlendModeStack.Back() : Blend_Normal, true, true);
            pDeviceContext->Draw(6, 0);
            PopRenderTarget();
            pDeviceContext->PSSetShaderResources(0, 2, clearViews);

            // Set this as the final cache result, and then render it.
            RenderTarget* prt = temporaryTextures[1];
            primitive->SetCacheResults(FilterPrimitive::Cache_Target, &prt, 1);
            ((D3D1x::HALData*)prt->GetHALData())->CacheID = reinterpret_cast<UPInt>(primitive);
            drawCachedFilter(primitive);

            // Cleanup.
            for ( unsigned i = 0; i < MaxTemporaryTextures; ++i )
            {
                if (temporaryTextures[i])
                    temporaryTextures[i]->SetInUse(false);
            }
            break;
        }

        // We have a final filtered texture. Just apply it to a screen quad.
        case FilterPrimitive::Cache_Target:
        {
            const VertexFormat* pvf[3];
            SManager.MapVertexFormat(PrimFill_Texture, &VertexXY16f::Format, &pvf[0], &pvf[1], &pvf[2] );
            SManager.PrimitivePSType = PS_Texture;
            if ( !SManager.ApplyPrimitiveBatchFill(PrimFill_Texture, (UInt16)(FillFlags & ~FF_Cxform), pvf[0], PrimitiveBatch::DP_Single) )
                return;

            RenderTarget* results;
            primitive->GetCacheResults(&results, 1);
            Texture* ptexture = (D3D1x::Texture*)results->GetTexture();
            ptexture->ApplyTexture(0, ImageFillMode(Wrap_Clamp, Sample_Linear));
            const Matrix2F& mvp = primitive->GetFilterAreaMatrix().GetMatrix2D();
            const Rect<int>& srect = results->GetRect();
            Matrix2F texgen;
            texgen.AppendTranslation((float)srect.x1, (float)srect.y1);
            texgen.AppendScaling((float)srect.Width() / ptexture->GetSize().Width, (float)srect.Height() / ptexture->GetSize().Height);
            applyRawMatrixConstants(mvp, Cxform::Identity, texgen);
            applyBlendMode(BlendModeStack.GetSize()>=1 ? BlendModeStack.Back() : Blend_Normal, true);
            pDeviceContext->Draw(6, 0);
            applyBlendMode(BlendModeStack.GetSize()>=1 ? BlendModeStack.Back() : Blend_Normal, false);
            pDeviceContext->PSSetShaderResources(0, 2, clearViews);

            // Cleanup.
            results->SetInUse(false);
            break;
        }

        // Should have been one of the other two caching types.
        default: SF_ASSERT(0); break;
    }
}

}}} // Scaleform::Render::D3D1x

