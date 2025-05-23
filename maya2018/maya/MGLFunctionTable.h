#ifndef _MGLFunctionTable_h_
#define _MGLFunctionTable_h_
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
// CLASS:    MGlFunctionTable
//
// ****************************************************************************

#if defined __cplusplus

// ****************************************************************************
// INCLUDED HEADER FILES


#include <maya/MGLdefinitions.h>

// ****************************************************************************
// DECLARATIONS

//! Enumeration of OpenGL extensions supported by MGL.
/*!
	The following extensions are not included in this enumeration because
	they were promoted to core features in OpenGL 1.1 and are therefore
	assumed to exist:

		EXT_vertex_array, EXT_polygon_offset, EXT_blend_logic_op,
		EXT_texture, EXT_copy_texture, EXT_subtexture,
		EXT_texture_object.
*/
enum MGLExtension
{
	//---------------------------------------------------------------
	//
	//		CORE MGL EXTENSIONS
	//		Version 1.2
	//
	//---------------------------------------------------------------

	// Version 1.2 Extensions
	kMGLext_abgr,						//!< aka EXT_abgr
	kMGLext_bgra,						//!< aka EXT_bgra
	kMGLext_draw_range_elements,		//!< aka EXT_draw_range_elements
	kMGLext_packed_pixels,				//!< aka EXT_packed_pixels
	kMGLext_rescale_normal,				//!< aka EXT_rescale_normal
	kMGLext_separate_specular_color,	//!< aka EXT_separate_specular_color
	kMGLext_texture3D,					//!< aka EXT_texture3D
	kMGLext_texture_edge_clamp,			//!< aka SGIS_texture_edge_clamp
	kMGLext_texture_lod,				//!< aka SGIS_texture_lod


	//---------------------------------------------------------------
	//
	//		CORE MGL EXTENSIONS
	//		Version 1.2.1
	//
	//---------------------------------------------------------------

	kMGLext_multitexture,		//!< \nop

	//---------------------------------------------------------------
	//
	//		CORE MGL EXTENSIONS
	//		Version 1.3
	//
	//---------------------------------------------------------------

	kMGLext_multisample,			//!< subset of EXT_multisample
	kMGLext_texture_compression,	//!< aka MGL_ARB_texture_compression
	kMGLext_texture_cube_map,		//!< aka ARB_texture_cube_map
	kMGLext_texture_env_add,		//!< aka MGL_ARB_texture_env_add
	kMGLext_texture_env_combine,	//!< aka MGL_ARB_texture_env_combine
	kMGLext_texture_env_dot3,		//!< aka MGL_ARB_texture_env_dot3
	kMGLext_texture_border_clamp,	//!< aka MGL_ARB_texture_border_clamp
	kMGLext_transpose_matrix,		//!< aka MGL_ARB_transpose_matrix

	//---------------------------------------------------------------
	//
	//		CORE MGL EXTENSIONS
	//		Version 1.4
	//
	//---------------------------------------------------------------
	kMGLext_multi_draw_arrays,		//!< \nop
	kMGLext_texture_mirrored_repeat,//!< \nop

	//---------------------------------------------------------------
	//
	//		CORE MGL EXTENSIONS
	//		Version 1.5
	//
	//---------------------------------------------------------------
	kMGLext_ARB_texture_non_power_of_two, //!< Non-power-of-two textures
	kMGLext_ARB_texture_rectangle,		 //!< Rectangular textures

	//---------------------------------------------------------------
	//
	//		IMAGING SUBSET CORE EXTENSIONS
	//
	//---------------------------------------------------------------

	kMGLext_imaging_subset,			//!< combination of kMGLext_blend_color thru kMGLext_convolution
	kMGLext_blend_color,			//!< aka EXT_blend_color
	kMGLext_blend_minmax,			//!< aka EXT_blend_minmax
	kMGLext_blend_subtract,			//!< aka EXT_blend_subtract
	kMGLext_histogram,				//!< aka EXT_histogram
	kMGLext_color_matrix,			//!< aka SGI_color_matrix
	kMGLext_color_table,			//!< aka EXT_color_table and EXT_color_subtable.
	kMGLext_convolution,			//!< aka EXT_convolution and HP_convolution_border_modes.


	//---------------------------------------------------------------
	//
	//		OPTIONAL ARB/CORE EXTENSIONS
	//
	//---------------------------------------------------------------

	kMGLext_ARB_vertex_blend,		//!< \nop
	kMGLext_ARB_matrix_palette,		//!< \nop
	kMGLext_ARB_point_parameters,	//!< aka EXT_point_parameters
	kMGLext_ARB_texture_env_crossbar,	//!< \nop
	kMGLext_ARB_depth_texture,		//!< ARB depth textures - not SGIX !
	kMGLext_ARB_shadow,				//!< ARB shadows - not SGIX !
	kMGLext_ARB_shadow_ambient,		//!< ARB shadows - not SGIX !
	kMGLext_SGIX_depth_texture,		//!< SGIX depth textures
	kMGLext_SGIX_shadow,			//!< \nop
	kMGLext_ARB_texgen_reflection,	//!< reflection texture coord generation
	kMGLext_ARB_vertex_program,		//!< ARB vertex program
	kMGLext_ARB_fragment_program,	//!< ARB fragment program
	kMGLext_ARB_occlusion_query,	//!< ARB occlusion query
	kMGLext_ARB_vertex_buffer_object, //!< ARB vertex buffer objects
	kMGLext_ARB_half_float_pixel,	//!< ARB half float pixel
	kMGLext_ARB_texture_float,		//!< ARB texture float
	kMGLext_ARB_color_buffer_float,	//!< ARB color buffer float

	kMGLext_ARB_fragment_program_shadow,	//!< ARB fragment program shadow

	kMGLext_ATI_pixel_format_float,	//!< ATI float buffer
	kMGLext_NV_float_buffer,		//!< nVidia float buffer

	//---------------------------------------------------------------
	//
	//		CORE MGL EXTENSIONS
	//		Version 2.0
	//
	//---------------------------------------------------------------
	kMGLext_ARB_OpenMGL20,		//!< \nop

	//---------------------------------------------------------------
	//
	//		CORE MGL EXTENSIONS
	//		Version 3.3
	//
	//---------------------------------------------------------------
	kMGLext_ARB_explicit_attrib_location,	//!< ARB explicit attribute location
	kMGLext_ARB_instanced_arrays,	//!< ARB instanced array

	//---------------------------------------------------------------
	//
	//		CORE MGL EXTENSIONS
	//		Version 4.1
	//
	//---------------------------------------------------------------
	kMGLext_ARB_ES2_compatibility,	//!< ARB ES2 compatibility

	//---------------------------------------------------------------
	//
	//		OTHER OPTIONAL EXTENSIONS
	//
	//---------------------------------------------------------------

	kMGLext_EXT_compiled_vertex_array,	//!< \nop
	kMGLext_EXT_cull_vertex,			//!< \nop
	kMGLext_EXT_secondary_color,		//!< \nop
	kMGLext_EXT_fog_coord,				//!< \nop
	kMGLext_EXT_vertex_weighting,		//!< \nop
	kMGLext_EXT_vertex_shader,	//!< used by ATI, but also reportedly by Matrox and 3DLabs
	kMGLext_EXT_texture_filter_anisotropic,		//!< \nop
	kMGLext_texture_compression_s3tc,	//!< lossy 4X texture compression
	kMGLext_EXT_transform_feedback,     //!< \nop
	kMGLext_ARB_sync,					//!< \nop
	kMGLext_ARB_cl_event,				//!< \nop

	// ATI-specific
	kMGLext_ATI_fragment_shader,		//!< \nop
	kMGLext_ATI_meminfo,                //!< \nop
	kMGLext_ATI_texture_mirror_once,	//!< \nop

	// nVidia-specific
	kMGLext_NV_fence,					//!< \nop
	kMGLext_NV_register_combiners,		//!< \nop
	kMGLext_NV_texture_shader,			//!< \nop
	kMGLext_NV_vertex_array_range,		//!< \nop
	kMGLext_NV_vertex_program,			//!< \nop
	kMGLext_NV_fragment_program,		//!< \nop
	kMGLext_NV_occlusion_query,			//!< \nop
	kMGLext_NV_primitive_restart,		//!< \nop
	kMGLext_NV_transform_feedback,      //!< \nop
	kMGLext_NVX_gpu_memory_info,        //!< \nop

	// SGI extensions
	kMGLext_SGIS_generate_mipmap,		//!< \nop

	// EXT frame buffer object
	kMGLext_frame_buffer_object,		//!< \nop

	kMGLext_packed_depth_stencil,		//!< aka EXT_packed_depth_stencil
	kMGLext_framebuffer_multisample,	//!< aka EXT_framebuffer_multisample
	kMGLext_texture_array,				//!< aka EXT_texture_array

	//---------------------------------------------------------------
	//
	//		CORE WMGL
	//
	//---------------------------------------------------------------
	kMGLext_WMGL_ARB_extensions_string,		//!< aka WMGL_EXT_extensions_string

	//---------------------------------------------------------------
	//
	//		NON-CORE WMGL EXTENSIONS
	//
	//---------------------------------------------------------------
	kMGLext_WMGL_ARB_buffer_region,			//!< \nop
	kMGLext_WMGL_ARB_pbuffer,				//!< aka WMGL_EXT_pbuffer
	kMGLext_WMGL_ARB_pixel_format,			//!< aka WMGL_EXT_pixel_format
	kMGLext_WMGL_ARB_make_current_read,		//!< aka WMGL_EXT_make_current_read
	kMGLext_WMGL_ARB_render_texture,		//!< \nop
	kMGLext_WMGL_NV_allocate_memory,		//!< \nop

    //----------------------------------------------------------//
	//    														//
	//      CORE MGLX											//
	//            												//
    //----------------------------------------------------------//
    kMGLext_MGLX_create_pbuffer,		//!< \nop
    kMGLext_MGLX_choose_fbconfig,		//!< \nop
    kMGLext_MGLX_create_new_context,	//!< \nop
    kMGLext_MGLX_destroy_window,		//!< \nop
	kMGLext_MGLX_destroy_pbuffer,		//!< \nop
    // older MGLX versions 1.2
    kMGLext_MGLX_create_pbuffer_sgix,	//!< \nop
    kMGLext_MGLX_choose_fbconfig_sgix,	//!< \nop
    kMGLext_MGLX_create_context_with_config_sgix,	//!< \nop
	kMGLext_MGLX_get_visual_from_fbconfig_sgix,		//!< \nop

