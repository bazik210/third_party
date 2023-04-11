project(ogg LANGUAGES CXX)

add_library(ogg STATIC
					# Source Files
					"${CMAKE_CURRENT_SOURCE_DIR}/../../src/bitwise.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../src/framing.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../ogg.def"
					# Header Files
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../ogg.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../os_types.h"
					# Resource Files
					# ./
)

set_target_properties(ogg PROPERTIES FOLDER "engine/sdk")
