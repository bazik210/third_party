project(vorbis LANGUAGES CXX)

add_library(vorbis STATIC
					# Source Files
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/analysis.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/bitrate.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/block.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/codebook.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/envelope.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/floor0.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/floor1.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/info.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/lookup.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/lpc.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/lsp.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/mapping0.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/mdct.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/psy.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/registry.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/res0.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/sharedbook.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/smallft.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/synthesis.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../vorbis.def"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/vorbisenc.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/window.c"
					# Header Files
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/backends.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/bitrate.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/codebook.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../../codec.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/codec_internal.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/envelope.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/modes/floor_all.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/books/floor/floor_books.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/highlevel.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/lookup.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/lookup_data.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/lpc.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/lsp.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/masking.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/mdct.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/misc.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/os.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/psy.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/modes/psych_11.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/modes/psych_16.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/modes/psych_44.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/modes/psych_8.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/registry.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/books/coupled/res_books_stereo.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/books/uncoupled/res_books_uncoupled.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/modes/residue_16.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/modes/residue_44.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/modes/residue_44u.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/modes/residue_8.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/scales.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/modes/setup_11.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/modes/setup_16.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/modes/setup_22.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/modes/setup_32.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/modes/setup_44.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/modes/setup_44u.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/modes/setup_8.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/modes/setup_X.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/smallft.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../../vorbisenc.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../../vorbisfile.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/window.h"
					# include
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../../library_linkage.h"
					# ./
)

#TODO Check this bizarre libogg include
target_include_directories(vorbis PRIVATE
	${SOLUTION_DIR_INCLUDE_PATH}
	${THIRDPARTY_DIR_INCLUDE_PATH}
	${THIRDPARTY_DIR_INCLUDE_PATH}/vorbis/sources/include
	${THIRDPARTY_DIR_INCLUDE_PATH}/vorbis/libogg/include
)
target_compile_definitions(vorbis PRIVATE
	LIBVORBIS_EXPORTS
)

set_target_properties(vorbis PROPERTIES FOLDER "engine/sdk/vorbis")