	// LAST ENTRY
	kMGLext_NUMBER_OF_EXTENSIONS		//!< Last entry placeholder.
};

OPENMAYA_MAJOR_NAMESPACE_OPEN

// ****************************************************************************
// CLASS DECLARATION (MGLFunctionTable)

//! \ingroup OpenMayaRender
//! \brief \obsolete
/*!

\deprecated
Please use the Viewport 2.0 device independent MHWRender interfaces instead.

The best cross platform alternative for drawing in Viewport 2.0 is
via MHWRender::MVertexBuffer, MHWRender::MPxGeometryOverride, and 
other classes providing an abstraction from the underlying hardware 
API. The MHWRender::MUIDrawManager offers handy options for very 
simple drawing commands.

Drawing in raw OpenGL mode will still be allowed, but we recommend
you use the core profile subset of the OpenGL API to ensure compatibility 
with future versions of Maya.

MGLFunctionTable is a utility class which provides wrappers for the basic
functions in the OpenGL API.

Core functions up to OpenGL 2.0 are provided here, as well as a number
of ARB/EXT and vendor specific extensions. Refer to the MGLExtension
enumeration for extensions which are checked.

Please refer to an OpenGL reference for usage of the OpenGL functions
provided in this wrapper class.

When using the functions provided, the standard GL* type and constant
definitions to be used can be found in MGLDefinitions.h.

MGLDefinitions.h basically provides a wrapper for what would
normally be found in gl.h and glext.h files.

The naming convention used in this file is to take the regular GL*
definitions and add a "M" prefix. This is to avoid conflicts with existing
type and constant declarations which may be found in files such as gl.h and
glext.h. It is recommended that externally provided files
which have GL definitions not be included in the same C++ file to avoid
conflicts. <b>Mixing GL code wusing MGLFunctionTable and external
code is possible, just not recommended.</b>

MGLFunctionTable cannot be created on its own, and must
be retrieved via a method on the MHardwareRenderer class. It is possible
that this class will not be available, if the hardware renderer class
cannot be instantiated. This would be due to insufficient graphics
hardware support.

Below is an example of initializing and using the function table to
draw a simple 3-line axis. Note the usage of the definitions from
MGLDefinitions such as MGL_LIGHTING versus GL_LIGHTING, and MGL_LINES
and MGL_DEPTH_TEST.

\code

#include <maya/MHardwareRenderer.h>
#include <maya/MGLFunctionTable.h>

class myClass
{
public:
	MStatus	initializeGL();
	void	drawAxis();
protected:
	MGLFunctionTable *gGLFT; // Function table to use
private:
// No private members
};

MStatus
myClass::initializeGL()
{
	// Get a pointer to a GL function table
	MHardwareRenderer *rend = MHardwareRenderer::theRenderer();
	if (rend)
		gGLFT = rend->glFunctionTable();
	if (!gGLFT)
		return MStatus::kFailure;
	return MStatus::kSuccess;
}

void
myClass::drawAxis()
{
	// Draw a world space axis
	//
	gGLFT->glDisable(MGL_LIGHTING);
	gGLFT->glBegin(MGL_LINES);
	gGLFT->glColor3f( 1.0f, 0.0f, 0.0f );
	gGLFT->glVertex3f( 0.0f, 0.0f, 0.0f );
	gGLFT->glVertex3f( 3.0f, 0.0f, 0.0f );

	gGLFT->glColor3f( 0.0f, 1.0f, 0.0f );
	gGLFT->glVertex3f( 0.0f, 0.0f, 0.0f );
	gGLFT->glVertex3f( 0.0f, 3.0f, 0.0f );

	gGLFT->glColor3f( 0.0f, 0.0f, 1.0f );
	gGLFT->glVertex3f( 0.0f, 0.0f, 0.0f );
	gGLFT->glVertex3f( 0.0f, 0.0f, 3.0f );
	gGLFT->glEnd();
	gGLFT->glEnable(MGL_LIGHTING);
}
\endcode

Here is a similar example of using the function table in Python.

\code
# Import the module
import maya.OpenMayaRender as OpenMayaRender

# Get a renderer, then a function table
def initializeGL():
  glRenderer = OpenMayaRender.MHardwareRenderer.theRenderer()
  glFT = glRenderer.glFunctionTable()

# Query the maximum texture size
def printMaxTextureSize():
  maxTxtSize = glFT.maxTextureSize()
  print maxTxtSize

# Draw an axis
def drawAxis():
  glFT.glDisable(OpenMayaRender.MGL_LIGHTING)
  glFT.glBegin(OpenMayaRender.MGL_LINES)

  glFT.glColor3f( 1.0, 0.0, 0.0 )
  glFT.glVertex3f( 0.0, 0.0, 0.0 )
  glFT.glVertex3f( 3.0, 0.0, 0.0 )

  glFT.glColor3f( 0.0, 1.0, 0.0 )
  glFT.glVertex3f( 0.0, 0.0, 0.0 )
  glFT.glVertex3f( 0.0, 3.0, 0.0 )

  glFT.glColor3f( 0.0, 0.0, 1.0 )
  glFT.glVertex3f( 0.0, 0.0, 0.0 )
  glFT.glVertex3f( 0.0, 0.0, 3.0 )

  glFT.glEnd()
  glFT.glEnable(OpenMayaRender.MGL_LIGHTING)
\endcode
*/
class OPENMAYARENDER_EXPORT MGLFunctionTable
{
public:

	// Version enumeration
	//! OpenGL versions checked.
	enum MGLversion {
		kMGL_Version11,						//!< GL 1.1
		kMGL_Version12,						//!< GL 1.2
		kMGL_Version121,					//!< GL 1.2.1
		kMGL_Version13,						//!< GL 1.3.1
		kMGL_Version14,						//!< GL 1.4.1
		kMGL_Version15,						//!< GL 1.5
		kMGL_Version20						//!< GL 2.0
	};

	//
	// Buffer operations
	//
	void glClear(MGLbitfield mask);
	void glClearAccum(MGLfloat red, MGLfloat green, MGLfloat blue, MGLfloat alpha);
	void glClearColor(MGLclampf red, MGLclampf green, MGLclampf blue, MGLclampf alpha);
	void glClearDepth(MGLclampd depth);
	void glClearIndex(MGLfloat c);
	void glClearStencil(MGLint s);
    void glSampleCoverage(MGLclampf value, MGLboolean invert);

	// List of capabilities.
	bool extensionExists(MGLExtension extension);

	// Return the number of texture units supported by this device.
	// Equivalent to min(numTexInterpolants, numTexImageUnits).
	//
	unsigned int numTexUnits() const;

	// Return the number of texture interpolants.
	// These can be used to transfer texture coordinates.
	//
	unsigned int numTexInterpolants() const;

	// Return the max number of texture images.
	// These can be used to fetch texels from a texture.
	//
	unsigned int numTexImageUnits() const;

    // Return the maximum width or height of any texture
    // image (without borders).
    //
    unsigned int maxTextureSize() const;

	// Return the maximum number of vertex attributes
	// for vertex programming.
	unsigned int maxVertexAttributes() const;


	//---------------------------------------------------------------
	//
	//		CORE MGL FUNCTIONS
	//		Version 1.0 - 1.1
	//
	//---------------------------------------------------------------

