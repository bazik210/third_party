#ifndef _MFnMeshData
#define _MFnMeshData
//-
// ===========================================================================
// Copyright 2017 Autodesk, Inc. All rights reserved.
//
// Use of this software is subject to the terms of the Autodesk license
// agreement provided at the time of installation or download, or which
// otherwise accompanies this software in either electronic or hard copy form.
// ===========================================================================
//+
//
// CLASS:    MFnMeshData
//
// ****************************************************************************

#if defined __cplusplus

// ****************************************************************************
// INCLUDED HEADER FILES


#include <maya/MFnGeometryData.h>


OPENMAYA_MAJOR_NAMESPACE_OPEN

// ****************************************************************************
// CLASS DECLARATION (MFnMeshData)

//! \ingroup OpenMaya MFn
//! \brief Mesh function set for dependency node data.
/*!
MFnMeshData allows the creation and manipulation of Mesh data objects
for use in the dependency graph.

If a user written dependency node either accepts or produces Meshes, then
this class is used to create data blocks into which Meshes can be constructed
before being passed to other dependency graph nodes. The MDataHandle::type
method will return kMesh when data of this type is present.

If a node is receiving a Mesh via an input attribute, the asMesh method of
MDataHandle can be used to access that input Mesh.

If a node is to create a Mesh and send it via an output attribute, a new
MFnMeshData must be instantiated and then the create method called to
build the actual data block as an MObject.  This MObject should be passed
to the MFnMesh::create method as the parentOrOwner parameter so that the
Mesh will be constructed inside the data block.  The MDataHandle::set
routine is then used to pass the data block down the connection.
*/
class OPENMAYA_EXPORT MFnMeshData : public MFnGeometryData
{
	declareMFn(MFnMeshData, MFnGeometryData);

public:
	MObject		create( MStatus* ReturnStatus = NULL );

BEGIN_NO_SCRIPT_SUPPORT:

 	declareMFnConstConstructor( MFnMeshData, MFnGeometryData );

END_NO_SCRIPT_SUPPORT:

protected:
// No protected members

private:
// No private members
};

OPENMAYA_NAMESPACE_CLOSE

#endif /* __cplusplus */
#endif /* _MFnMeshData */
