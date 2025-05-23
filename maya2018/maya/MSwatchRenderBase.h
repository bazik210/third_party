#ifndef _MSwatchRenderBase
#define _MSwatchRenderBase
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
// CLASS:    MSwatchRenderBase
//
// ****************************************************************************

#if defined __cplusplus

// ****************************************************************************
// INCLUDED HEADER FILES


#include <maya/MImage.h>

OPENMAYA_MAJOR_NAMESPACE_OPEN

//! \ingroup OpenMayaRender
//! \brief Swatch Render Base class
/*!
A class providing an interface through which a plugin can implement a
class to provide custom rendered images for swatches which are
displayed in hypershade and the Attribute Editor.

By deriving from this class and implementing the doIteration function,
swatches for nodes (having the required classification) can be custom
rendered by the plugin.

The derived class needs to be registered with Maya using the interface
provided by MSwatchRenderRegister.  Please refer to documentation of
MSwatchRenderRegister for more details.

To indicate that swatch for a certain node type will be generated by
the plugin the classfication string of the node needs to contain the
following string : "swatch/<swatch generator name>" The swatch
generator name string should match the name used to register the
swatch generator class.
*/
class OPENMAYARENDER_EXPORT MSwatchRenderBase {
public:

	MSwatchRenderBase(MObject obj, MObject renderObj, int res);

	virtual	~MSwatchRenderBase();

	virtual bool doIteration()  ;

	virtual bool renderParallel();

    virtual void cancelParallelRendering();

	MObject swatchNode() const ;

	MObject node() const ;

	int		resolution() const ;

	MImage&  image() ;
	// this has to be a reference otherwise the internal image gets deleted !

    void setRenderQuality(int);
    int renderQuality() const;

public:
    static void cancelCurrentSwatchRender();

	static void enableSwatchRender(bool enable);

protected :

	void finishParallelRender();

	// node for which the swatch is required
	MObject fObjToSwatch ;
	MObject fObjToRender ;

	// object in which the swatch image should be stored
	MImage fImage ;

	// resolution at which the swatch image is to be generated
	int fRes ;

    // render quality in which the swatch will be rendered.
    int fRenderQuality;

private:
	// No private members
};

inline
MObject MSwatchRenderBase::swatchNode() const
{
	return fObjToSwatch ;
}

inline
MObject MSwatchRenderBase::node() const
{
	return fObjToRender ;
}

inline int
MSwatchRenderBase::resolution() const
{
	return fRes ;
}

inline MImage&
MSwatchRenderBase::image()
{
	return fImage ;
}
OPENMAYA_NAMESPACE_CLOSE

#endif /* __cplusplus */
#endif /* _MSwatchRenderBase */
