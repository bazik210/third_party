#ifndef _MColorPickerUtilities
#define _MColorPickerUtilities
//
//-
// ===========================================================================
// Copyright 2021 Autodesk, Inc. All rights reserved.
//
// Use of this software is subject to the terms of the Autodesk license
// agreement provided at the time of installation or download, or which
// otherwise accompanies this software in either electronic or hard copy form.
// ===========================================================================
//+
//
// ****************************************************************************

// ****************************************************************************
// INCLUDED HEADER FILES

#include <maya/MColor.h>
#include <maya/MStatus.h>

// ****************************************************************************
// DECLARATIONS

class QWidget;
class QPoint;


OPENMAYA_MAJOR_NAMESPACE_OPEN

// ****************************************************************************
// CLASS DECLARATION (MColorPickerCallback)
OPENMAYA_AVAILABLE(2019)
//! \ingroup OpenMayaRender
//! \brief Helper class for the color picking mechanism.
//!
//! When using the Color Picking mechanism one should create a callback class
//! inhereting from MColorPickerCallback in order to implement the pure virtual 
//! method getcolor(). By having a class (instead of a plain function callback),
//! some custom data could be added to the callback instance.
//!
class OPENMAYARENDER_EXPORT MColorPickerCallback
{
public:

    explicit MColorPickerCallback(QWidget* key);

    virtual ~MColorPickerCallback();

    //! \note The widget is the picked widget, the point is the mouse position 
    //!       in global window coordinate and the boolean indicates to compute the color 
    //!       in the view transform or in the rendering color space.
    virtual MColor getColor(QWidget*, const QPoint&, bool) const = 0;

    QWidget* getKey() const;


    static const char* className();

private:
#ifdef __GNUC__
  friend class shutUpAboutPrivateDestructors;
#endif

    QWidget* m_key;
};


// ****************************************************************************
// CLASS DECLARATION (MColorPickerUtilities)
OPENMAYA_AVAILABLE(2019)
//! \ingroup OpenMayaRender
//! \brief Utilities for implementing Color Pickers.  See also \ref MColorMixingSpaceHelper
class OPENMAYARENDER_EXPORT MColorPickerUtilities
{
public:
    //! Color transform direction
    enum Direction
    {
        kForward = 0, //!< apply the color transform
        kInverse      //!< invert the color transform
    };

    //! \note The widget could be either the registered one or one of its parent.
    static bool isRegisteredToColorPicking(QWidget*);

    static MStatus doRegisterToColorPicking(QWidget*, MColorPickerCallback*);
    static MStatus unregisterFromColorPicking(QWidget*);

    OPENMAYA_AVAILABLE(2023)
    static MColor applyViewTransform(const MColor &inputColor, Direction direction);

    OPENMAYA_AVAILABLE(2023)    
    static MColor grabColor(MStatus *returnedStatus = nullptr);

    static const char* className();

private:
    ~MColorPickerUtilities();
#ifdef __GNUC__
  friend class shutUpAboutPrivateDestructors;
#endif
};


// ****************************************************************************

OPENMAYA_NAMESPACE_CLOSE

#endif /* _MColorPickerUtilities */