project(LibOpenJPEG LANGUAGES CXX)

add_library(LibOpenJPEG STATIC
							# Source Files
							"${CMAKE_CURRENT_SOURCE_DIR}/bio.c"
							"${CMAKE_CURRENT_SOURCE_DIR}/cio.c"
							"${CMAKE_CURRENT_SOURCE_DIR}/dwt.c"
							"${CMAKE_CURRENT_SOURCE_DIR}/event.c"
							"${CMAKE_CURRENT_SOURCE_DIR}/image.c"
							"${CMAKE_CURRENT_SOURCE_DIR}/j2k.c"
							"${CMAKE_CURRENT_SOURCE_DIR}/j2k_lib.c"
							"${CMAKE_CURRENT_SOURCE_DIR}/jp2.c"
							"${CMAKE_CURRENT_SOURCE_DIR}/jpt.c"
							"${CMAKE_CURRENT_SOURCE_DIR}/mct.c"
							"${CMAKE_CURRENT_SOURCE_DIR}/mqc.c"
							"${CMAKE_CURRENT_SOURCE_DIR}/openjpeg.c"
							"${CMAKE_CURRENT_SOURCE_DIR}/pi.c"
							"${CMAKE_CURRENT_SOURCE_DIR}/raw.c"
							"${CMAKE_CURRENT_SOURCE_DIR}/t1.c"
							"${CMAKE_CURRENT_SOURCE_DIR}/t2.c"
							"${CMAKE_CURRENT_SOURCE_DIR}/tcd.c"
							"${CMAKE_CURRENT_SOURCE_DIR}/tgt.c"
							# Header Files
							"${CMAKE_CURRENT_SOURCE_DIR}/bio.h"
							"${CMAKE_CURRENT_SOURCE_DIR}/cio.h"
							"${CMAKE_CURRENT_SOURCE_DIR}/dwt.h"
							"${CMAKE_CURRENT_SOURCE_DIR}/event.h"
							"${CMAKE_CURRENT_SOURCE_DIR}/fix.h"
							"${CMAKE_CURRENT_SOURCE_DIR}/image.h"
							"${CMAKE_CURRENT_SOURCE_DIR}/int.h"
							"${CMAKE_CURRENT_SOURCE_DIR}/j2k.h"
							"${CMAKE_CURRENT_SOURCE_DIR}/j2k_lib.h"
							"${CMAKE_CURRENT_SOURCE_DIR}/jp2.h"
							"${CMAKE_CURRENT_SOURCE_DIR}/jpt.h"
							"${CMAKE_CURRENT_SOURCE_DIR}/mct.h"
							"${CMAKE_CURRENT_SOURCE_DIR}/mqc.h"
							"${CMAKE_CURRENT_SOURCE_DIR}/openjpeg.h"
							"${CMAKE_CURRENT_SOURCE_DIR}/opj_includes.h"
							"${CMAKE_CURRENT_SOURCE_DIR}/opj_malloc.h"
							"${CMAKE_CURRENT_SOURCE_DIR}/pi.h"
							"${CMAKE_CURRENT_SOURCE_DIR}/raw.h"
							"${CMAKE_CURRENT_SOURCE_DIR}/t1.h"
							"${CMAKE_CURRENT_SOURCE_DIR}/t2.h"
							"${CMAKE_CURRENT_SOURCE_DIR}/tcd.h"
							"${CMAKE_CURRENT_SOURCE_DIR}/tgt.h"
							# ./
)

target_compile_definitions(LibOpenJPEG PRIVATE
    _LIB
    _OPJ_STATIC
    _CRT_SECURE_NO_DEPRECATE
)

set_target_properties(LibOpenJPEG PROPERTIES FOLDER "engine/sdk/freeimage")
