project(FreeImage LANGUAGES CXX)

add_library(FreeImage STATIC
						# Source Files
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/BitmapAccess.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/ColorLookup.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/FreeImage.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/FreeImageIO.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/GetType.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/MemoryIO.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PixelAccess.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/TIFFLogLuv.cpp"
						# Quantizers
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/NNQuantizer.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/WuQuantizer.cpp"
						# Conversion
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/Conversion.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/Conversion16_555.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/Conversion16_565.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/Conversion24.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/Conversion32.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/Conversion4.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/Conversion8.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/ConversionRGBF.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/ConversionType.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/Halftoning.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/tmoColorConvert.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/tmoDrago03.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/tmoFattal02.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/tmoReinhard05.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/ToneMapping.cpp"
						# Plugins
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/J2KHelper.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/Plugin.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginBMP.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginCUT.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginDDS.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginEXR.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginG3.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginGIF.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginHDR.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginICO.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginIFF.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginJ2K.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginJP2.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginJPEG.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginKOALA.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginMNG.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginPCD.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginPCX.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginPFM.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginPNG.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginPNM.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginPSD.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginRAS.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginSGI.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginTARGA.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginTIFF.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginWBMP.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginXBM.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginXPM.cpp"
						# DeprecationMgr
						"${CMAKE_CURRENT_SOURCE_DIR}/../DeprecationManager/DeprecationMgr.cpp"
						# MultiPaging
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/CacheFile.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/MultiPage.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/ZLibInterface.cpp"
						# Metadata
						"${CMAKE_CURRENT_SOURCE_DIR}/../Metadata/Exif.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../Metadata/FIRational.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../Metadata/FreeImageTag.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../Metadata/IPTC.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../Metadata/TagConversion.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../Metadata/TagLib.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../Metadata/XTIFF.cpp"
						# Header Files
						"${CMAKE_CURRENT_SOURCE_DIR}/../CacheFile.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../DeprecationManager/DeprecationMgr.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../Metadata/FIRational.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImageIO.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../Metadata/FreeImageTag.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../Plugin.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../Quantizers.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../ToneMapping.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../Utilities.h"
						# Toolkit Files
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImageToolkit/BSplineRotate.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImageToolkit/Channels.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImageToolkit/ClassicRotate.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImageToolkit/Colors.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImageToolkit/CopyPaste.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImageToolkit/Display.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImageToolkit/Flip.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImageToolkit/JPEGTransform.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImageToolkit/MultigridPoissonSolver.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImageToolkit/Rescale.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImageToolkit/Resize.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImageToolkit/Resize.h"
						# ./
						#"${CMAKE_CURRENT_SOURCE_DIR}/../../Whatsnew.txt"
)

target_include_directories(FreeImage PRIVATE
	${THIRDPARTY_DIR_INCLUDE_PATH}/freeimage
	${THIRDPARTY_DIR_INCLUDE_PATH}/freeimage/OpenEXR
	${THIRDPARTY_DIR_INCLUDE_PATH}/freeimage/OpenEXR/Half
	${THIRDPARTY_DIR_INCLUDE_PATH}/freeimage/OpenEXR/Iex
	${THIRDPARTY_DIR_INCLUDE_PATH}/freeimage/OpenEXR/IlmImf
	${THIRDPARTY_DIR_INCLUDE_PATH}/freeimage/OpenEXR/IlmThread
	${THIRDPARTY_DIR_INCLUDE_PATH}/freeimage/OpenEXR/Imath
)
#TODO check if other linker flags aren't needed
target_compile_definitions(FreeImage PRIVATE
    OPJ_STATIC
    FREEIMAGE_EXPORTS
    _CRT_SECURE_NO_DEPRECATE
)
target_link_directories(FreeImage PRIVATE
    ${SOLUTION_DIR_INCLUDE_PATH}/binaries
)   
target_link_libraries(FreeImage PUBLIC
	LibPNG
	OpenEXR
	LibMNG
	LibTIFF
	LibOpenJPEG
)

set_target_properties(FreeImage PROPERTIES FOLDER "engine/sdk/freeimage")

#############################################

