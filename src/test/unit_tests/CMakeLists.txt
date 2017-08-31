project( test_coord )
add_executable( test_coord test_coord.cpp )
target_link_libraries( test_coord coord gtest gtest_main )

# --------------------------------

project( test_node )
add_executable( test_node test_node.cpp )
target_link_libraries( test_node map gtest gtest_main )

# --------------------------------

project( test_map_2d )
add_executable( test_map_2d test_map_2d.cpp )
target_link_libraries( test_map_2d map_2d gtest gtest_main )

# --------------------------------

project( manual_debug )
add_executable( manual_debug manual_debug.cpp )
target_link_libraries( manual_debug map_2d map_3d )