	void glAccum(MGLenum op, MGLfloat value);
	void glAlphaFunc(MGLenum func, MGLclampf ref);
	MGLboolean glAreTexturesResident(MGLsizei n, const MGLuint *textures, MGLboolean *residences);
	void glArrayElement(MGLint i);
	void glBegin(MGLenum mode);
	void glBindTexture(MGLenum target, MGLuint texture);
	void glBitmap(MGLsizei width, MGLsizei height, MGLfloat xorig, MGLfloat yorig, MGLfloat xmove, MGLfloat ymove, const MGLubyte *bitmap);
	void glBlendFunc(MGLenum sfactor, MGLenum dfactor);
	void glCallList(MGLuint list);
	void glCallLists(MGLsizei n, MGLenum type, const MGLvoid *lists);
	void glClipPlane(MGLenum plane, const MGLdouble *equation);
	void glColor3b(MGLbyte red, MGLbyte green, MGLbyte blue);
	void glColor3bv(const MGLbyte *v);
	void glColor3d(MGLdouble red, MGLdouble green, MGLdouble blue);
	void glColor3dv(const MGLdouble *v);
	void glColor3f(MGLfloat red, MGLfloat green, MGLfloat blue);
	void glColor3fv(const MGLfloat *v);
	void glColor3i(MGLint red, MGLint green, MGLint blue);
	void glColor3iv(const MGLint *v);
	void glColor3s(MGLshort red, MGLshort green, MGLshort blue);
	void glColor3sv(const MGLshort *v);
	void glColor3ub(MGLubyte red, MGLubyte green, MGLubyte blue);
	void glColor3ubv(const MGLubyte *v);
	void glColor3ui(MGLuint red, MGLuint green, MGLuint blue);
	void glColor3uiv(const MGLuint *v);
	void glColor3us(MGLushort red, MGLushort green, MGLushort blue);
	void glColor3usv(const MGLushort *v);
	void glColor4b(MGLbyte red, MGLbyte green, MGLbyte blue, MGLbyte alpha);
	void glColor4bv(const MGLbyte *v);
	void glColor4d(MGLdouble red, MGLdouble green, MGLdouble blue, MGLdouble alpha);
	void glColor4dv(const MGLdouble *v);
	void glColor4f(MGLfloat red, MGLfloat green, MGLfloat blue, MGLfloat alpha);
	void glColor4fv(const MGLfloat *v);
	void glColor4i(MGLint red, MGLint green, MGLint blue, MGLint alpha);
	void glColor4iv(const MGLint *v);
	void glColor4s(MGLshort red, MGLshort green, MGLshort blue, MGLshort alpha);
	void glColor4sv(const MGLshort *v);
	void glColor4ub(MGLubyte red, MGLubyte green, MGLubyte blue, MGLubyte alpha);
	void glColor4ubv(const MGLubyte *v);
	void glColor4ui(MGLuint red, MGLuint green, MGLuint blue, MGLuint alpha);
	void glColor4uiv(const MGLuint *v);
	void glColor4us(MGLushort red, MGLushort green, MGLushort blue, MGLushort alpha);
	void glColor4usv(const MGLushort *v);
	void glColorMask(MGLboolean red, MGLboolean green, MGLboolean blue, MGLboolean alpha);
	void glColorMaterial(MGLenum face, MGLenum mode);
	void glColorPointer(MGLint size, MGLenum type, MGLsizei stride, const MGLvoid *pointer);
	void glCopyPixels(MGLint x, MGLint y, MGLsizei width, MGLsizei height, MGLenum type);
	void glCopyTexImage1D(MGLenum target, MGLint level, MGLenum internalFormat, MGLint x, MGLint y, MGLsizei width, MGLint border);
	void glCopyTexImage2D(MGLenum target, MGLint level, MGLenum internalFormat, MGLint x, MGLint y, MGLsizei width, MGLsizei height, MGLint border);
	void glCopyTexSubImage1D(MGLenum target, MGLint level, MGLint xoffset, MGLint x, MGLint y, MGLsizei width);
	void glCopyTexSubImage2D(MGLenum target, MGLint level, MGLint xoffset, MGLint yoffset, MGLint x, MGLint y, MGLsizei width, MGLsizei height);
	void glCullFace(MGLenum mode);
	void glDeleteLists(MGLuint list, MGLsizei range);
	void glDeleteTextures(MGLsizei n, const MGLuint *textures);
	void glDepthFunc(MGLenum func);
	void glDepthMask(MGLboolean flag);
	void glDepthRange(MGLclampd zNear, MGLclampd zFar);
	void glDisable(MGLenum cap);
	void glDisableClientState(MGLenum array);
	void glDrawArrays(MGLenum mode, MGLint first, MGLsizei count);
	void glDrawBuffer(MGLenum mode);
	void glDrawElements(MGLenum mode, MGLsizei count, MGLenum type, const MGLvoid *indices);
	void glDrawPixels(MGLsizei width, MGLsizei height, MGLenum format, MGLenum type, const MGLvoid *pixels);
	void glEdgeFlag(MGLboolean flag);
	void glEdgeFlagPointer(MGLsizei stride, const MGLvoid *pointer);
	void glEdgeFlagv(const MGLboolean *flag);
	void glEnable(MGLenum cap);
	void glEnableClientState(MGLenum array);
	void glEnd(void);
	void glEndList(void);
	void glEvalCoord1d(MGLdouble u);
	void glEvalCoord1dv(const MGLdouble *u);
	void glEvalCoord1f(MGLfloat u);
	void glEvalCoord1fv(const MGLfloat *u);
	void glEvalCoord2d(MGLdouble u, MGLdouble v);
	void glEvalCoord2dv(const MGLdouble *u);
	void glEvalCoord2f(MGLfloat u, MGLfloat v);
	void glEvalCoord2fv(const MGLfloat *u);
	void glEvalMesh1(MGLenum mode, MGLint i1, MGLint i2);
	void glEvalMesh2(MGLenum mode, MGLint i1, MGLint i2, MGLint j1, MGLint j2);
	void glEvalPoint1(MGLint i);
	void glEvalPoint2(MGLint i, MGLint j);
	void glFeedbackBuffer(MGLsizei size, MGLenum type, MGLfloat *buffer);
	void glFinish(void);
	void glFlush(void);
	void glFogf(MGLenum pname, MGLfloat param);
	void glFogfv(MGLenum pname, const MGLfloat *params);
	void glFogi(MGLenum pname, MGLint param);
	void glFogiv(MGLenum pname, const MGLint *params);
	void glFrontFace(MGLenum mode);
	void glFrustum(MGLdouble left, MGLdouble right, MGLdouble bottom, MGLdouble top, MGLdouble zNear, MGLdouble zFar);
	MGLuint glGenLists(MGLsizei range);
	void glGenTextures(MGLsizei n, MGLuint *textures);
	void glGetBooleanv(MGLenum pname, MGLboolean *params);
	void glGetClipPlane(MGLenum plane, MGLdouble *equation);
	void glGetDoublev(MGLenum pname, MGLdouble *params);
	MGLenum glGetError(void);
	void glGetFloatv(MGLenum pname, MGLfloat *params);
	void glGetIntegerv(MGLenum pname, MGLint *params);
	void glGetLightfv(MGLenum light, MGLenum pname, MGLfloat *params);
	void glGetLightiv(MGLenum light, MGLenum pname, MGLint *params);
	void glGetMapdv(MGLenum target, MGLenum query, MGLdouble *v);
	void glGetMapfv(MGLenum target, MGLenum query, MGLfloat *v);
	void glGetMapiv(MGLenum target, MGLenum query, MGLint *v);
	void glGetMaterialfv(MGLenum face, MGLenum pname, MGLfloat *params);
	void glGetMaterialiv(MGLenum face, MGLenum pname, MGLint *params);
	void glGetPixelMapfv(MGLenum map, MGLfloat *values);
	void glGetPixelMapuiv(MGLenum map, MGLuint *values);
	void glGetPixelMapusv(MGLenum map, MGLushort *values);
	void glGetPointerv(MGLenum pname, MGLvoid* *params);
	void glGetPolygonStipple(MGLubyte *mask);
	const MGLubyte* glGetString(MGLenum name);
	void glGetTexEnvfv(MGLenum target, MGLenum pname, MGLfloat *params);
	void glGetTexEnviv(MGLenum target, MGLenum pname, MGLint *params);
	void glGetTexGendv(MGLenum coord, MGLenum pname, MGLdouble *params);
	void glGetTexGenfv(MGLenum coord, MGLenum pname, MGLfloat *params);
	void glGetTexGeniv(MGLenum coord, MGLenum pname, MGLint *params);
	void glGetTexImage(MGLenum target, MGLint level, MGLenum format, MGLenum type, MGLvoid *pixels);
	void glGetTexLevelParameterfv(MGLenum target, MGLint level, MGLenum pname, MGLfloat *params);
	void glGetTexLevelParameteriv(MGLenum target, MGLint level, MGLenum pname, MGLint *params);
	void glGetTexParameterfv(MGLenum target, MGLenum pname, MGLfloat *params);
	void glGetTexParameteriv(MGLenum target, MGLenum pname, MGLint *params);
	void glHint(MGLenum target, MGLenum mode);
	void glIndexMask(MGLuint mask);
	void glIndexPointer(MGLenum type, MGLsizei stride, const MGLvoid *pointer);
	void glIndexd(MGLdouble c);
	void glIndexdv(const MGLdouble *c);
	void glIndexf(MGLfloat c);
	void glIndexfv(const MGLfloat *c);
	void glIndexi(MGLint c);
	void glIndexiv(const MGLint *c);
	void glIndexs(MGLshort c);
	void glIndexsv(const MGLshort *c);
	void glIndexub(MGLubyte c);
	void glIndexubv(const MGLubyte *c);
	void glInitNames(void);
	void glInterleavedArrays(MGLenum format, MGLsizei stride, const MGLvoid *pointer);
	MGLboolean glIsEnabled(MGLenum cap);
	MGLboolean glIsList(MGLuint list);
	MGLboolean glIsTexture(MGLuint texture);
	void glLightModelf(MGLenum pname, MGLfloat param);
	void glLightModelfv(MGLenum pname, const MGLfloat *params);
	void glLightModeli(MGLenum pname, MGLint param);
	void glLightModeliv(MGLenum pname, const MGLint *params);
	void glLightf(MGLenum light, MGLenum pname, MGLfloat param);
	void glLightfv(MGLenum light, MGLenum pname, const MGLfloat *params);
	void glLighti(MGLenum light, MGLenum pname, MGLint param);
	void glLightiv(MGLenum light, MGLenum pname, const MGLint *params);
	void glLineStipple(MGLint factor, MGLushort pattern);
	void glLineWidth(MGLfloat width);
	void glListBase(MGLuint base);
	void glLoadIdentity(void);
	void glLoadMatrixd(const MGLdouble *m);
	void glLoadMatrixf(const MGLfloat *m);
	void glLoadName(MGLuint name);
	void glLogicOp(MGLenum opcode);
	void glMap1d(MGLenum target, MGLdouble u1, MGLdouble u2, MGLint stride, MGLint order, const MGLdouble *points);
	void glMap1f(MGLenum target, MGLfloat u1, MGLfloat u2, MGLint stride, MGLint order, const MGLfloat *points);
	void glMap2d(MGLenum target, MGLdouble u1, MGLdouble u2, MGLint ustride, MGLint uorder, MGLdouble v1, MGLdouble v2, MGLint vstride, MGLint vorder, const MGLdouble *points);
	void glMap2f(MGLenum target, MGLfloat u1, MGLfloat u2, MGLint ustride, MGLint uorder, MGLfloat v1, MGLfloat v2, MGLint vstride, MGLint vorder, const MGLfloat *points);
	void glMapGrid1d(MGLint un, MGLdouble u1, MGLdouble u2);
	void glMapGrid1f(MGLint un, MGLfloat u1, MGLfloat u2);
	void glMapGrid2d(MGLint un, MGLdouble u1, MGLdouble u2, MGLint vn, MGLdouble v1, MGLdouble v2);
	void glMapGrid2f(MGLint un, MGLfloat u1, MGLfloat u2, MGLint vn, MGLfloat v1, MGLfloat v2);
	void glMaterialf(MGLenum face, MGLenum pname, MGLfloat param);
	void glMaterialfv(MGLenum face, MGLenum pname, const MGLfloat *params);
	void glMateriali(MGLenum face, MGLenum pname, MGLint param);
	void glMaterialiv(MGLenum face, MGLenum pname, const MGLint *params);
	void glMatrixMode(MGLenum mode);
	void glMultMatrixd(const MGLdouble *m);
	void glMultMatrixf(const MGLfloat *m);
	void glNewList(MGLuint list, MGLenum mode);
	void glNormal3b(MGLbyte nx, MGLbyte ny, MGLbyte nz);
	void glNormal3bv(const MGLbyte *v);
	void glNormal3d(MGLdouble nx, MGLdouble ny, MGLdouble nz);
	void glNormal3dv(const MGLdouble *v);
	void glNormal3f(MGLfloat nx, MGLfloat ny, MGLfloat nz);
	void glNormal3fv(const MGLfloat *v);
	void glNormal3i(MGLint nx, MGLint ny, MGLint nz);
	void glNormal3iv(const MGLint *v);
	void glNormal3s(MGLshort nx, MGLshort ny, MGLshort nz);
	void glNormal3sv(const MGLshort *v);
	void glNormalPointer(MGLenum type, MGLsizei stride, const MGLvoid *pointer);
	void glOrtho(MGLdouble left, MGLdouble right, MGLdouble bottom, MGLdouble top, MGLdouble zNear, MGLdouble zFar);
	void glPassThrough(MGLfloat token);
	void glPixelMapfv(MGLenum map, MGLsizei mapsize, const MGLfloat *values);
	void glPixelMapuiv(MGLenum map, MGLsizei mapsize, const MGLuint *values);
	void glPixelMapusv(MGLenum map, MGLsizei mapsize, const MGLushort *values);
	void glPixelStoref(MGLenum pname, MGLfloat param);
	void glPixelStorei(MGLenum pname, MGLint param);
	void glPixelTransferf(MGLenum pname, MGLfloat param);
	void glPixelTransferi(MGLenum pname, MGLint param);
	void glPixelZoom(MGLfloat xfactor, MGLfloat yfactor);
	void glPointSize(MGLfloat size);
	void glPolygonMode(MGLenum face, MGLenum mode);
	void glPolygonOffset(MGLfloat factor, MGLfloat units);
	void glPolygonStipple(const MGLubyte *mask);
	void glPopAttrib(void);
	void glPopClientAttrib(void);
	void glPopMatrix(void);
	void glPopName(void);
	void glPrioritizeTextures(MGLsizei n, const MGLuint *textures, const MGLclampf *priorities);
	void glPushAttrib(MGLbitfield mask);
	void glPushClientAttrib(MGLbitfield mask);
	void glPushMatrix(void);
	void glPushName(MGLuint name);
	void glRasterPos2d(MGLdouble x, MGLdouble y);
	void glRasterPos2dv(const MGLdouble *v);
	void glRasterPos2f(MGLfloat x, MGLfloat y);
	void glRasterPos2fv(const MGLfloat *v);
	void glRasterPos2i(MGLint x, MGLint y);
	void glRasterPos2iv(const MGLint *v);
	void glRasterPos2s(MGLshort x, MGLshort y);
	void glRasterPos2sv(const MGLshort *v);
	void glRasterPos3d(MGLdouble x, MGLdouble y, MGLdouble z);
	void glRasterPos3dv(const MGLdouble *v);
	void glRasterPos3f(MGLfloat x, MGLfloat y, MGLfloat z);
	void glRasterPos3fv(const MGLfloat *v);
	void glRasterPos3i(MGLint x, MGLint y, MGLint z);
	void glRasterPos3iv(const MGLint *v);
	void glRasterPos3s(MGLshort x, MGLshort y, MGLshort z);
	void glRasterPos3sv(const MGLshort *v);
	void glRasterPos4d(MGLdouble x, MGLdouble y, MGLdouble z, MGLdouble w);
	void glRasterPos4dv(const MGLdouble *v);
	void glRasterPos4f(MGLfloat x, MGLfloat y, MGLfloat z, MGLfloat w);
	void glRasterPos4fv(const MGLfloat *v);
	void glRasterPos4i(MGLint x, MGLint y, MGLint z, MGLint w);
	void glRasterPos4iv(const MGLint *v);
	void glRasterPos4s(MGLshort x, MGLshort y, MGLshort z, MGLshort w);
	void glRasterPos4sv(const MGLshort *v);
	void glReadBuffer(MGLenum mode);
	void glReadPixels(MGLint x, MGLint y, MGLsizei width, MGLsizei height, MGLenum format, MGLenum type, MGLvoid *pixels);
	void glRectd(MGLdouble x1, MGLdouble y1, MGLdouble x2, MGLdouble y2);
	void glRectdv(const MGLdouble *v1, const MGLdouble *v2);
	void glRectf(MGLfloat x1, MGLfloat y1, MGLfloat x2, MGLfloat y2);
	void glRectfv(const MGLfloat *v1, const MGLfloat *v2);
	void glRecti(MGLint x1, MGLint y1, MGLint x2, MGLint y2);
	void glRectiv(const MGLint *v1, const MGLint *v2);
	void glRects(MGLshort x1, MGLshort y1, MGLshort x2, MGLshort y2);
	void glRectsv(const MGLshort *v1, const MGLshort *v2);
	MGLint glRenderMode(MGLenum mode);
	void glRotated(MGLdouble angle, MGLdouble x, MGLdouble y, MGLdouble z);
	void glRotatef(MGLfloat angle, MGLfloat x, MGLfloat y, MGLfloat z);
	void glScaled(MGLdouble x, MGLdouble y, MGLdouble z);
	void glScalef(MGLfloat x, MGLfloat y, MGLfloat z);
	void glScissor(MGLint x, MGLint y, MGLsizei width, MGLsizei height);
	void glSelectBuffer(MGLsizei size, MGLuint *buffer);
	void glShadeModel(MGLenum mode);
	void glStencilFunc(MGLenum func, MGLint ref, MGLuint mask);
	void glStencilMask(MGLuint mask);
	void glStencilOp(MGLenum fail, MGLenum zfail, MGLenum zpass);
	void glTexCoord1d(MGLdouble s);
	void glTexCoord1dv(const MGLdouble *v);
	void glTexCoord1f(MGLfloat s);
	void glTexCoord1fv(const MGLfloat *v);
	void glTexCoord1i(MGLint s);
	void glTexCoord1iv(const MGLint *v);
	void glTexCoord1s(MGLshort s);
	void glTexCoord1sv(const MGLshort *v);
	void glTexCoord2d(MGLdouble s, MGLdouble t);
	void glTexCoord2dv(const MGLdouble *v);
	void glTexCoord2f(MGLfloat s, MGLfloat t);
	void glTexCoord2fv(const MGLfloat *v);
	void glTexCoord2i(MGLint s, MGLint t);
	void glTexCoord2iv(const MGLint *v);
	void glTexCoord2s(MGLshort s, MGLshort t);
	void glTexCoord2sv(const MGLshort *v);
	void glTexCoord3d(MGLdouble s, MGLdouble t, MGLdouble r);
	void glTexCoord3dv(const MGLdouble *v);
	void glTexCoord3f(MGLfloat s, MGLfloat t, MGLfloat r);
	void glTexCoord3fv(const MGLfloat *v);
	void glTexCoord3i(MGLint s, MGLint t, MGLint r);
	void glTexCoord3iv(const MGLint *v);
	void glTexCoord3s(MGLshort s, MGLshort t, MGLshort r);
	void glTexCoord3sv(const MGLshort *v);
	void glTexCoord4d(MGLdouble s, MGLdouble t, MGLdouble r, MGLdouble q);
	void glTexCoord4dv(const MGLdouble *v);
	void glTexCoord4f(MGLfloat s, MGLfloat t, MGLfloat r, MGLfloat q);
	void glTexCoord4fv(const MGLfloat *v);
	void glTexCoord4i(MGLint s, MGLint t, MGLint r, MGLint q);
	void glTexCoord4iv(const MGLint *v);
	void glTexCoord4s(MGLshort s, MGLshort t, MGLshort r, MGLshort q);
	void glTexCoord4sv(const MGLshort *v);
	void glTexCoordPointer(MGLint size, MGLenum type, MGLsizei stride, const MGLvoid *pointer);
	void glTexEnvf(MGLenum target, MGLenum pname, MGLfloat param);
	void glTexEnvfv(MGLenum target, MGLenum pname, const MGLfloat *params);
	void glTexEnvi(MGLenum target, MGLenum pname, MGLint param);
	void glTexEnviv(MGLenum target, MGLenum pname, const MGLint *params);
	void glTexGend(MGLenum coord, MGLenum pname, MGLdouble param);
	void glTexGendv(MGLenum coord, MGLenum pname, const MGLdouble *params);
	void glTexGenf(MGLenum coord, MGLenum pname, MGLfloat param);
	void glTexGenfv(MGLenum coord, MGLenum pname, const MGLfloat *params);
	void glTexGeni(MGLenum coord, MGLenum pname, MGLint param);
	void glTexGeniv(MGLenum coord, MGLenum pname, const MGLint *params);
	void glTexImage1D(MGLenum target, MGLint level, MGLint internalformat, MGLsizei width, MGLint border, MGLenum format, MGLenum type, const MGLvoid *pixels);
	void glTexImage2D(MGLenum target, MGLint level, MGLint internalformat, MGLsizei width, MGLsizei height, MGLint border, MGLenum format, MGLenum type, const MGLvoid *pixels);
	void glTexParameterf(MGLenum target, MGLenum pname, MGLfloat param);
	void glTexParameterfv(MGLenum target, MGLenum pname, const MGLfloat *params);
	void glTexParameteri(MGLenum target, MGLenum pname, MGLint param);
	void glTexParameteriv(MGLenum target, MGLenum pname, const MGLint *params);
	void glTexSubImage1D(MGLenum target, MGLint level, MGLint xoffset, MGLsizei width, MGLenum format, MGLenum type, const MGLvoid *pixels);
	void glTexSubImage2D(MGLenum target, MGLint level, MGLint xoffset, MGLint yoffset, MGLsizei width, MGLsizei height, MGLenum format, MGLenum type, const MGLvoid *pixels);
	void glTranslated(MGLdouble x, MGLdouble y, MGLdouble z);
	void glTranslatef(MGLfloat x, MGLfloat y, MGLfloat z);
	void glVertex2d(MGLdouble x, MGLdouble y);
	void glVertex2dv(const MGLdouble *v);
	void glVertex2f(MGLfloat x, MGLfloat y);
	void glVertex2fv(const MGLfloat *v);
	void glVertex2i(MGLint x, MGLint y);
	void glVertex2iv(const MGLint *v);
	void glVertex2s(MGLshort x, MGLshort y);
	void glVertex2sv(const MGLshort *v);
	void glVertex3d(MGLdouble x, MGLdouble y, MGLdouble z);
	void glVertex3dv(const MGLdouble *v);
	void glVertex3f(MGLfloat x, MGLfloat y, MGLfloat z);
	void glVertex3fv(const MGLfloat *v);
	void glVertex3i(MGLint x, MGLint y, MGLint z);
	void glVertex3iv(const MGLint *v);
	void glVertex3s(MGLshort x, MGLshort y, MGLshort z);
	void glVertex3sv(const MGLshort *v);
	void glVertex4d(MGLdouble x, MGLdouble y, MGLdouble z, MGLdouble w);
	void glVertex4dv(const MGLdouble *v);
	void glVertex4f(MGLfloat x, MGLfloat y, MGLfloat z, MGLfloat w);
	void glVertex4fv(const MGLfloat *v);
	void glVertex4i(MGLint x, MGLint y, MGLint z, MGLint w);
	void glVertex4iv(const MGLint *v);
	void glVertex4s(MGLshort x, MGLshort y, MGLshort z, MGLshort w);
	void glVertex4sv(const MGLshort *v);
	void glVertexPointer(MGLint size, MGLenum type, MGLsizei stride, const MGLvoid *pointer);
	void glViewport(MGLint x, MGLint y, MGLsizei width, MGLsizei height);

