project(vorbisfile LANGUAGES CXX)

add_library(vorbisfile STATIC
						# Source Files
						"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/vorbisfile.c"
						# Header Files
						"${CMAKE_CURRENT_SOURCE_DIR}/../../../../vorbisfile.h"
						# Resource Files
						# ./
)

set_target_properties(vorbisfile PROPERTIES FOLDER "engine/sdk/vorbis")
