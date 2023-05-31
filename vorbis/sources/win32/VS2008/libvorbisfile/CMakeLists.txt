project(vorbisfile LANGUAGES CXX)

add_library(vorbisfile STATIC
						# Source Files
						"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/vorbisfile.c"
						# Header Files
						"${CMAKE_CURRENT_SOURCE_DIR}/../../../../vorbisfile.h"
						# Resource Files
						# ./
)

#TODO Check this bizarre libogg include
target_include_directories(vorbisfile PRIVATE
	${SOLUTION_DIR_INCLUDE_PATH}
	${THIRDPARTY_DIR_INCLUDE_PATH}
	${THIRDPARTY_DIR_INCLUDE_PATH}/vorbis/sources/include
	${THIRDPARTY_DIR_INCLUDE_PATH}/vorbis/libogg/include
)
target_compile_definitions(vorbisfile PRIVATE
	LIBVORBISFILE_EXPORTS
)

set_target_properties(vorbisfile PROPERTIES FOLDER "engine/sdk/vorbis")