	//---------------------------------------------------------------
	//
	//		CORE MGL EXTENSIONS
	//		Version 1.2
	//
	//---------------------------------------------------------------

	// draw_range_elements
	void glDrawRangeElements(MGLenum mode, MGLuint start, MGLuint end, MGLsizei count, MGLenum type, const MGLvoid *indices);

	// texture3D
	void glTexImage3D(MGLenum target, MGLint level, MGLenum internalformat, MGLsizei width, MGLsizei height, MGLsizei depth, MGLint border, MGLenum format, MGLenum type, const MGLvoid *pixels);
	void glTexSubImage3D(MGLenum target, MGLint level, MGLint xoffset, MGLint yoffset, MGLint zoffset, MGLsizei width, MGLsizei height, MGLsizei depth, MGLenum format, MGLenum type, const MGLvoid *pixels);
	void glCopyTexSubImage3D(MGLenum target, MGLint level, MGLint xoffset, MGLint yoffset, MGLint zoffset, MGLint x, MGLint y, MGLsizei width, MGLsizei height);



	//---------------------------------------------------------------
	//
	//		CORE MGL EXTENSIONS
	//		Version 1.2.1
	//
	//---------------------------------------------------------------

	// multitexture
	void glMultiTexCoord1d(MGLenum target, MGLdouble s);
	void glMultiTexCoord1dv(MGLenum target, const MGLdouble *v);
	void glMultiTexCoord1f(MGLenum target, MGLfloat s);
	void glMultiTexCoord1fv(MGLenum target, const MGLfloat *v);
	void glMultiTexCoord1i(MGLenum target, MGLint s);
	void glMultiTexCoord1iv(MGLenum target, const MGLint *v);
	void glMultiTexCoord1s(MGLenum target, MGLshort s);
	void glMultiTexCoord1sv(MGLenum target, const MGLshort *v);
	void glMultiTexCoord2d(MGLenum target, MGLdouble s, MGLdouble t);
	void glMultiTexCoord2dv(MGLenum target, const MGLdouble *v);
	void glMultiTexCoord2f(MGLenum target, MGLfloat s, MGLfloat t);
	void glMultiTexCoord2fv(MGLenum target, const MGLfloat *v);
	void glMultiTexCoord2i(MGLenum target, MGLint s, MGLint t);
	void glMultiTexCoord2iv(MGLenum target, const MGLint *v);
	void glMultiTexCoord2s(MGLenum target, MGLshort s, MGLshort t);
	void glMultiTexCoord2sv(MGLenum target, const MGLshort *v);
	void glMultiTexCoord3d(MGLenum target, MGLdouble s, MGLdouble t, MGLdouble r);
	void glMultiTexCoord3dv(MGLenum target, const MGLdouble *v);
	void glMultiTexCoord3f(MGLenum target, MGLfloat s, MGLfloat t, MGLfloat r);
	void glMultiTexCoord3fv(MGLenum target, const MGLfloat *v);
	void glMultiTexCoord3i(MGLenum target, MGLint s, MGLint t, MGLint r);
	void glMultiTexCoord3iv(MGLenum target, const MGLint *v);
	void glMultiTexCoord3s(MGLenum target, MGLshort s, MGLshort t, MGLshort r);
	void glMultiTexCoord3sv(MGLenum target, const MGLshort *v);
	void glMultiTexCoord4d(MGLenum target, MGLdouble s, MGLdouble t, MGLdouble r, MGLdouble q);
	void glMultiTexCoord4dv(MGLenum target, const MGLdouble *v);
	void glMultiTexCoord4f(MGLenum target, MGLfloat s, MGLfloat t, MGLfloat r, MGLfloat q);
	void glMultiTexCoord4fv(MGLenum target, const MGLfloat *v);
	void glMultiTexCoord4i(MGLenum target, MGLint s, MGLint t, MGLint r, MGLint q);
	void glMultiTexCoord4iv(MGLenum target, const MGLint *v);
	void glMultiTexCoord4s(MGLenum target, MGLshort s, MGLshort t, MGLshort r, MGLshort q);
	void glMultiTexCoord4sv(MGLenum target, const MGLshort *v);
	void glActiveTexture(MGLenum target);
	void glClientActiveTexture(MGLenum target);

