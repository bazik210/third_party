/* SCE CONFIDENTIAL
 * PlayStation(R)3 Programmer Tool Runtime Library 310.001
 *                Copyright (C) 2009 Sony Computer Entertainment Inc.
 *                                               All Rights Reserved.
 */

#ifndef _PSGL_include_deprecated_h
#define _PSGL_include_deprecated_h


/* Types */

#define JsDevice PSGLdevice
#define JsContext PSGLcontext
#define JsBufferParameters PSGLbufferParameters
#define JSdeviceType PSGLdeviceType
#define JStvStandard PSGLtvStandard
#define JStvFormat PSGLtvFormat
#define JSinitOptions PSGLinitOptions


/* Functions */

#define jsInit psglInit
#define jsExit psglExit
#define jsCreateDevice psglCreateDevice
#define jsDestroyDevice psglDestroyDevice
#define jsMakeCurrent psglMakeCurrent
#define jsCreateContext psglCreateContext
#define jsDestroyContext psglDestroyContext
#define jsResetCurrentContext psglResetCurrentContext
#define jsGetCurrentContext psglGetCurrentContext
#define jsGetCurrentDevice psglGetCurrentDevice
#define jsLoadShaderLibrary psglLoadShaderLibrary


/* Enums */

#define JS_DEVICE_TYPE_AUTO PSGL_DEVICE_TYPE_AUTO
#define JS_DEVICE_TYPE_WINDOW PSGL_DEVICE_TYPE_WINDOW
#define JS_DEVICE_TYPE_VGA PSGL_DEVICE_TYPE_VGA
#define JS_DEVICE_TYPE_DFP PSGL_DEVICE_TYPE_DFP
#define JS_DEVICE_TYPE_TV PSGL_DEVICE_TYPE_TV

#define JS_TV_STANDARD_NONE PSGL_TV_STANDARD_NONE
#define JS_TV_STANDARD_NTSC_M PSGL_TV_STANDARD_NTSC_M
#define JS_TV_STANDARD_NTSC_J PSGL_TV_STANDARD_NTSC_J
#define JS_TV_STANDARD_PAL_M PSGL_TV_STANDARD_PAL_M
#define JS_TV_STANDARD_PAL_B PSGL_TV_STANDARD_PAL_B
#define JS_TV_STANDARD_PAL_D PSGL_TV_STANDARD_PAL_D
#define JS_TV_STANDARD_PAL_G PSGL_TV_STANDARD_PAL_G
#define JS_TV_STANDARD_PAL_H PSGL_TV_STANDARD_PAL_H
#define JS_TV_STANDARD_PAL_I PSGL_TV_STANDARD_PAL_I
#define JS_TV_STANDARD_PAL_N PSGL_TV_STANDARD_PAL_N
#define JS_TV_STANDARD_PAL_NC PSGL_TV_STANDARD_PAL_NC
#define JS_TV_STANDARD_HD480I PSGL_TV_STANDARD_HD480I
#define JS_TV_STANDARD_HD480P PSGL_TV_STANDARD_HD480P
#define JS_TV_STANDARD_HD576I PSGL_TV_STANDARD_HD576I
#define JS_TV_STANDARD_HD576P PSGL_TV_STANDARD_HD576P
#define JS_TV_STANDARD_HD720P PSGL_TV_STANDARD_HD720P
#define JS_TV_STANDARD_HD1080I PSGL_TV_STANDARD_HD1080I
#define JS_TV_STANDARD_HD1080P PSGL_TV_STANDARD_HD1080P

#define JS_TV_FORMAT_AUTO PSGL_TV_FORMAT_AUTO
#define JS_TV_FORMAT_COMPOSITE PSGL_TV_FORMAT_COMPOSITE
#define JS_TV_FORMAT_SVIDEO PSGL_TV_FORMAT_SVIDEO
#define JS_TV_FORMAT_YCRCB PSGL_TV_FORMAT_YCRCB
#define JS_TV_FORMAT_YPRPB PSGL_TV_FORMAT_YPRPB

#define JS_INIT_MAX_SPUS PSGL_INIT_MAX_SPUS
#define JS_INIT_INITIALIZE_SPUS PSGL_INIT_INITIALIZE_SPUS
#define JS_INIT_PERSISTENT_MEMORY_SIZE PSGL_INIT_PERSISTENT_MEMORY_SIZE
#define JS_INIT_TRANSIENT_MEMORY_SIZE PSGL_INIT_TRANSIENT_MEMORY_SIZE

#endif // _PSGL_include_deprecated_h
