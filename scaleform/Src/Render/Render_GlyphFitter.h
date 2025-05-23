/**************************************************************************

PublicHeader:   Render
Filename    :   Render_GlyphFitter.h
Content     :   
Created     :   
Authors     :   Maxim Shemanarev

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/

#ifndef INC_SF_Render_GlyphFitter_H
#define INC_SF_Render_GlyphFitter_H

#include "Render_Containers.h"

namespace Scaleform { namespace Render {

//------------------------------------------------------------------------
class GlyphFitter
{
    enum DirType
    { 
        DirCW  = 1,
        DirCCW = 2
    };

    enum FitDir
    {
        FitX = 1,
        FitY = 2
    };

public:
    struct VertexType
    {
        SInt16 x,y;
    };

    struct ContourType
    {
        unsigned StartVertex;
        unsigned NumVertices;
    };

    GlyphFitter(MemoryHeap* heap, int nominalFontHeight=1024);

    void SetNominalFontHeight(int height) { NominalFontHeight = height; }

    void Clear();
    void MoveTo(float x, float y);
    void LineTo(float x, float y);
    void AddVertex(float x, float y) { LineTo(x, y); } // Alias
    void ClosePolygon();

    float GetLastX() const { return LastXf; }
    float GetLastY() const { return LastYf; }

    int  ComputeTopY() { computeBounds(); return MaxY; }
    void FitGlyph(int heightInPixels, int widthInPixels, 
                  int lowerCaseTop,   int upperCaseTop);

    int                GetNominalFontHeight() const { return NominalFontHeight; }
    int                GetUnitsPerPixelX()    const { return UnitsPerPixelX; }
    int                GetUnitsPerPixelY()    const { return UnitsPerPixelY; }
    int                GetSnappedHeight()     const { return SnappedHeight; }
    UPInt              GetNumContours()       const { return Contours.GetSize(); }
    const ContourType& GetContour(unsigned i)     const { return Contours[i]; }
    const VertexType&  GetVertex(const ContourType& c, unsigned i) const 
    { 
        return Vertices[c.StartVertex + i]; 
    }

    void SnapVertex(VertexType& v)
    {
        int i;

        i = v.y - MinY;
        if(i >= 0 && i < (int)LerpRampY.GetSize())
        {
            v.y = LerpRampY[i] + MinY;
        }

        i = v.x - MinX;
        if(i >= 0 && i < (int)LerpRampX.GetSize())
        {
            v.x = LerpRampX[i] + MinX;
        }
    }

private:
    void removeDuplicateClosures();
    void computeBounds();
    void detectEvents(FitDir dir);
    void computeLerpRamp(FitDir dir, int unitsPerPixel, int middle, int lowerCaseTop, int upperCaseTop);
    int  snapToPixel(int x, int unitsPerPixel)
    {
        return (x + SnappedHeight) / unitsPerPixel * unitsPerPixel - SnappedHeight;
    }

    int                             NominalFontHeight;
    LinearHeap                      LHeap;
    ArrayPaged<ContourType, 2, 4>   Contours;
    ArrayPaged<VertexType, 4, 16>   Vertices;
    ArrayUnsafe<UByte>              Events;
    ArrayPaged<VertexType, 4, 16>   LerpPairs;
    ArrayUnsafe<SInt16>             LerpRampX;
    ArrayUnsafe<SInt16>             LerpRampY;
    SInt16                          MinX;
    SInt16                          MinY;
    SInt16                          MaxX;
    SInt16                          MaxY;
    DirType                         Direction;
    int                             UnitsPerPixelX;
    int                             UnitsPerPixelY;
    int                             SnappedHeight;
    float                           StartX;
    float                           StartY;
    float                           LastXf;
    float                           LastYf;
};

}} // Scaleform::Render

#endif