	//---------------------------------------------------------------
	//
	//		CORE MGL EXTENSIONS
	//		Version 1.3
	//
	//---------------------------------------------------------------

	// texture_compression
	void glCompressedTexImage1D(MGLenum target, MGLint level, MGLenum internalformat, MGLsizei width, MGLint border, MGLsizei imageSize, const void *data);
	void glCompressedTexImage2D(MGLenum target, MGLint level, MGLenum internalformat, MGLsizei width, MGLsizei height, MGLint border, MGLsizei imageSize, const void *data);
	void glCompressedTexImage3D(MGLenum target, MGLint level, MGLenum internalformat, MGLsizei width, MGLsizei height, MGLsizei depth, MGLint border, MGLsizei imageSize, const void *data);
	void glCompressedTexSubImage1D(MGLenum target, MGLint level, MGLint xoffset, MGLsizei width, MGLenum format, MGLsizei imageSize, const void *data);
	void glCompressedTexSubImage2D(MGLenum target, MGLint level, MGLint xoffset, MGLint yoffset, MGLsizei width, MGLsizei height, MGLenum format, MGLsizei imageSize, const void *data);
	void glCompressedTexSubImage3D(MGLenum target, MGLint level, MGLint xoffset, MGLint yoffset, MGLint zoffset, MGLsizei width, MGLsizei height, MGLsizei depth, MGLenum format, MGLsizei imageSize, const void *data);
	void glGetCompressedTexImage(MGLenum target, MGLint lod, void *img);

	// transpose_matrix
	void glLoadTransposeMatrixf(const MGLfloat m[16]);
	void glLoadTransposeMatrixd(const MGLdouble m[16]);
	void glMultTransposeMatrixf(const MGLfloat m[16]);
	void glMultTransposeMatrixd(const MGLdouble m[16]);

	//---------------------------------------------------------------
	//
	//		CORE MGL EXTENSIONS
	//		Version 1.4
	//
	//---------------------------------------------------------------
	// Multi draw arrays
	void glMultiDrawArrays(MGLenum, MGLint *, MGLsizei *, MGLsizei);
	void glMultiDrawElements(MGLenum, const MGLsizei *, MGLenum, const MGLvoid* *, MGLsizei);

	//---------------------------------------------------------------
	//
	//		OPTIONAL ARB EXTENSIONS (alphabetical extension name order)
	//
	//---------------------------------------------------------------

	// blend_minmax
	void glBlendEquationEXT(MGLenum mode);

	// ARB_point_parameters
	void glPointParameterf(MGLenum pname, MGLfloat param);
	void glPointParameterfv(MGLenum pname, const MGLfloat *params);

	// ARB_transpose_matrix
    void glLoadTransposeMatrixfARB(const MGLfloat *m);
    void glLoadTransposeMatrixdARB(const MGLdouble *m);
    void glMultTransposeMatrixfARB(const MGLfloat *m);
    void glMultTransposeMatrixdARB(const MGLdouble *m);

	// ARB_vertex_program
	void glVertexAttrib1s(MGLuint index, MGLshort x);
    void glVertexAttrib1f(MGLuint index, MGLfloat x);
    void glVertexAttrib1d(MGLuint index, MGLdouble x);
    void glVertexAttrib2s(MGLuint index, MGLshort x, MGLshort y);
    void glVertexAttrib2f(MGLuint index, MGLfloat x, MGLfloat y);
    void glVertexAttrib2d(MGLuint index, MGLdouble x, MGLdouble y);
    void glVertexAttrib3s(MGLuint index, MGLshort x, MGLshort y, MGLshort z);
    void glVertexAttrib3f(MGLuint index, MGLfloat x, MGLfloat y, MGLfloat z);
    void glVertexAttrib3d(MGLuint index, MGLdouble x, MGLdouble y, MGLdouble z);
    void glVertexAttrib4s(MGLuint index, MGLshort x, MGLshort y, MGLshort z, MGLshort w);
    void glVertexAttrib4f(MGLuint index, MGLfloat x, MGLfloat y, MGLfloat z, MGLfloat w);
    void glVertexAttrib4d(MGLuint index, MGLdouble x, MGLdouble y, MGLdouble z, MGLdouble w);
    void glVertexAttrib4Nub(MGLuint index, MGLubyte x, MGLubyte y, MGLubyte z, MGLubyte w);
    void glVertexAttrib1sv(MGLuint index, const MGLshort *v);
    void glVertexAttrib1fv(MGLuint index, const MGLfloat *v);
    void glVertexAttrib1dv(MGLuint index, const MGLdouble *v);
    void glVertexAttrib2sv(MGLuint index, const MGLshort *v);
    void glVertexAttrib2fv(MGLuint index, const MGLfloat *v);
    void glVertexAttrib2dv(MGLuint index, const MGLdouble *v);
    void glVertexAttrib3sv(MGLuint index, const MGLshort *v);
    void glVertexAttrib3fv(MGLuint index, const MGLfloat *v);
    void glVertexAttrib3dv(MGLuint index, const MGLdouble *v);
    void glVertexAttrib4bv(MGLuint index, const MGLbyte *v);
    void glVertexAttrib4sv(MGLuint index, const MGLshort *v);
    void glVertexAttrib4iv(MGLuint index, const MGLint *v);
    void glVertexAttrib4ubv(MGLuint index, const MGLubyte *v);
    void glVertexAttrib4usv(MGLuint index, const MGLushort *v);
    void glVertexAttrib4uiv(MGLuint index, const MGLuint *v);
    void glVertexAttrib4fv(MGLuint index, const MGLfloat *v);
    void glVertexAttrib4dv(MGLuint index, const MGLdouble *v);
    void glVertexAttrib4Nbv(MGLuint index, const MGLbyte *v);
    void glVertexAttrib4Nsv(MGLuint index, const MGLshort *v);
    void glVertexAttrib4Niv(MGLuint index, const MGLint *v);
    void glVertexAttrib4Nubv(MGLuint index, const MGLubyte *v);
    void glVertexAttrib4Nusv(MGLuint index, const MGLushort *v);
    void glVertexAttrib4Nuiv(MGLuint index, const MGLuint *v);
    void glVertexAttribPointer(MGLuint index, MGLint size, MGLenum type, MGLboolean normalized, MGLsizei stride, const void *pointer);
    void glEnableVertexAttribArray(MGLuint index);
    void glDisableVertexAttribArray(MGLuint index);
    void glProgramString(MGLenum target, MGLenum format, MGLsizei len, const void *string);
    void glBindProgram(MGLenum target, MGLuint program);
    void glDeletePrograms(MGLsizei n, const MGLuint *programs);
    void glGenPrograms(MGLsizei n, MGLuint *programs);
    void glProgramEnvParameter4d(MGLenum target, MGLuint index, MGLdouble x, MGLdouble y, MGLdouble z, MGLdouble w);
    void glProgramEnvParameter4dv(MGLenum target, MGLuint index, const MGLdouble *params);
    void glProgramEnvParameter4f(MGLenum target, MGLuint index, MGLfloat x, MGLfloat y, MGLfloat z, MGLfloat w);
    void glProgramEnvParameter4fv(MGLenum target, MGLuint index, const MGLfloat *params);
    void glProgramLocalParameter4d(MGLenum target, MGLuint index, MGLdouble x, MGLdouble y, MGLdouble z, MGLdouble w);
    void glProgramLocalParameter4dv(MGLenum target, MGLuint index, const MGLdouble *params);
    void glProgramLocalParameter4f(MGLenum target, MGLuint index, MGLfloat x, MGLfloat y, MGLfloat z, MGLfloat w);
    void glProgramLocalParameter4fv(MGLenum target, MGLuint index, const MGLfloat *params);
    void glGetProgramEnvParameterdv(MGLenum target, MGLuint index, MGLdouble *params);
    void glGetProgramEnvParameterfv(MGLenum target, MGLuint index, MGLfloat *params);
    void glGetProgramLocalParameterdv(MGLenum target, MGLuint index, MGLdouble *params);
    void glGetProgramLocalParameterfv(MGLenum target, MGLuint index, MGLfloat *params);
    void glGetProgramiv(MGLenum target, MGLenum pname, MGLint *params);
    void glGetProgramString(MGLenum target, MGLenum pname, void *string);
    void glGetVertexAttribdv(MGLuint index, MGLenum pname, MGLdouble *params);
    void glGetVertexAttribfv(MGLuint index, MGLenum pname, MGLfloat *params);
    void glGetVertexAttribiv(MGLuint index, MGLenum pname, MGLint *params);
    void glGetVertexAttribPointerv(MGLuint index, MGLenum pname, void **pointer);
    MGLboolean glIsProgram(MGLuint program);


