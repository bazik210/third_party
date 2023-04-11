project(core_cs LANGUAGES CXX)

add_library(core_cs STATIC
						# core
						"${CMAKE_CURRENT_SOURCE_DIR}/internal.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/library_linkage.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/pch.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/pch.h"
						# extensions
						# memory
						# functions
						"${CMAKE_CURRENT_SOURCE_DIR}/memory_functions.cpp"
						# allocators
						# doug_lea
						"${CMAKE_CURRENT_SOURCE_DIR}/doug_lea_memory_allocator.c"
						"${CMAKE_CURRENT_SOURCE_DIR}/doug_lea_memory_allocator.h"
						# monitor
						"${CMAKE_CURRENT_SOURCE_DIR}/memory_monitor.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/memory_monitor.h"
						# debug
						# debug
						"${CMAKE_CURRENT_SOURCE_DIR}/debug.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/debug_initialize.cpp"
						# math
						# vec3f
						"${CMAKE_CURRENT_SOURCE_DIR}/vec3f_script.cpp"
						# matrix4f
						"${CMAKE_CURRENT_SOURCE_DIR}/matrix4f_script.cpp"
						# vec2f
						"${CMAKE_CURRENT_SOURCE_DIR}/vec2f_script.cpp"
						# aabb3f
						"${CMAKE_CURRENT_SOURCE_DIR}/aabb3f_script.cpp"
						# plane3f
						"${CMAKE_CURRENT_SOURCE_DIR}/plane3f.cpp"
						# angles
						"${CMAKE_CURRENT_SOURCE_DIR}/math_angles_script.cpp"
						# sphere3f
						"${CMAKE_CURRENT_SOURCE_DIR}/sphere3f_script.cpp"
						# vec4f
						"${CMAKE_CURRENT_SOURCE_DIR}/vec4f_script.cpp"
						# frustum3f
						"${CMAKE_CURRENT_SOURCE_DIR}/frustum3f.cpp"
						# core
						# core
						"${CMAKE_CURRENT_SOURCE_DIR}/core.cpp"
						# delay_loading
						"${CMAKE_CURRENT_SOURCE_DIR}/delayimp.h"
						# strings
						# shared
						# manager
						"${CMAKE_CURRENT_SOURCE_DIR}/shared_string_manager.cpp"
						# string_profile
						"${CMAKE_CURRENT_SOURCE_DIR}/shared_string_profile.cpp"
						# functions
						"${CMAKE_CURRENT_SOURCE_DIR}/string_functions.cpp"
						# stream
						"${CMAKE_CURRENT_SOURCE_DIR}/string_stream.cpp"
						# fs
						# fs
						"${CMAKE_CURRENT_SOURCE_DIR}/fs.cpp"
						# reader
						# base
						"${CMAKE_CURRENT_SOURCE_DIR}/fs_readers_base.cpp"
						# file
						"${CMAKE_CURRENT_SOURCE_DIR}/fs_readers_file.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/fs_readers_file.h"
						# writers
						# file
						"${CMAKE_CURRENT_SOURCE_DIR}/fs_writers_file.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/fs_writers_file.h"
						# threading
						# mutex
						"${CMAKE_CURRENT_SOURCE_DIR}/threading_mutex.cpp"
						# functions
						"${CMAKE_CURRENT_SOURCE_DIR}/threading_functions.cpp"
						# os
						# functions
						"${CMAKE_CURRENT_SOURCE_DIR}/os_functions.cpp"
						# platform
						# platform
						"${CMAKE_CURRENT_SOURCE_DIR}/platform.cpp"
						# logging
						"${CMAKE_CURRENT_SOURCE_DIR}/log.cpp"
						# log_file
						"${CMAKE_CURRENT_SOURCE_DIR}/log_file.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/log_file.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/log_file_inline.h"
						# build
						"${CMAKE_CURRENT_SOURCE_DIR}/build_extensions.cpp"
						# script_export
						"${CMAKE_CURRENT_SOURCE_DIR}/pch_script.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/pch_script.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/script_export.cpp"
						"${CMAKE_CURRENT_SOURCE_DIR}/script_export.h"
						# include
						"${CMAKE_CURRENT_SOURCE_DIR}/../extensions.h"
						# math
						"${CMAKE_CURRENT_SOURCE_DIR}/../math_extensions.h"
						# functions
						"${CMAKE_CURRENT_SOURCE_DIR}/../math_functions.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../math_functions_inline.h"
						# sphere3f
						"${CMAKE_CURRENT_SOURCE_DIR}/../sphere3f.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../sphere3f_inline.h"
						# vec4f
						"${CMAKE_CURRENT_SOURCE_DIR}/../vec4f.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../vec4f_inline.h"
						# vec3f
						"${CMAKE_CURRENT_SOURCE_DIR}/../vec3f.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../vec3f_inline.h"
						# angles
						"${CMAKE_CURRENT_SOURCE_DIR}/../math_angles.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../math_angles_inline.h"
						# matrix4f
						"${CMAKE_CURRENT_SOURCE_DIR}/../matrix4f.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../matrix4f_inline.h"
						# constants
						"${CMAKE_CURRENT_SOURCE_DIR}/../math_constants.h"
						# vec2f
						"${CMAKE_CURRENT_SOURCE_DIR}/../vec2f.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../vec2f_inline.h"
						# plane3f
						"${CMAKE_CURRENT_SOURCE_DIR}/../plane3f.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../plane3f_inline.h"
						# frustum3f
						"${CMAKE_CURRENT_SOURCE_DIR}/../frustum3f.h"
						# aabb3f
						"${CMAKE_CURRENT_SOURCE_DIR}/../aabb3f.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../aabb3f_inline.h"
						# aabb2f
						"${CMAKE_CURRENT_SOURCE_DIR}/../aabb2f.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../aabb2f_inline.h"
						# build
						"${CMAKE_CURRENT_SOURCE_DIR}/../build_extensions.h"
						# core
						"${CMAKE_CURRENT_SOURCE_DIR}/../core_extensions.h"
						# core
						"${CMAKE_CURRENT_SOURCE_DIR}/../core.h"
						# type
						"${CMAKE_CURRENT_SOURCE_DIR}/../type_extensions.h"
						# timing
						"${CMAKE_CURRENT_SOURCE_DIR}/../timing_extensions.h"
						# timer
						"${CMAKE_CURRENT_SOURCE_DIR}/../timing_timer.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../timing_timer_inline.h"
						# threading
						"${CMAKE_CURRENT_SOURCE_DIR}/../threading_extensions.h"
						# functions
						"${CMAKE_CURRENT_SOURCE_DIR}/../threading_functions.h"
						# mutex
						"${CMAKE_CURRENT_SOURCE_DIR}/../threading_mutex.h"
						# strings
						"${CMAKE_CURRENT_SOURCE_DIR}/../string_extensions.h"
						# functions
						"${CMAKE_CURRENT_SOURCE_DIR}/../string_functions.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../string_functions_inline.h"
						# stream
						"${CMAKE_CURRENT_SOURCE_DIR}/../string_stream.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../string_stream_inline.h"
						# shared
						# string
						"${CMAKE_CURRENT_SOURCE_DIR}/../shared_string.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../shared_string_inline.h"
						# manager
						"${CMAKE_CURRENT_SOURCE_DIR}/../shared_string_manager.h"
						# profile
						"${CMAKE_CURRENT_SOURCE_DIR}/../shared_string_profile.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../shared_string_profile_inline.h"
						# std
						"${CMAKE_CURRENT_SOURCE_DIR}/../std_extensions.h"
						# platform
						"${CMAKE_CURRENT_SOURCE_DIR}/../platform.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../platform_extensions.h"
						# os
						"${CMAKE_CURRENT_SOURCE_DIR}/../os_extensions.h"
						# include
						"${CMAKE_CURRENT_SOURCE_DIR}/../os_include.h"
						# functions
						"${CMAKE_CURRENT_SOURCE_DIR}/../os_functions.h"
						# optimization
						"${CMAKE_CURRENT_SOURCE_DIR}/../optimization_extensions.h"
						# memory
						"${CMAKE_CURRENT_SOURCE_DIR}/../memory.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../memory_extensions.h"
						# manager
						"${CMAKE_CURRENT_SOURCE_DIR}/../memory_manager_generator.h"
						# allocator
						"${CMAKE_CURRENT_SOURCE_DIR}/../memory_allocator.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../memory_allocator_inline.h"
						# logging
						"${CMAKE_CURRENT_SOURCE_DIR}/../log_extensions.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../logging.h"
						# library_linkage
						"${CMAKE_CURRENT_SOURCE_DIR}/../library_linkage.h"
						# macro
						"${CMAKE_CURRENT_SOURCE_DIR}/../macro_extensions.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../macro_platform.h"
						# fs
						"${CMAKE_CURRENT_SOURCE_DIR}/../fs.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../fs_extensions.h"
						# reader
						# base
						"${CMAKE_CURRENT_SOURCE_DIR}/../fs_readers_base.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../fs_readers_base_inline.h"
						# writer
						# base
						"${CMAKE_CURRENT_SOURCE_DIR}/../fs_writers_base.h"
						# debug
						"${CMAKE_CURRENT_SOURCE_DIR}/../debug.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../debug_extensions.h"
						# extern
						"${CMAKE_CURRENT_SOURCE_DIR}/../../config.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../defines.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../libraries_linkage.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../library_names.h"
						# stdlib_extensions
						"${CMAKE_CURRENT_SOURCE_DIR}/../stdlib_extensions.h"
						# gtl
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/type_traits.h"
						# comparison
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/comparison/array.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/comparison/c_string.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/comparison/compare.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/comparison/deque.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/comparison/hash_map.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/comparison/hash_set.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/comparison/list.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/comparison/map.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/comparison/pair.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/comparison/queue.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/comparison/set.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/comparison/stack.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/comparison/stl_container.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/comparison/stl_queue.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/comparison/str_shared.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/comparison/string.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/comparison/vector.h"
						# destruction
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/destruction/array.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/destruction/c_string.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/destruction/deque.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/destruction/destroy.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/destruction/hash_map.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/destruction/hash_set.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/destruction/list.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/destruction/map.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/destruction/pair.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/destruction/queue.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/destruction/set.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/destruction/stack.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/destruction/stl_container.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/destruction/stl_queue.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/destruction/str_shared.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/destruction/string.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/destruction/vector.h"
						# graph
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/graph.h"
						# base
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/graph_base.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/graph_base_inline.h"
						# data
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/graph_data.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/graph_data_inline.h"
						# edge
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/graph_edge.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/graph_edge_inline.h"
						# helper
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/graph_helper.h"
						# data
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/graph_helper_data.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/graph_helper_data_inline.h"
						# base
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/graph_helper_base.h"
						# no_data
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/graph_helper_no_data.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/graph_helper_no_data_inline.h"
						# no_data
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/graph_no_data.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/graph_no_data_inline.h"
						# vertex
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/graph_vertex.h"
						# base
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/graph_vertex_base.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/graph_vertex_base_inline.h"
						# data
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/graph_vertex_data.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/graph_vertex_data_inline.h"
						# no_data
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/graph_vertex_no_data.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/graph_vertex_no_data_inline.h"
						# intrusive_ptr
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/intrusive_ptr.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/intrusive_ptr_inline.h"
						# base
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/intrusive_base.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/intrusive_base_inline.h"
						# default_functionality
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/intrusive_default_functionality.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/intrusive_default_functionality_inline.h"
						# quad_tree
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/quad_tree.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/quad_tree_inline.h"
						# list_item
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/quad_list_item.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/quad_list_item_inline.h"
						# node
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/quad_node.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/quad_node_inline.h"
						# fixed_storage
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/quad_fixed_storage.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/quad_fixed_storage_inline.h"
						# random32
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/random32.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/random32_inline.h"
						# script_export
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/script_export.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/script_export_macroses.h"
						# object_factory
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/object_factory.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/object_factory_inline.h"
						# constructor_base
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/object_constructor_base.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/object_constructor_base_inline.h"
						# any_cast
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/any_cast.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/any_cast_inline.h"
						# aggregated
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/aggregated.h"
						"${CMAKE_CURRENT_SOURCE_DIR}/../../gtl/aggregated_inline.h"
						# ./
						"${CMAKE_CURRENT_SOURCE_DIR}/entry_point.cpp"
)

set_target_properties(core_cs PROPERTIES FOLDER "engine/sdk/cs")
