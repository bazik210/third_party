#ifndef _MItMeshEdge
#define _MItMeshEdge
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
// CLASS:    MItMeshEdge
//
// ****************************************************************************

#if defined __cplusplus

// ****************************************************************************
// INCLUDED HEADER FILES


#include <maya/MFnDagNode.h>
#include <maya/MObject.h>
#include <maya/MVector.h>
#include <maya/MPoint.h>

OPENMAYA_MAJOR_NAMESPACE_OPEN

// ****************************************************************************
// CLASS DECLARATION (MItMeshEdge)

//! \ingroup OpenMaya
//! \brief Polygon edge iterator. 
/*!
	This class is the edge iterator for polygonal surfaces.

	The iterator functions in two modes depending on whether a component
	is specified. When a component is not given or is NULL the iteration
	will be over all edges for the polygon.  When a component is given
	this iterator will iterate over the edges specified in the component.
	When iterating over components a DAG path to the polygon must also be
	supplied.
*/
class OPENMAYA_EXPORT MItMeshEdge
{
public:
    MItMeshEdge( MObject & polyObject, MStatus * ReturnStatus = NULL );
	MItMeshEdge( MObject & polyObject, MObject & component, MStatus * ReturnStatus = NULL );
    MItMeshEdge( const MDagPath &polyObject, MObject & component = MObject::kNullObj, MStatus * ReturnStatus = NULL );
	virtual ~MItMeshEdge();
    bool        isDone( MStatus * ReturnStatus = NULL );
    MStatus     next();
    MStatus     reset();
    MStatus     reset( MObject & polyObject, MObject & component = MObject::kNullObj );
    MStatus     reset( const MDagPath &polyObject, MObject & component = MObject::kNullObj );
    int        count( MStatus * ReturnStatus = NULL );
    MPoint      center( MSpace::Space space = MSpace::kObject,
						MStatus * ReturnStatus = NULL );
    MPoint      point( int index, MSpace::Space space = MSpace::kObject,
						MStatus * ReturnStatus = NULL );
    MStatus     setPoint( const MPoint & point, unsigned int index,
						MSpace::Space space = MSpace::kObject );
	bool		isSmooth( MStatus * ReturnStatus = NULL ) const;
	MStatus		setSmoothing( bool smooth = true );
	// Obsolete
	MStatus		cleanupSmoothing();
    int         index( int index, MStatus * ReturnStatus = NULL );
    int         index( MStatus * ReturnStatus = NULL ) const;
	// Obsolete
	MObject		edge( MStatus * ReturnStatus = NULL );
	MObject		currentItem( MStatus * ReturnStatus = NULL );
    MStatus     updateSurface();
    MStatus     geomChanged();
	MStatus		setIndex(int index, int &prevIndex );
	int			getConnectedFaces(MIntArray & faceList,
								  MStatus * ReturnStatus = NULL ) const;
	int			getConnectedEdges(MIntArray & edgeList,
								  MStatus * ReturnStatus = NULL ) const;
	MStatus		numConnectedFaces(int &faceCount ) const;
	MStatus		numConnectedEdges(int &edgeCount ) const;
	bool		connectedToFace( int index, MStatus * ReturnStatus = NULL);
	bool		connectedToEdge( int index, MStatus * ReturnStatus = NULL);
	bool		onBoundary(MStatus * ReturnStatus = NULL );
	MStatus		getLength(double &length,
						MSpace::Space space = MSpace::kObject );

    static const char*  className();

protected:
// No protected members

private:
    void     *       f_it;
    MPtrBase *       f_shape;
    void	 *       f_path;
    void	 *       f_geom;
	void     *       fElements;
	int              fCurrentElement;
	int              fMaxElements;
	int				 fCurrentIndex;
	void	*		 f_edge;
	void	*		 f_ref;
	bool			 fDirectIndex;
	bool			 fCustomEdgeComponent;
};

OPENMAYA_NAMESPACE_CLOSE

#endif /* __cplusplus */
#endif /* _MItMeshEdge */