	// ATI_fragment_shader
	MGLuint glGenFragmentShadersATI(MGLuint range);
    void glBindFragmentShaderATI(MGLuint id);
    void glDeleteFragmentShaderATI(MGLuint id);
    void glBeginFragmentShaderATI();
    void glEndFragmentShaderATI();
    void glPassTexCoordATI(MGLuint dst, MGLuint coord, MGLenum swizzle);
    void glSampleMapATI(MGLuint dst, MGLuint interp, MGLenum swizzle);
    void glColorFragmentOp1ATI(MGLenum op, MGLuint dst, MGLuint dstMask, MGLuint dstMod, MGLuint arg1, MGLuint arg1Rep, MGLuint arg1Mod);
    void glColorFragmentOp2ATI(MGLenum op, MGLuint dst, MGLuint dstMask, MGLuint dstMod, MGLuint arg1, MGLuint arg1Rep, MGLuint arg1Mod, MGLuint arg2, MGLuint arg2Rep, MGLuint arg2Mod);
    void glColorFragmentOp3ATI(MGLenum op, MGLuint dst, MGLuint dstMask, MGLuint dstMod, MGLuint arg1, MGLuint arg1Rep, MGLuint arg1Mod, MGLuint arg2, MGLuint arg2Rep, MGLuint arg2Mod, MGLuint arg3, MGLuint arg3Rep, MGLuint arg3Mod);
    void glAlphaFragmentOp1ATI(MGLenum op, MGLuint dst, MGLuint dstMod, MGLuint arg1, MGLuint arg1Rep, MGLuint arg1Mod);
    void glAlphaFragmentOp2ATI(MGLenum op, MGLuint dst, MGLuint dstMod, MGLuint arg1, MGLuint arg1Rep, MGLuint arg1Mod, MGLuint arg2, MGLuint arg2Rep, MGLuint arg2Mod);
	void glAlphaFragmentOp3ATI(MGLenum op, MGLuint dst, MGLuint dstMod, MGLuint arg1, MGLuint arg1Rep, MGLuint arg1Mod, MGLuint arg2, MGLuint arg2Rep, MGLuint arg2Mod, MGLuint arg3, MGLuint arg3Rep, MGLuint arg3Mod);
    void glSetFragmentShaderConstantATI(MGLuint dst, const float *value);

#ifndef SDK_10_8
	// ATI_pn_triangles
	void glPNTrianglesiATI(MGLenum pname, MGLint param);
	void glPNTrianglesfATI(MGLenum pname, MGLfloat param);
#endif

	// EXT_compiled_vertex_array
	void glLockArraysEXT(MGLint first, MGLsizei count);
	void glUnlockArraysEXT(void);

	// EXT_cull_vertex
	void glCullParameterdvEXT(MGLenum pname, MGLdouble *params);
	void glCullParameterfvEXT(MGLenum pname, MGLfloat *params);

	// EXT_secondary_color
	void glSecondaryColor3bEXT(MGLbyte red, MGLbyte green, MGLbyte blue);
	void glSecondaryColor3bvEXT(const MGLbyte *components);
	void glSecondaryColor3dEXT(MGLdouble red, MGLdouble green, MGLdouble blue);
	void glSecondaryColor3dvEXT(const MGLdouble *components);
	void glSecondaryColor3fEXT(MGLfloat red, MGLfloat green, MGLfloat blue);
	void glSecondaryColor3fvEXT(const MGLfloat *components);
	void glSecondaryColor3iEXT(MGLint red, MGLint green, MGLint blue);
	void glSecondaryColor3ivEXT(const MGLint *components);
	void glSecondaryColor3sEXT(MGLshort red, MGLshort green, MGLshort blue);
	void glSecondaryColor3svEXT(const MGLshort *components);
	void glSecondaryColor3ubEXT(MGLubyte red, MGLubyte green, MGLubyte blue);
	void glSecondaryColor3ubvEXT(const MGLubyte *components);
	void glSecondaryColor3uiEXT(MGLuint red, MGLuint green, MGLuint blue);
	void glSecondaryColor3uivEXT(const MGLuint *components);
	void glSecondaryColor3usEXT(MGLushort red, MGLushort green, MGLushort blue);
	void glSecondaryColor3usvEXT(const MGLushort *components);
	void glSecondaryColorPointerEXT(MGLint size, MGLenum type, MGLsizei stride, MGLvoid *pointer);

	// EXT_fog_coord
	void glFogCoordfEXT(MGLfloat coord);
	void glFogCoordfvEXT(const MGLfloat *coord);
	void glFogCoorddEXT(MGLdouble coord);
	void glFogCoorddvEXT(const MGLdouble *coord);
	void glFogCoordPointerEXT(MGLenum type, MGLsizei stride, const MGLvoid *pointer);

	// EXT_vertex_shader (supported by ATI, Apple, Matrox, 3DLabs)
	void glBeginVertexShaderEXT();
    void glEndVertexShaderEXT();
    void glBindVertexShaderEXT(MGLuint id);
    MGLuint glGenVertexShadersEXT(MGLuint range);
    void glDeleteVertexShaderEXT(MGLuint id);
    void glShaderOp1EXT(MGLenum op, MGLuint res, MGLuint arg1);
    void glShaderOp2EXT(MGLenum op, MGLuint res, MGLuint arg1, MGLuint arg2);
    void glShaderOp3EXT(MGLenum op, MGLuint res, MGLuint arg1, MGLuint arg2, MGLuint arg3);
    void glSwizzleEXT(MGLuint res, MGLuint in, MGLenum outX, MGLenum outY, MGLenum outZ, MGLenum outW);
    void glWriteMaskEXT(MGLuint res, MGLuint in, MGLenum outX, MGLenum outY, MGLenum outZ, MGLenum outW);
    void glInsertComponentEXT(MGLuint res, MGLuint src, MGLuint num);
    void glExtractComponentEXT(MGLuint res, MGLuint src, MGLuint num);
    MGLuint glGenSymbolsEXT(MGLenum datatype, MGLenum storagetype, MGLenum range, MGLuint components);
	void glSetInvariantEXT(MGLuint id, MGLenum type, void *addr);
    void glSetLocalConstantEXT(MGLuint id, MGLenum type, void *addr);
    void glVariantbvEXT(MGLuint id, MGLbyte *addr);
    void glVariantsvEXT(MGLuint id, MGLshort *addr);
    void glVariantivEXT(MGLuint id, MGLint *addr);
    void glVariantfvEXT(MGLuint id, MGLfloat *addr);
    void glVariantdvEXT(MGLuint id, MGLdouble *addr);
    void glVariantubvEXT(MGLuint id, MGLubyte *addr);
    void glVariantusvEXT(MGLuint id, MGLushort *addr);
    void glVariantuivEXT(MGLuint id, MGLuint *addr);
    void glVariantPointerEXT(MGLuint id, MGLenum type, MGLuint stride, void *addr);
    void glEnableVariantClientStateEXT(MGLuint id);
    void glDisableVariantClientStateEXT(MGLuint id);
    MGLuint glBindLightParameterEXT(MGLenum light, MGLenum value);
    MGLuint glBindMaterialParameterEXT(MGLenum face, MGLenum value);
    MGLuint glBindTexGenParameterEXT(MGLenum unit, MGLenum coord, MGLenum value);
    MGLuint glBindTextureUnitParameterEXT(MGLenum unit, MGLenum value);
    MGLuint glBindParameterEXT(MGLenum value);
    MGLboolean glIsVariantEnabledEXT(MGLuint id, MGLenum cap);
    void glGetVariantBooleanvEXT(MGLuint id, MGLenum value, MGLboolean *data);
    void glGetVariantIntegervEXT(MGLuint id, MGLenum value, MGLint *data);
    void glGetVariantFloatvEXT(MGLuint id, MGLenum value, MGLfloat *data);
    void glGetVariantPointervEXT(MGLuint id, MGLenum value, void **data);
    void glGetInvariantBooleanvEXT(MGLuint id, MGLenum value, MGLboolean *data);
    void glGetInvariantIntegervEXT(MGLuint id, MGLenum value, MGLint *data);
    void glGetInvariantFloatvEXT(MGLuint id, MGLenum value, MGLfloat *data);
    void glGetLocalConstantBooleanvEXT(MGLuint id, MGLenum value, MGLboolean *data);
    void glGetLocalConstantIntegervEXT(MGLuint id, MGLenum value, MGLint *data);
    void glGetLocalConstantFloatvEXT(MGLuint id, MGLenum value, MGLfloat *data);

