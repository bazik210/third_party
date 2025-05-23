#ifndef _MFrameContext
#define _MFrameContext
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
#include <maya/MStatus.h>
#include <maya/MMatrix.h>
#include <maya/MFloatArray.h>
#include <maya/MDoubleArray.h>
#include <maya/MBoundingBox.h>
#include <maya/MDagPath.h>
#include <maya/MString.h>
#include <maya/MColor.h>

// ****************************************************************************
// CLASS FORWARDS


OPENMAYA_MAJOR_NAMESPACE_OPEN

namespace MHWRender
{

// ****************************************************************************
// DECLARATIONS
//
//! \ingroup OpenMayaRender
//! \brief This class contains some global information for the current render frame.
/*!
MFrameContext is designed to provide information which is available per frame
render. This includes information such as render targets, viewport size and
camera information.

In terms of relative scope, MFrameContext can be thought of as encompassing
the time period for a "pass" (MPassContext) and the time period for actual drawing
(MDrawContext).

MDrawContext is derived from MFrameContext and provides its own implementation
for all virtual methods. The values returned from these methods may differ
slightly between MFrameContext and MDrawContext as MFrameContext retrieves the
values from Maya and MDrawContext retrieves the values from the GPU device
state. Also, MFrameContext::getMatrix() is not able to return values for any
matrix type requiring the object-to-world matrix as that information is only
available at draw time.
	*/
class OPENMAYARENDER_EXPORT MFrameContext
{
public:
	//! Matrices that can be accessed
	enum MatrixType {
		kWorldMtx,                      //!< Object to world matrix
		kWorldTransposeMtx,             //!< Object to world matrix transpose
		kWorldInverseMtx,               //!< Object to world matrix inverse
		kWorldTranspInverseMtx,         //!< Object to world matrix transpose inverse (adjoint)
		kViewMtx,                       //!< World to view matrix
		kViewTransposeMtx,              //!< World to view matrix tranpose
		kViewInverseMtx,                //!< World to view matrix inverse
		kViewTranspInverseMtx,          //!< World to view matrix transpose inverse (adjoint)
		kProjectionMtx,                 //!< Projection matrix
		kProjectionTranposeMtx,         //!< Projection matrix tranpose
		kProjectionInverseMtx,          //!< Projection matrix inverse
		kProjectionTranspInverseMtx,    //!< Projection matrix tranpose inverse (adjoint)
		kViewProjMtx,                   //!< View * projection matrix
		kViewProjTranposeMtx,           //!< View * projection matrix tranpose
		kViewProjInverseMtx,            //!< View * projection matrix inverse
		kViewProjTranspInverseMtx,      //!< View * projection matrix tranpose inverse (adjoint)
		kWorldViewMtx,                  //!< World * view matrix
		kWorldViewTransposeMtx,         //!< World * view matrix transpose
		kWorldViewInverseMtx,           //!< World * view matrix inverse
		kWorldViewTranspInverseMtx,     //!< World * view matrix transpose inverse (adjoint)
		kWorldViewProjMtx,              //!< World * view * projection matrix
		kWorldViewProjTransposeMtx,     //!< World * view * projection matrix transpose
		kWorldViewProjInverseMtx,       //!< World * view * projection matrix inverse
		kWorldViewProjTranspInverseMtx  //!< World * view * projection matrix tranpose inverse (adjoint)
	};
	static MFrameContext::MatrixType semanticToMatrixType(const MString &value, MStatus* ReturnStatus=NULL);
	virtual MMatrix getMatrix(MFrameContext::MatrixType mtype, MStatus* ReturnStatus=NULL) const;

	//! Tuples that can be accessed. May be one or more values returned depending on the tuple requested.
	enum TupleType {
		kViewPosition,		//!< View position
		kViewDirection,		//!< View direction vector
		kViewUp,			//!< View up vector
		kViewRight,			//!< View right vector
		kViewportPixelSize,	//!< Viewport size in pixels (single value)
		kViewNearClipValue,	//!< Camera near clip value (single value)
		kViewFarClipValue,	//!< Camera far clip value (single value)
		kViewUnnormlizedNearClipValue,	//!< Unnormalized camera near clip value (single value)
		kViewUnnormalizedFarClipValue	//!< Unnormalized camera far clip value (single value)
	};
	static MFrameContext::TupleType semanticToTupleType(const MString &value, MStatus* ReturnStatus=NULL);
	virtual MDoubleArray getTuple(MFrameContext::TupleType ttype, MStatus* ReturnStatus=NULL) const;

	virtual MStatus getViewportDimensions(int &originX, int &originY, int &width, int &height) const;

	virtual float getGlobalLineWidth() const;

