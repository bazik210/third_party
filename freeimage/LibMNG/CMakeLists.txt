project(LibMNG LANGUAGES CXX)

add_library(LibMNG STATIC
					# Source Files
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_callback_xs.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_chunk_descr.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_chunk_io.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_chunk_prc.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_chunk_xs.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_cms.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_display.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_dither.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_error.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_filter.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_hlapi.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_jpeg.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_object_prc.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_pixels.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_prop_xs.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_read.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_trace.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_write.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_zlib.c"
					# Header Files
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_chunk_descr.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_chunk_io.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_chunk_prc.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_chunks.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_cms.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_conf.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_data.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_display.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_dither.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_error.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_filter.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_jpeg.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_memory.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_object_prc.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_objects.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_pixels.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_read.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_trace.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_types.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_write.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/libmng_zlib.h"
					# ./
)

target_include_directories(LibMNG PRIVATE
    ${THIRDPARTY_DIR_INCLUDE_PATH}/freeimage/LibJPEG
)
target_compile_definitions(LibMNG PRIVATE
    _LIB
    _CRT_SECURE_NO_DEPRECATE
)
target_link_directories(LibMNG PRIVATE
    ${SOLUTION_DIR_INCLUDE_PATH}/binaries
)
target_link_libraries(LibMNG PUBLIC
	LibJPEG
	zlib
)

set_target_properties(LibMNG PROPERTIES FOLDER "engine/sdk/freeimage")
