project( test_coord )
add_executable( test_coord test_coord.cpp )
target_link_libraries( test_coord coord gtest gtest_main )

# --------------------------------

project( test_node )
add_executable( test_node test_node.cpp )
target_link_libraries( test_node map gtest gtest_main )
