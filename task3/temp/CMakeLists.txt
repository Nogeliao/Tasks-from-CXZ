aux_source_directory (. SRC_LIST)


add_library (array_static STATIC ${SRC_LIST})

add_library (sort_static STATIC ${SRC_LIST})

add_library (quick_sort_static STATIC ${SRC_LIST})


set_target_properties (array_static PROPERTIES OUTPUT_NAME "array")

set_target_properties (sort_static PROPERTIES OUTPUT_NAME "sort")

set_target_properties (quick_sort_static PROPERTIES OUTPUT_NAME "quicksort")

# 设置 库文件的默认输出路径
set (LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)