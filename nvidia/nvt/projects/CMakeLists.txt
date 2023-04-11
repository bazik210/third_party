project(nvidia LANGUAGES CXX)

add_library(nvcore STATIC
					# Source Files
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvcore/Debug.cpp"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvcore/Library.cpp"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvcore/Memory.cpp"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvcore/StrLib.cpp"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvcore/TextReader.cpp"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvcore/TextWriter.cpp"
					# Header Files
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvcore/Containers.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvcore/Debug.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvcore/DefsVcWin32.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvcore/Library.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvcore/Memory.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvconfig.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvcore/nvcore.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvcore/Ptr.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvcore/StrLib.h"
					# ./
)

set_target_properties(nvcore PROPERTIES FOLDER "engine/sdk/nvidia")


add_library(nvimage STATIC
						# Source Files
						"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvimage/BlockDXT.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvimage/ColorBlock.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvimage/DirectDrawSurface.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvimage/Filter.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvimage/FloatImage.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvimage/Image.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvimage/ImageIO.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvimage/NormalMap.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvimage/Quantize.cpp"
						# Header Files
						"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvimage/BlockDXT.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvimage/ColorBlock.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvimage/DirectDrawSurface.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvimage/Filter.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvimage/FloatImage.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvimage/Image.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvimage/ImageIO.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvimage/NormalMap.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvimage/nvimage.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvimage/PixelFormat.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvimage/PsdFile.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvimage/Quantize.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvimage/TgaFile.h"
						# ./
)

set_target_properties(nvimage PROPERTIES FOLDER "engine/sdk/nvidia")


add_library(nvtt SHARED
					# Source Files
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/CompressDXT.cpp"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/CompressionOptions.cpp"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/Compressor.cpp"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/CompressRGB.cpp"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/cuda/CudaCompressDXT.cpp"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/cuda/CudaUtils.cpp"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/InputOptions.cpp"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/nvtt.cpp"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/nvtt_wrapper.cpp"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/OptimalCompressDXT.cpp"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/OutputOptions.cpp"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/QuickCompressDXT.cpp"
					# Header Files
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/cuda/Bitmaps.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/CompressDXT.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/CompressionOptions.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/Compressor.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/CompressRGB.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/cuda/CudaCompressDXT.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/cuda/CudaMath.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/cuda/CudaUtils.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/InputOptions.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/nvtt.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/nvtt_wrapper.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/OptimalCompressDXT.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/OutputOptions.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/QuickCompressDXT.h"
					# MISSING
					#"${CMAKE_CURRENT_SOURCE_DIR}/resource.h"
					# Resource Files
					# ./
)

set_target_properties(nvtt PROPERTIES FOLDER "engine/sdk/nvidia")


add_library(squish STATIC
					# Source Files
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/squish/clusterfit.cpp"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/squish/colourblock.cpp"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/squish/colourfit.cpp"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/squish/colourset.cpp"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/squish/fastclusterfit.cpp"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/squish/maths.cpp"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/squish/weightedclusterfit.cpp"
					# Header Files
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/squish/clusterfit.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/squish/colourblock.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/squish/colourfit.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/squish/colourset.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/squish/fastclusterfit.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/squish/maths.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/squish/simd.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/squish/simd_sse.h"
					"${CMAKE_CURRENT_SOURCE_DIR}/../src/nvtt/squish/weightedclusterfit.h"
					# ./
)

set_target_properties(squish PROPERTIES FOLDER "engine/sdk/nvidia")
