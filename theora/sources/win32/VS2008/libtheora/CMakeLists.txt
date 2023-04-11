project(theora LANGUAGES CXX)

add_library(theora STATIC
					# include
					# theora
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../../codec.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../../theora.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../../theoradec.h"
					# lib
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/cpu.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/cpu.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/internal.h"
					# enc
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/analyze.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/encapiwrapper.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/encfrag.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/encinfo.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/encint.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/encode.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/enquant.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/fdct.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/huffenc.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/huffenc.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/mathops.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/mathops.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/mcenc.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/modedec.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/rate.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/tokenize.c"
					# x86_vc
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/x86_vc/mmxencfrag.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/x86_vc/mmxfdct.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/x86_vc/x86enc.c"
					# dec
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/apiwrapper.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/apiwrapper.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/bitpack.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/bitpack.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/dct.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/decapiwrapper.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/decinfo.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/decint.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/decode.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/dequant.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/dequant.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/enquant.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/fragment.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/huffdec.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/huffdec.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/huffman.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/idct.c"
					# MISSING
					#"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/idct.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/info.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/internal.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/ocintrin.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/quant.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/quant.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/state.c"
					# x86_vc
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/x86_vc/mmxfrag.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/x86_vc/mmxidct.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/x86_vc/mmxstate.c"
					"${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/x86_vc/x86state.c"
					# ./
)

set_target_properties(theora PROPERTIES FOLDER "engine/sdk")