project(LibJPEG LANGUAGES CXX)

add_library(LibJPEG STATIC
						# Source Files
						"${CMAKE_CURRENT_SOURCE_DIR}/jcapimin.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jcapistd.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jccoefct.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jccolor.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jcdctmgr.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jchuff.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jcinit.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jcmainct.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jcmarker.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jcmaster.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jcomapi.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jcparam.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jcphuff.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jcprepct.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jcsample.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jctrans.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jdapimin.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jdapistd.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jdatadst.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jdatasrc.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jdcoefct.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jdcolor.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jddctmgr.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jdhuff.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jdinput.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jdmainct.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jdmarker.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jdmaster.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jdmerge.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jdphuff.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jdpostct.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jdsample.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jdtrans.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jerror.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jfdctflt.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jfdctfst.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jfdctint.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jidctflt.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jidctfst.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jidctint.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jidctred.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jmemmgr.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jmemnobs.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jquant1.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jquant2.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/jutils.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/transupp.c"
						# Header Files
						"${CMAKE_CURRENT_SOURCE_DIR}/jchuff.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/jconfig.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/jdct.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/jdhuff.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/jerror.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/jinclude.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/jmemsys.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/jmorecfg.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/jpegint.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/jpeglib.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/jversion.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/transupp.h"
						# ./
)

target_include_directories(LibJPEG PRIVATE
    ${THIRDPARTY_DIR_INCLUDE_PATH}/zlib
)
target_compile_definitions(LibJPEG PRIVATE
    _LIB
    _CRT_SECURE_NO_DEPRECATE
)

set_target_properties(LibJPEG PROPERTIES FOLDER "engine/sdk/freeimage")