	// EXT_vertex_weighting
    void glVertexWeightfEXT(MGLfloat weight);
    void glVertexWeightfvEXT(MGLfloat *weight);
    void glVertexWeightPointerEXT(MGLint size, MGLenum type, MGLsizei stride, MGLvoid *pointer);

	// NV_vertex_array_range
	void glFlushVertexArrayRangeNV();
	void glVertexArrayRangeNV(MGLsizei length, const MGLvoid *pointer);

	// NV_vertex_program
	void glBindProgramNV(MGLenum target, MGLuint id);
	void glDeleteProgramsNV(MGLsizei n, const MGLuint *ids);
	void glExecuteProgramNV(MGLenum target,MGLuint id, const MGLfloat *params);
	void glGenProgramsNV(MGLsizei n, MGLuint *ids);
	MGLboolean glAreProgramsResidentNV(MGLsizei n, const MGLuint *ids, MGLboolean *residences);
	void glRequestResidentProgramsNV(MGLsizei n, const MGLuint *ids);
	void glGetProgramParameterfvNV(MGLenum target, MGLuint index, MGLenum pname, MGLfloat *params);
	void glGetProgramParameterdvNV(MGLenum target, MGLuint index, MGLenum pname, MGLdouble *params);
	void glGetProgramivNV(MGLuint id, MGLenum pname, MGLint *params);
	void glGetProgramStringNV(MGLuint id, MGLenum pname, MGLubyte *program);
	void glGetTrackMatrixivNV(MGLenum target, MGLuint address, MGLenum pname, int *params);
	void glGetVertexAttribdvNV(MGLuint index, MGLenum pname, MGLdouble *params);
	void glGetVertexAttribfvNV(MGLuint index, MGLenum pname, MGLfloat *params);
	void glGetVertexAttribivNV(MGLuint index, MGLenum pname, MGLint *params);
	void glGetVertexAttribPointervNV(MGLuint index, MGLenum pname, void **pointer);
	MGLboolean glIsProgramNV(MGLuint id);
	void glLoadProgramNV(MGLenum target, MGLuint id, MGLsizei len, const MGLubyte *program);
	void glProgramParameter4fNV(MGLenum target, MGLuint index, MGLfloat x, MGLfloat y, MGLfloat z, MGLfloat w);
	void glProgramParameter4dNV(MGLenum target, MGLuint index, MGLdouble x, MGLdouble y, MGLdouble z, MGLdouble w);
	void glProgramParameter4dvNV(MGLenum target, MGLuint index, const MGLdouble *params);
	void glProgramParameter4fvNV(MGLenum target, MGLuint index, const MGLfloat *params);
	void glProgramParameters4dvNV(MGLenum target, MGLuint index, MGLsizei count, const MGLdouble *params);
	void glProgramParameters4fvNV(MGLenum target, MGLuint index, MGLsizei count, const MGLfloat *params);
	void glTrackMatrixNV(MGLenum target, MGLuint address, MGLenum matrix, MGLenum transform);
	void glVertexAttribPointerNV(MGLuint index, MGLint sizei, MGLenum type, MGLsizei stride, const void *pointer);
	void glVertexAttrib1sNV(MGLuint index, MGLshort x);
	void glVertexAttrib1fNV(MGLuint index, MGLfloat x);
	void glVertexAttrib1dNV(MGLuint index, MGLdouble x);
	void glVertexAttrib2sNV(MGLuint index, MGLshort x, MGLshort y);
	void glVertexAttrib2fNV(MGLuint index, MGLfloat x, MGLfloat y);
	void glVertexAttrib2dNV(MGLuint index, MGLdouble x, MGLdouble y);
	void glVertexAttrib3sNV(MGLuint index, MGLshort x, MGLshort y, MGLshort z);
	void glVertexAttrib3fNV(MGLuint index, MGLfloat x, MGLfloat y, MGLfloat z);
	void glVertexAttrib3dNV(MGLuint index, MGLdouble x, MGLdouble y, MGLdouble z);
	void glVertexAttrib4sNV(MGLuint index, MGLshort x, MGLshort y, MGLshort z, MGLshort w);
	void glVertexAttrib4fNV(MGLuint index, MGLfloat x, MGLfloat y, MGLfloat z, MGLfloat w);
	void glVertexAttrib4dNV(MGLuint index, MGLdouble x, MGLdouble y, MGLdouble z, MGLdouble w);
	void glVertexAttrib4ubNV(MGLuint index, MGLubyte x, MGLubyte y, MGLubyte z, MGLubyte w);
	void glVertexAttrib1svNV(MGLuint index, const MGLshort *v);
	void glVertexAttrib1fvNV(MGLuint index, const MGLfloat *v);
	void glVertexAttrib1dvNV(MGLuint index, const MGLdouble *v);
	void glVertexAttrib2svNV(MGLuint index, const MGLshort *v);
	void glVertexAttrib2fvNV(MGLuint index, const MGLfloat *v);
	void glVertexAttrib2dvNV(MGLuint index, const MGLdouble *v);
	void glVertexAttrib3svNV(MGLuint index, const MGLshort *v);
	void glVertexAttrib3fvNV(MGLuint index, const MGLfloat *v);
	void glVertexAttrib3dvNV(MGLuint index, const MGLdouble *v);
	void glVertexAttrib4svNV(MGLuint index, const MGLshort *v);
	void glVertexAttrib4fvNV(MGLuint index, const MGLfloat *v);
	void glVertexAttrib4dvNV(MGLuint index, const MGLdouble *v);
	void glVertexAttrib4ubvNV(MGLuint index, const MGLubyte *v);
	void glVertexAttribs1svNV(MGLuint index, MGLsizei n, const MGLshort *v);
	void glVertexAttribs1fvNV(MGLuint index, MGLsizei n, const MGLfloat *v);
	void glVertexAttribs1dvNV(MGLuint index, MGLsizei n, const MGLdouble *v);
	void glVertexAttribs2svNV(MGLuint index, MGLsizei n, const MGLshort *v);
	void glVertexAttribs2fvNV(MGLuint index, MGLsizei n, const MGLfloat *v);
	void glVertexAttribs2dvNV(MGLuint index, MGLsizei n, const MGLdouble *v);
	void glVertexAttribs3svNV(MGLuint index, MGLsizei n, const MGLshort *v);
	void glVertexAttribs3fvNV(MGLuint index, MGLsizei n, const MGLfloat *v);
	void glVertexAttribs3dvNV(MGLuint index, MGLsizei n, const MGLdouble *v);
	void glVertexAttribs4svNV(MGLuint index, MGLsizei n, const MGLshort *v);
	void glVertexAttribs4fvNV(MGLuint index, MGLsizei n, const MGLfloat *v);
	void glVertexAttribs4dvNV(MGLuint index, MGLsizei n, const MGLdouble *v);
	void glVertexAttribs4ubvNV(MGLuint index, MGLsizei n, const MGLubyte *v);

	// NV_fence
	void glGenFencesNV(MGLsizei n, MGLuint *fences);
	void glDeleteFencesNV(MGLsizei n, const MGLuint *fences);
	void glSetFenceNV(MGLuint fence, MGLenum condition);
	MGLboolean glTestFenceNV(MGLuint fence);
	void glFinishFenceNV(MGLuint fence);
	MGLboolean glIsFenceNV(MGLuint fence);
	void glGetFenceivNV(MGLuint fence, MGLenum pname, MGLint *params);

	// NV_register_combiners
	void glCombinerParameterfvNV(MGLenum pname, const MGLfloat *params);
	void glCombinerParameterfNV(MGLenum pname, MGLfloat param);
	void glCombinerParameterivNV(MGLenum pname, const MGLint *params);
	void glCombinerParameteriNV(MGLenum pname, MGLint param);
	void glCombinerInputNV(MGLenum stage, MGLenum portion, MGLenum variable, MGLenum input, MGLenum mapping, MGLenum componentUsage);
	void glCombinerOutputNV(MGLenum stage, MGLenum portion, MGLenum abOutput, MGLenum cdOutput, MGLenum sumOutput, MGLenum scale, MGLenum bias, MGLboolean abDotProduct, MGLboolean cdDotProduct, MGLboolean muxSum);
	void glFinalCombinerInputNV(MGLenum variable, MGLenum input, MGLenum mapping, MGLenum componentUsage);
	void glGetCombinerInputParameterfvNV(MGLenum stage, MGLenum portion, MGLenum variable, MGLenum pname, MGLfloat *params);
	void glGetCombinerInputParameterivNV(MGLenum stage, MGLenum portion, MGLenum variable, MGLenum pname, MGLint *params);
	void glGetCombinerOutputParameterfvNV(MGLenum stage, MGLenum portion, MGLenum pname, MGLfloat *params);
	void glGetCombinerOutputParameterivNV(MGLenum stage, MGLenum portion, MGLenum pname, MGLint *params);
	void glGetFinalCombinerInputParameterfvNV(MGLenum variable, MGLenum pname, MGLfloat *params);
	void glGetFinalCombinerInputParameterivNV(MGLenum variable, MGLenum pname, MGLint *params);

	// NV_occlusion_query
	void glGenOcclusionQueriesNV(MGLsizei n, MGLuint *ids);
	void glDeleteOcclusionQueriesNV(MGLsizei n, const MGLuint *ids);
	void glIsOcclusionQueryNV(MGLuint id);
	void glBeginOcclusionQueryNV(MGLuint id);
	void glEndOcclusionQueryNV(void);
	void glGetOcclusionQueryivNV(MGLuint id, MGLenum pname, MGLint *params);
	void glGetOcclusionQueryuivNV(MGLuint id, MGLenum pname, MGLuint *params);

