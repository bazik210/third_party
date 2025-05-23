#ifndef _MItMeshVertex
#define _MItMeshVertex
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
// CLASS:    MItMeshVertex
//
// ****************************************************************************

#if defined __cplusplus

// ****************************************************************************
// INCLUDED HEADER FILES


#include <maya/MFnDagNode.h>
#include <maya/MObject.h>
#include <maya/MVector.h>
#include <maya/MPoint.h>
#include <maya/MColor.h>
#include <maya/MFloatVectorArray.h>
#include <maya/MFloatArray.h>
#include <maya/MVectorArray.h>
#include <maya/MColorArray.h>
#include <maya/MString.h>

OPENMAYA_MAJOR_NAMESPACE_OPEN

// ****************************************************************************
// CLASS DECLARATION (MItMeshVertex)

//! \ingroup OpenMaya
//! \brief Polygon vertex iterator. 
/*!
	This class is the iterator for polygonal vertices.

	The iterator functions in two modes depending on whether a component
	is specified. When a component is not given or is NULL the iteration
	will be over all vertices for the polygon.  When a component is given
	this iterator will iterate over the vertices specified in the component.
	When iterating over components a DAG path to the surface must also be
	supplied.
*/
class OPENMAYA_EXPORT MItMeshVertex
{
public:
	MItMeshVertex( MObject & polyObject, MStatus * ReturnStatus = NULL );
	MItMeshVertex( const MDagPath &polyObject,
						MObject & component = MObject::kNullObj,
						MStatus * ReturnStatus = NULL );
	virtual ~MItMeshVertex();
	bool		isDone( MStatus * ReturnStatus = NULL );
	MStatus		next();
	MStatus		reset();
	MStatus		reset( MObject & polyObject );
	MStatus		reset( const MDagPath &polyObject,
					MObject & component = MObject::kNullObj );

	int		count( MStatus * ReturnStatus = NULL );

	// The index in the vertex list of the current vertex in iteration.
	//
	int		index( MStatus * ReturnStatus = NULL );
	// Obsolete
	MObject		vertex( MStatus * ReturnStatus = NULL );
	MObject		currentItem( MStatus * ReturnStatus = NULL );

	MPoint		position( MSpace::Space space = MSpace::kObject,
					      MStatus * ReturnStatus = NULL );
	MStatus		setPosition( const MPoint & point,
						  MSpace::Space space = MSpace::kObject );
	MStatus		translateBy( const MVector & vector,
						  MSpace::Space space = MSpace::kObject );

	MStatus		getNormal( MVector & vector,
						  MSpace::Space space = MSpace::kObject );
	MStatus		getNormal( MVector & vector, int faceIndex,
						  MSpace::Space space = MSpace::kObject );
	MStatus		getNormals( MVectorArray & vectorArray,
						  MSpace::Space space = MSpace::kObject );
	MStatus		getNormalIndices( MIntArray& normalIndices) const;

	MStatus		numUVs( int &count, const MString * uvSet = NULL);
	MStatus		setUV( float2 & uvPoint, const MString * uvSet = NULL);
	MStatus		getUV( float2 & uvPoint, const MString * uvSet = NULL);
	MStatus		setUV( int faceId, float2 & uvPoint, const MString * uvSet = NULL);
	MStatus		getUV( int faceId, float2 & uvPoint, const MString * uvSet = NULL) const;
	MStatus 	setUVs( MFloatArray& uArray, MFloatArray& vArray, MIntArray& faceIds,
						const MString * uvSet = NULL );
	MStatus 	getUVs( MFloatArray& uArray, MFloatArray& vArray, MIntArray& faceIds,
						const MString * uvSet = NULL) const;
	MStatus		getUVIndices( MIntArray& uvIndices, const MString * uvSet = NULL) const;

	MStatus		updateSurface();
    MStatus     geomChanged();
	MStatus		setIndex(int index, int &prevIndex);
	MStatus		getConnectedFaces( MIntArray & faceList);
	MStatus		getConnectedEdges( MIntArray & edgeList );
	MStatus		getConnectedVertices( MIntArray & vertexList );
	MStatus		numConnectedFaces(int &faceCount ) const;
	MStatus		numConnectedEdges(int &edgeCount ) const;
	bool		connectedToFace( int faceIndex, MStatus * ReturnStatus = NULL);
	bool		connectedToEdge( int edgeIndex, MStatus * ReturnStatus = NULL);
	MStatus		getOppositeVertex( int &vertexId, int edgeId);
	bool        onBoundary(MStatus * ReturnStatus = NULL );

	bool		hasColor(MStatus * ReturnStatus = NULL ) const;
	bool		hasColor(int faceIndex, MStatus * ReturnStatus = NULL ) const;
	MStatus		getColor(MColor &color, int faceIndex, const MString *colorSetName = NULL) const;
	MStatus		getColor(MColor &color, const MString *colorSetName = NULL) const;
	MStatus		getColors(MColorArray &colors, const MString *colorSetName = NULL) const;
	MStatus		getColorIndices( MIntArray &colorIndex, const MString *colorSetName = NULL ) const;

	static const char* 	className();

protected:
    bool		getUVSetIndex( const MString * uvSetName,
								   int & uvSet) const;

	bool		updateColorSet(const MString *colorSetName, int& prevSetId) const;

	void		resetColorSetToPrevious(const MString *colorSetName, int prevSetId) const;

private:
	void     *       f_it;
	MPtrBase *       f_shape;
	void     *       f_path;
	void     *       f_geom;
	void     *       fElements;
	int             fCurrentElement;
	int             fMaxElements;
	int				fCurrentIndex;
	void	*		 f_vertex;
	void	*		 f_ref;
	bool			 fDirectIndex;
};

OPENMAYA_NAMESPACE_CLOSE

#endif /* __cplusplus */
#endif /* _MItMeshVertex */