# Project texture_compressor uses __declspec(dllimport) so it fails to link against static lib. This is exact same version just compiled as dll.
add_library(FreeImageDLL SHARED
						# Source Files
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/BitmapAccess.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/ColorLookup.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/FreeImage.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/FreeImageIO.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/GetType.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/MemoryIO.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PixelAccess.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/TIFFLogLuv.cpp"
						# Quantizers
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/NNQuantizer.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/WuQuantizer.cpp"
						# Conversion
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/Conversion.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/Conversion16_555.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/Conversion16_565.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/Conversion24.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/Conversion32.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/Conversion4.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/Conversion8.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/ConversionRGBF.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/ConversionType.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/Halftoning.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/tmoColorConvert.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/tmoDrago03.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/tmoFattal02.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/tmoReinhard05.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/ToneMapping.cpp"
						# Plugins
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/J2KHelper.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/Plugin.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginBMP.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginCUT.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginDDS.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginEXR.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginG3.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginGIF.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginHDR.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginICO.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginIFF.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginJ2K.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginJP2.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginJPEG.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginKOALA.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginMNG.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginPCD.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginPCX.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginPFM.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginPNG.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginPNM.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginPSD.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginRAS.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginSGI.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginTARGA.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginTIFF.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginWBMP.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginXBM.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/PluginXPM.cpp"
						# DeprecationMgr
						"${CMAKE_CURRENT_SOURCE_DIR}/../DeprecationManager/DeprecationMgr.cpp"
						# MultiPaging
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/CacheFile.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/MultiPage.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage/ZLibInterface.cpp"
						# Metadata
						"${CMAKE_CURRENT_SOURCE_DIR}/../Metadata/Exif.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../Metadata/FIRational.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../Metadata/FreeImageTag.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../Metadata/IPTC.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../Metadata/TagConversion.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../Metadata/TagLib.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../Metadata/XTIFF.cpp"
						# Header Files
						"${CMAKE_CURRENT_SOURCE_DIR}/../CacheFile.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../DeprecationManager/DeprecationMgr.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../Metadata/FIRational.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImage.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImageIO.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../Metadata/FreeImageTag.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../Plugin.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../Quantizers.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../ToneMapping.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../Utilities.h"
						# Toolkit Files
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImageToolkit/BSplineRotate.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImageToolkit/Channels.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImageToolkit/ClassicRotate.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImageToolkit/Colors.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImageToolkit/CopyPaste.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImageToolkit/Display.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImageToolkit/Flip.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImageToolkit/JPEGTransform.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImageToolkit/MultigridPoissonSolver.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImageToolkit/Rescale.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImageToolkit/Resize.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/../FreeImageToolkit/Resize.h"
						# ./
						#"${CMAKE_CURRENT_SOURCE_DIR}/../../Whatsnew.txt"
)

target_include_directories(FreeImageDLL PRIVATE
	${THIRDPARTY_DIR_INCLUDE_PATH}/freeimage
	${THIRDPARTY_DIR_INCLUDE_PATH}/freeimage/OpenEXR
	${THIRDPARTY_DIR_INCLUDE_PATH}/freeimage/OpenEXR/Half
	${THIRDPARTY_DIR_INCLUDE_PATH}/freeimage/OpenEXR/Iex
	${THIRDPARTY_DIR_INCLUDE_PATH}/freeimage/OpenEXR/IlmImf
	${THIRDPARTY_DIR_INCLUDE_PATH}/freeimage/OpenEXR/IlmThread
	${THIRDPARTY_DIR_INCLUDE_PATH}/freeimage/OpenEXR/Imath
)
#TODO check if other linker flags aren't needed
target_compile_definitions(FreeImageDLL PRIVATE
    OPJ_STATIC
    FREEIMAGE_EXPORTS
    _CRT_SECURE_NO_DEPRECATE
)
target_link_directories(FreeImageDLL PRIVATE
    ${SOLUTION_DIR_INCLUDE_PATH}/binaries
)   
target_link_libraries(FreeImageDLL PUBLIC
	LibPNG
	OpenEXR
	LibMNG
	LibTIFF
	LibOpenJPEG
)

set_target_properties(FreeImageDLL PROPERTIES FOLDER "engine/sdk/freeimage")