	// NV_primitive_restart
	void glPrimitiveRestartNV(void);
	void glPrimitiveRestartIndexNV(MGLuint index);

	// ARB_occlusion_query
	void glGenQueriesARB (MGLsizei n, MGLuint *ids);
    void glDeleteQueriesARB (MGLsizei n, const MGLuint *ids);
    MGLboolean glIsQueryARB (MGLuint id);
    void glBeginQueryARB (MGLenum target, MGLuint id);
    void glEndQueryARB (MGLenum target);
    void glGetQueryivARB (MGLenum target, MGLenum pname, MGLint *params);
    void glGetQueryObjectivARB (MGLuint id, MGLenum pname, MGLint *params);
    void glGetQueryObjectuivARB (MGLuint id, MGLenum pname, MGLuint *params);

	// ARB_vertex_buffer_object
	void  glBindBufferARB(MGLenum target, MGLuint buffer);
	void  glDeleteBuffersARB(MGLsizei n, const MGLuint *buffers);
	void  glGenBuffersARB(MGLsizei n, MGLuint *buffers);
	MGLboolean  glIsBufferARB(MGLuint buffer);
	bool  glBufferDataARB(MGLenum target, MGLsizeiptrARB size, const MGLvoid *data, MGLenum usage);
	bool  glBufferSubDataARB(MGLenum target, MGLintptrARB offset, MGLsizeiptrARB size, const MGLvoid *data);
	void  glGetBufferSubDataARB(MGLenum target, MGLintptrARB offset, MGLsizeiptrARB size, MGLvoid *data);
	void*  glMapBufferARB(MGLenum target, MGLenum access);
	MGLboolean  glUnmapBufferARB(MGLenum target);
	void  glGetBufferParameterivARB(MGLenum target, MGLenum pname, MGLint *params);
	void  glGetBufferPointervARB(MGLenum target, MGLenum pname, MGLvoid **params);


	// OpenGL 2.0 API
	//
	void glDeleteObjectARB(MGLhandleARB obj);
	MGLhandleARB glGetHandleARB(MGLenum pname);
	void glDetachObjectARB(MGLhandleARB containerObj, MGLhandleARB attachedObj);
	MGLhandleARB glCreateShaderObjectARB(MGLenum shaderType);
	void glShaderSourceARB(MGLhandleARB shaderObj, MGLsizei count, const MGLcharARB **string, const MGLint *length);
	void glCompileShaderARB(MGLhandleARB shaderObj);
	MGLhandleARB glCreateProgramObjectARB(void);
	void glAttachObjectARB(MGLhandleARB containerObj, MGLhandleARB obj);
	void glLinkProgramARB(MGLhandleARB programObj);
	void glUseProgramObjectARB(MGLhandleARB programObj);
	void glValidateProgramARB(MGLhandleARB programObj);
	void glUniform1fARB(MGLint location, MGLfloat v0);
	void glUniform2fARB(MGLint location, MGLfloat v0, MGLfloat v1);
	void glUniform3fARB(MGLint location, MGLfloat v0, MGLfloat v1, MGLfloat v2);
	void glUniform4fARB(MGLint location, MGLfloat v0, MGLfloat v1, MGLfloat v2, MGLfloat v3);
	void glUniform1iARB(MGLint location, MGLint v0);
	void glUniform2iARB(MGLint location, MGLint v0, MGLint v1);
	void glUniform3iARB(MGLint location, MGLint v0, MGLint v1, MGLint v2);
	void glUniform4iARB(MGLint location, MGLint v0, MGLint v1, MGLint v2, MGLint v3);
	void glUniform1fvARB(MGLint location, MGLsizei count, MGLfloat *value);
	void glUniform2fvARB(MGLint location, MGLsizei count, MGLfloat *value);
	void glUniform3fvARB(MGLint location, MGLsizei count, MGLfloat *value);
	void glUniform4fvARB(MGLint location, MGLsizei count, MGLfloat *value);
	void glUniform1ivARB(MGLint location, MGLsizei count, MGLint *value);
	void glUniform2ivARB(MGLint location, MGLsizei count, MGLint *value);
	void glUniform3ivARB(MGLint location, MGLsizei count, MGLint *value);
	void glUniform4ivARB(MGLint location, MGLsizei count, MGLint *value);
	void glUniformMatrix2fvARB(MGLint location, MGLsizei count, MGLboolean transpose, MGLfloat *value);
	void glUniformMatrix3fvARB(MGLint location, MGLsizei count, MGLboolean transpose, MGLfloat *value);
	void glUniformMatrix4fvARB(MGLint location, MGLsizei count, MGLboolean transpose, MGLfloat *value);
	void glGetObjectParameterfvARB(MGLhandleARB obj, MGLenum pname, MGLfloat *params);
	void glGetObjectParameterivARB(MGLhandleARB obj, MGLenum pname, MGLint *params);
	void glGetInfoLogARB(MGLhandleARB obj, MGLsizei maxLength, MGLsizei *length, MGLcharARB *infoLog);
	void glGetAttachedObjectsARB(MGLhandleARB containerObj, MGLsizei maxCount, MGLsizei *count, MGLhandleARB *obj);
	MGLint glGetUniformLocationARB(MGLhandleARB programObj, const MGLcharARB *name);
	void glGetActiveUniformARB(MGLhandleARB programObj, MGLuint index, MGLsizei maxLength, MGLsizei *length, MGLint *size, MGLenum *type, MGLcharARB *name);
	void glGetUniformfvARB(MGLhandleARB programObj, MGLint location, MGLfloat *params);
	void glGetUniformivARB(MGLhandleARB programObj, MGLint location, MGLint *params);
	void glGetShaderSourceARB(MGLhandleARB obj, MGLsizei maxLength, MGLsizei *length, MGLcharARB *source);
	void glBindAttribLocationARB(MGLhandleARB programObj, MGLuint index, const MGLcharARB *name);
	void glGetActiveAttribARB(MGLhandleARB programObj, MGLuint index, MGLsizei maxLength, MGLsizei *length, MGLint *size, MGLenum *type, MGLcharARB *name);
	MGLint glGetAttribLocationARB(MGLhandleARB programObj, const MGLcharARB *name);

	// EXT_frame_buffer_object
	MGLboolean glIsRenderbufferEXT(MGLuint);
	void glBindRenderbufferEXT (MGLenum, MGLuint);
	void glDeleteRenderbuffersEXT (MGLsizei, const MGLuint *);
	void glGenRenderbuffersEXT (MGLsizei, MGLuint *);
	void glRenderbufferStorageEXT (MGLenum, MGLenum, MGLsizei, MGLsizei);
	void glGetRenderbufferParameterivEXT (MGLenum, MGLenum, MGLint *);
	MGLboolean glIsFramebufferEXT (MGLuint);
	void glBindFramebufferEXT (MGLenum, MGLuint);
	void glDeleteFramebuffersEXT (MGLsizei, const MGLuint *);
	void glGenFramebuffersEXT (MGLsizei, MGLuint *);
	MGLenum glCheckFramebufferStatusEXT (MGLenum);
	void glFramebufferTexture1DEXT (MGLenum, MGLenum, MGLenum, MGLuint, MGLint);
	void glFramebufferTexture2DEXT (MGLenum, MGLenum, MGLenum, MGLuint, MGLint);
	void glFramebufferTexture3DEXT (MGLenum, MGLenum, MGLenum, MGLuint, MGLint, MGLint);
	void glFramebufferRenderbufferEXT (MGLenum, MGLenum, MGLenum, MGLuint);
	void glGetFramebufferAttachmentParameterivEXT (MGLenum, MGLenum, MGLenum, MGLint *);
	void glGenerateMipmapEXT (MGLenum);
	void glBlitFramebufferEXT (MGLint srcX0, MGLint srcY0, MGLint srcX1, MGLint srcY1, MGLint dstX0, MGLint dstY0, MGLint dstX1, MGLint dstY1, MGLbitfield mask, MGLenum filter);

	// NV_transform_feedback
	void   glActiveVaryingNV(MGLuint program, const MGLcharARB *name);
	void   glBeginTransformFeedbackNV(MGLenum primitiveMode);
	void   glBindBufferBaseNV(MGLenum target, MGLuint index, MGLuint buffer);
	void   glBindBufferOffsetNV(MGLenum target, MGLuint index, MGLuint buffer, MGLintptrARB offset);
	void   glBindBufferRangeNV(MGLenum target, MGLuint index, MGLuint buffer, MGLintptrARB offset, MGLsizeiptrARB size);
	void   glEndTransformFeedbackNV(void);
	void   glGetActiveVaryingNV(MGLuint program, MGLuint index, MGLsizei bufSize, MGLsizei *length, MGLsizei *size, MGLenum *type, MGLcharARB *name);
	void   glGetTransformFeedbackVaryingNV(MGLuint program, MGLuint index, MGLint *location);
	MGLint glGetVaryingLocationNV(MGLuint program, const MGLcharARB *name);
	void   glTransformFeedbackAttribsNV(MGLuint count, const MGLint *attribs, MGLenum bufferMode);
	void   glTransformFeedbackVaryingsNV(MGLuint program, MGLsizei count, const MGLint *locations, MGLenum bufferMode);

	// EXT_transform_feedback
	void glBeginTransformFeedbackEXT(MGLenum primitiveMode);
	void glBindBufferBaseEXT(MGLenum target, MGLuint index, MGLuint buffer);
	void glBindBufferOffsetEXT(MGLenum target, MGLuint index, MGLuint buffer, MGLintptrARB offset);
	void glBindBufferRangeEXT(MGLenum target, MGLuint index, MGLuint buffer, MGLintptrARB offset, MGLsizeiptrARB size);
	void glEndTransformFeedbackEXT(void);
	void glGetTransformFeedbackVaryingEXT(MGLuint program, MGLuint index, MGLsizei bufSize, MGLsizei* length, MGLsizei *size, MGLenum *type, MGLcharARB *name);
	void glTransformFeedbackVaryingsEXT(MGLuint program, MGLsizei count, const MGLcharARB ** varyings, MGLenum bufferMode);

protected:
	friend class MHardwareRenderer;

	MGLFunctionTable();
	virtual ~MGLFunctionTable();

private:
	// No private members
};
OPENMAYA_NAMESPACE_CLOSE

#endif /* __cplusplus */
#endif // _MGLFunctionTable_h_