	MDagPath getCurrentCameraPath(MStatus* ReturnStatus=NULL) const;

	const MRenderTarget* getCurrentColorRenderTarget() const;
	const MRenderTarget* getCurrentDepthRenderTarget() const;

	//! Display styles
    enum DisplayStyle
    {
        kGouraudShaded = (0x1),        //!< Shaded display.
        kWireFrame = (0x1 << 1),       //!< Wire frame display.
		kBoundingBox = (0x1 << 2),     //!< Bounding box display.
		kTextured = (0x1 << 3),        //!< Textured display.
		kDefaultMaterial = (0x1 << 4), //!< Default material display.
		kXrayJoint = (0x1 << 5),       //!< X-ray joint display.
		kXray = (0x1 << 6),            //!< X-ray display.
		kTwoSidedLighting = (0x1 << 7), //!< Two-sided lighting enabled.
		kFlatShaded = (0x1 << 8),		//!< Flat shading display.
		kShadeActiveOnly = (0x1 << 9),	//!< Shade active object only.
		kXrayActiveComponents = (0x1 << 10), //!< X-ray active components.
		kBackfaceCulling = (0x1 << 11), //!< Backface culling enabled.
		kSmoothWireframe = (0x1 << 12) //!< Smooth wireframe enabled.
    };
	unsigned int getDisplayStyle() const;

	//! Lighting modes
	enum LightingMode
	{
		kNoLighting,	 //!< Use no light
		kAmbientLight,   //!< Use global ambient light
		kLightDefault,   //!< Use default light
		kSelectedLights, //!< Use lights which are selected
		kSceneLights,    //!< Use all lights in the scene
		kCustomLights	 //!< A custom set of lights which are not part of the scene. Currently this applies for use in the Hypershade Material Viewer panel
	};
	LightingMode getLightingMode() const;
	unsigned int getLightLimit() const;

	//! Struct for environment map parameters.
	struct EnvironmentParams
	{
		bool enabled;     //!< True if an environment is enabled.
		MString filePath; //!< Full path to the environment image file. The image is in lat-long format.
	};

	EnvironmentParams getEnvironmentParameters() const;

	//! Types of post effects which may be enabled during rendering
	enum PostEffectType {
		kAmbientOcclusion,	//!< Screen-space ambient occlusion
		kMotionBlur,		//!< 2D Motion blur
		kGammaCorrection,	//!< Gamma correction
        kViewColorTransformEnabled = kGammaCorrection, //!< Color managed viewing
		kDepthOfField,		//!< Depth of field
		kAntiAliasing		//!< Hardware multi-sampling
	};
	bool getPostEffectEnabled( PostEffectType postEffectType ) const;

	//! Types of the fog mode
	enum FogMode {
		kFogLinear,	//!< The linear fog
		kFogExp,		//!< The exponential fog
		kFogExp2	//!< The exponential squared fog
	};
	//! Struct for hardware fog parameters
	struct HwFogParams
	{
		bool	HwFogEnabled;	//!< If hardware fog is enabled
		FogMode HwFogMode; //!< Hardware fog mode, like Linear, Exponential, Exponential squared.
		float HwFogStart;		//!< The near distance used in the linear fog.
		float HwFogEnd;		//!< The far distance used in the linear fog.
		float HwFogDensity;		//!< The density of the exponential fog.
		MColor HwFogColor;		//!< The fog color includes (r, g, b, a).
	};

	HwFogParams getHwFogParameters() const;

	//! Options for transparency algorithm
	enum TransparencyAlgorithm {
		kUnsorted = 0,	//!< Unsorted transparent object drawing
		kObjectSorting,	//!< Object sorting of transparent objects
		kWeightedAverage, //!< Weight average transparency
		kDepthPeeling, //!< Depth-peel transparency
	};
	TransparencyAlgorithm getTransparencyAlgorithm() const;

	static bool inUserInteraction();
	static bool userChangingViewContext();
	//! Wireframe on shaded modes
	enum WireOnShadedMode
	{
		kWireframeOnShadedFull,		//!< Draw wireframe
		kWireFrameOnShadedReduced,	//!< Draw wireframe but with reduced quality
		kWireFrameOnShadedNone		//!< Do not draw wireframe
	};
	static WireOnShadedMode wireOnShadedMode();
	static bool shadeTemplates();

	//! Rendering destinations
	enum RenderingDestination
	{
		k3dViewport,				//!< Rendering to an interactive 3d viewport
		k2dViewport,				//!< Rendering to an interactive 2d viewport such as the render view
		kImage						//!< Rendering to an image
	};
	RenderingDestination renderingDestination(MString & destinationName) const;

