#ifndef _MPxImagePlaneOverride
#define _MPxImagePlaneOverride
//-
// ===========================================================================
// Copyright 2017 Autodesk, Inc. All rights reserved.
//
// Use of this software is subject to the terms of the Autodesk license
// agreement provided at the time of installation or download, or which
// otherwise accompanies this software in either electronic or hard copy form.
// ===========================================================================
//+
#if defined __cplusplus

// ****************************************************************************
// INCLUDED HEADER FILES
#include <maya/MObject.h>
#include <maya/MViewport2Renderer.h>
#include <maya/MString.h>


OPENMAYA_MAJOR_NAMESPACE_OPEN

// ****************************************************************************
// NAMESPACE

namespace MHWRender
{
// ****************************************************************************
// CLASS DECLARATION (MPxImagePlaneOverride)
//! \ingroup OpenMayaRender MPx
//! \brief Base class for user defined image plane draw overrides.

class OPENMAYARENDER_EXPORT MPxImagePlaneOverride
{
public:

	MPxImagePlaneOverride(const MObject& obj);
	virtual ~MPxImagePlaneOverride();
	
	virtual ::MHWRender::DrawAPI	supportedDrawAPIs() const;
	static const char*				className();

	MString							getFileName(bool useImageSequence);
	virtual void					updateDG();
	virtual void					updateColorTexture();

private:

	void *fData;
};
	
}// namespace MHWRender

OPENMAYA_NAMESPACE_CLOSE

#endif /* __cplusplus */
#endif /* MPxImagePlaneOverride */