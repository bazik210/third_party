project(zlib LANGUAGES CXX)

add_library(zlib STATIC
					# ./
					"${CMAKE_CURRENT_SOURCE_DIR}/adler32.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/compress.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/crc32.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/crc32.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/deflate.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/deflate.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/gzio.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/infback.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/inffast.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/inffast.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/inffixed.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/inflate.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/inflate.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/inftrees.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/inftrees.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/minigzip.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/trees.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/trees.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/uncompr.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/zconf.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/zconf.in.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/zlib.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/zutil.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/zutil.h"
)

target_compile_definitions(zlib PRIVATE
    WIN32
    WIN64=0
    _LIB
    _CRT_SECURE_NO_WARNINGS
)

set_target_properties(zlib PROPERTIES FOLDER "engine/sdk/zlib")



#####################



add_library(zlibN STATIC
					# ./
					"${CMAKE_CURRENT_SOURCE_DIR}/adler32.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/compress.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/crc32.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/crc32.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/deflate.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/deflate.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/gzio.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/infback.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/inffast.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/inffast.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/inffixed.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/inflate.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/inflate.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/inftrees.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/inftrees.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/minigzip.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/trees.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/trees.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/uncompr.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/zconf.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/zconf.in.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/zlib.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/zutil.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/zutil.h"
)

target_compile_definitions(zlibN PRIVATE
    _LIB
    _CRT_SECURE_NO_WARNINGS
)

set_target_properties(zlibN PROPERTIES FOLDER "engine/sdk/zlib")
