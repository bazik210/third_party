project(script_cs LANGUAGES CXX)

add_library(script_cs STATIC
						# property_holder
						"${CMAKE_CURRENT_SOURCE_DIR}/property_holder.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/property_holder.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/property_holder_inline.h"
						# world
						"${CMAKE_CURRENT_SOURCE_DIR}/world.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/world.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/world_autoload.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/world_error.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/world_help.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/world_inline.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/world_interface.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/world_object.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/world_process.cpp"
						# core
						"${CMAKE_CURRENT_SOURCE_DIR}/library_linkage.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/pch.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/pch.h"
						# thread
						"${CMAKE_CURRENT_SOURCE_DIR}/thread.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/thread.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/thread_inline.h"
						# include
						"${CMAKE_CURRENT_SOURCE_DIR}/../callback.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../callback_generator.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../callback_impl.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../callback_impl_inline.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../interfaces.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../library_linkage.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../property_holder.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../thread.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../world.h"
						# lua_studio_backend
						# engine
						"${CMAKE_CURRENT_SOURCE_DIR}/engine.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/engine.h"
						# singleton
						"${CMAKE_CURRENT_SOURCE_DIR}/lua_studio_backend_singleton.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/lua_studio_backend_singleton.h"
						# ./
						"${CMAKE_CURRENT_SOURCE_DIR}/entry_point.cpp"
)

set_target_properties(script_cs PROPERTIES FOLDER "engine/sdk/cs")
