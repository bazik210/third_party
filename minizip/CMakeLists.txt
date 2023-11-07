project(minizip LANGUAGES CXX)

add_library(minizip STATIC
						# ./
						"${CMAKE_CURRENT_SOURCE_DIR}/crypt.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/ioapi.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/ioapi.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/iowin32.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/iowin32.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/miniunz.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/mztools.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/mztools.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/unzip.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/unzip.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/zip.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/zip.h"
)

set_target_properties(minizip PROPERTIES FOLDER "engine/sdk/minizip")

target_compile_definitions(minizip PRIVATE
    WIN32
    WIN64=0
    _LIB
    _CRT_SECURE_NO_WARNINGS
)

##################



add_library(minizipN STATIC
						# ./
						"${CMAKE_CURRENT_SOURCE_DIR}/crypt.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/ioapi.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/ioapi.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/iowin32.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/iowin32.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/miniunz.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/mztools.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/mztools.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/unzip.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/unzip.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/zip.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/zip.h"
)

target_compile_definitions(minizipN PRIVATE
    _LIB
    _CRT_SECURE_NO_WARNINGS
)

set_target_properties(minizipN PROPERTIES FOLDER "engine/sdk/minizip")
