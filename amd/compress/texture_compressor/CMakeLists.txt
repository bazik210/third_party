project(texture_compressor LANGUAGES CXX)

add_library(texture_compressor SHARED
								# core
								"${CMAKE_CURRENT_SOURCE_DIR}/ATI_Compress_Test_Helpers.cpp"
								"${CMAKE_CURRENT_SOURCE_DIR}/ATI_Compress_Test_Helpers.h"
								"${CMAKE_CURRENT_SOURCE_DIR}/dds_utils.cpp"
								"${CMAKE_CURRENT_SOURCE_DIR}/freeimage_utils.cpp"
								"${CMAKE_CURRENT_SOURCE_DIR}/pch.cpp"
								"${CMAKE_CURRENT_SOURCE_DIR}/pch.h"
								"${CMAKE_CURRENT_SOURCE_DIR}/tga_utils.cpp"
								"${CMAKE_CURRENT_SOURCE_DIR}/utils.h"
								# optimized
								"${CMAKE_CURRENT_SOURCE_DIR}/realtime_dxt_compression.cpp"
								"${CMAKE_CURRENT_SOURCE_DIR}/realtime_nmap_dxt.cpp"
								# include
								"${CMAKE_CURRENT_SOURCE_DIR}/api.h"
								# ./
								"${CMAKE_CURRENT_SOURCE_DIR}/entry_point.cpp"
)

target_include_directories(texture_compressor PRIVATE
	${SOLUTION_DIR_INCLUDE_PATH}
	${THIRDPARTY_DIR_INCLUDE_PATH}
)
if("${CMAKE_GENERATOR_PLATFORM}" STREQUAL "x64")
target_link_libraries(texture_compressor PRIVATE
	FreeImageDLL
	nvtt
	"${THIRDPARTY_DIR_INCLUDE_PATH}amd/compress/ATI_Compress_MT_DLL64.lib"
	odbc32.lib
	odbccp32.lib
)
else()
target_link_libraries(texture_compressor PRIVATE
	FreeImageDLL
	nvtt
	"${THIRDPARTY_DIR_INCLUDE_PATH}amd/compress/ATI_Compress_MT_DLL32.lib"
	odbc32.lib
	odbccp32.lib
)
endif()
target_link_directories(texture_compressor PRIVATE
    ${SOLUTION_DIR_INCLUDE_PATH}/binaries
)

# seems not needed, give problems with engine

#set_target_properties(texture_compressor PROPERTIES DOTNET_TARGET_FRAMEWORK_VERSION "v4.0")

#set_target_properties(texture_compressor PROPERTIES VS_GLOBAL_CLRSupport "true")

#set_target_properties(texture_compressor PROPERTIES COMMON_LANGUAGE_RUNTIME "")

set_target_properties(texture_compressor PROPERTIES FOLDER "engine/sdk/amd")