project(LibPNG LANGUAGES CXX)

add_library(LibPNG STATIC
					# Source Files
					"${CMAKE_CURRENT_SOURCE_DIR}/png.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/pngerror.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/pnggccrd.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/pngget.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/pngmem.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/pngpread.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/pngread.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/pngrio.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/pngrtran.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/pngrutil.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/pngset.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/pngtrans.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/pngvcrd.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/pngwio.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/pngwrite.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/pngwtran.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/pngwutil.c"
					# Header Files
					"${CMAKE_CURRENT_SOURCE_DIR}/png.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/pngconf.h"
					# ./
)

set_target_properties(LibPNG PROPERTIES FOLDER "engine/sdk/freeimage")