	static MUint64 kExcludeNone;		//!< Exclude no object types
	static MUint64 kExcludeNurbsCurves; //!< Exclude NURBS curves
	static MUint64 kExcludeNurbsSurfaces; //!< Exclude NURBS surface
	static MUint64 kExcludeMeshes;		//!< Exclude polygonal meshes
	static MUint64 kExcludePlanes;		//!< Exclude planes
	static MUint64 kExcludeLights;		//!< Exclude lights
	static MUint64 kExcludeCameras;	//!< Exclude camera
	static MUint64 kExcludeJoints; //!< Exclude joints
	static MUint64 kExcludeIkHandles;//!< Exclude IK handles
	static MUint64 kExcludeDeformers;//!< Exclude all deformations
	static MUint64 kExcludeDynamics;//!< Exclude all dynamics objects (emiiters, cloth)
	static MUint64 kExcludeParticleInstancers;//!< Exclude all Particle Instancers
	static MUint64 kExcludeLocators;//!< Exclude locators
	static MUint64 kExcludeDimensions;//!< Exclude all measurement objects
	static MUint64 kExcludeSelectHandles;//!< Exclude selection handles
	static MUint64 kExcludePivots;	//!< Exclude pivots
	static MUint64 kExcludeTextures;//!< Exclude texure placement objects
	static MUint64 kExcludeGrid;//!< Exclude grid drawing
	static MUint64 kExcludeCVs;//!< Exclude NURBS control vertices
	static MUint64 kExcludeHulls;//!< Exclude NURBS hulls
	static MUint64 kExcludeStrokes;//!< Exclude PaintFX strokes
	static MUint64 kExcludeSubdivSurfaces;//!< Exclude subdivision surfaces
	static MUint64 kExcludeFluids;//!< Exclude fluid objects
	static MUint64 kExcludeFollicles;//!< Exclude hair follicles
	static MUint64 kExcludeHairSystems;//!< Exclude hair system
	static MUint64 kExcludeImagePlane;//!< Exclude image planes
	static MUint64 kExcludeNCloths;//!< Exclude N-cloth objects
	static MUint64 kExcludeNRigids;//!< Exclude rigid-body objects
	static MUint64 kExcludeDynamicConstraints;//!< Exclude rigid-body constraints
	static MUint64 kExcludeManipulators;//!< Exclude manipulators
	static MUint64 kExcludeNParticles;//!< Exclude N-particle objects
	static MUint64 kExcludeMotionTrails;//!< Exclude motion trails
	static MUint64 kExcludeHoldOuts;//!< Exclude Hold-Outs
	static MUint64 kExcludePluginShapes; //!< Exclude plug-in shapes
	static MUint64 kExcludeHUD; //!< Exclude HUD
	static MUint64 kExcludeClipGhosts; //!< Exclude animation clip ghosts
	static MUint64 kExcludeGreasePencils; //!< Exclude grease-pencil draw
	static MUint64 kExcludeControllers; //!< Exclude Controllers
	static MUint64 kExcludeAll	;//!< Exclude all listed object types

	MUint64 objectTypeExclusions() const;
	void classificationExclusions(MStringArray &classification) const;

	//! Background parameters
	struct BackgroundParams
	{
		bool displayGradient;		//!< Display gradient
		bool clearColorFlag;		//!< Clear color flag
		bool clearDepthFlag;		//!< Clear depth flag
		bool clearStencilFlag;		//!< Clear stencil flag
		MColor clearColor1;			//!< Clear color 1
		MColor clearColor2;			//!< Clear color 2
		float clearDepthValue;		//!< Clear depth value
		int clearStencilValue;		//!< Clear stencil value
	};
	void getBackgroundParameters( MFrameContext::BackgroundParams & params ) const;

	//! Depth-of-field parameters
	struct DOFParams
	{
		bool enabled;			//!< True if DOF is enabled
		float focalDistance;	//!< Camera focus distance
		float alpha;			//!< Combination of camera paramaters: a = F*F/(A*(Zf-F))
	};
	void getDOFParameters(MFrameContext::DOFParams &params) const;

	//! Render override information
	struct RenderOverrideInformation
	{
		MString overrideName;	//!< Name of any active override. Empty string if none
	};
	void getRenderOverrideInformation(RenderOverrideInformation &info) const;

	void worldToViewport(const MPoint &inPoint, double &xPos, double &yPos) const;
	void viewportToWorld(double xPos, double yPos, MPoint &worldNearPt, MPoint &worldFarPt) const;

	static const char* className();

protected:
	MFrameContext();
	virtual ~MFrameContext();

	friend class MRenderOverride;
	friend class MPxGeometryOverride;
};

} // namespace MHWRender

OPENMAYA_NAMESPACE_CLOSE

#endif /* __cplusplus */
#endif /* _MFrameContext */
