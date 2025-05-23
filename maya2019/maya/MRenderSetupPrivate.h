// Content of this header should not appear in external documentation.
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#ifndef _MRenderSetupPrivate
#define _MRenderSetupPrivate
//
//-
// ===========================================================================
// Copyright 2018 Autodesk, Inc.  All rights reserved.
//
// Use of this software is subject to the terms of the Autodesk license
// agreement provided at the time of installation or download, or which
// otherwise accompanies this software in either electronic or hard copy form.
// ===========================================================================
//+
//
// ****************************************************************************

#if defined __cplusplus

// ****************************************************************************
// INCLUDED HEADER FILES

#include <maya/MApiNamespace.h>

OPENMAYA_MAJOR_NAMESPACE_OPEN

// ****************************************************************************
// CLASS DECLARATION (MRenderSetupPrivate)
//
//! \ingroup OpenMayaRender
//! \brief Undocumented implementation utilities for render setup.
//
// Methods in this class are an implementation detail of render setup.
// They should not be invoked by client code, and are subject to change
// without notice.

class OPENMAYARENDER_EXPORT MRenderSetupPrivate
{
public:
	static const char* className();

    static void _triggerSelectionChanged();

    static MStatus _switchToLegacyRenderLayer(const MString& renderLayerName);

private:

    ~MRenderSetupPrivate();

#ifdef __GNUC__
	friend class shutUpAboutPrivateDestructors;
#endif
};

// ****************************************************************************

OPENMAYA_NAMESPACE_CLOSE

#endif /* __cplusplus */
#endif /* _MRenderSetupPrivate */
#endif /* DOXYGEN_SHOULD_SKIP_THIS */
