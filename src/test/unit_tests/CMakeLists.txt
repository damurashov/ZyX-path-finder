project( test_coord )

add_executable( test_coord test_coord.cpp )
target_link_libraries( test_coord coord gtest gtest_main )
