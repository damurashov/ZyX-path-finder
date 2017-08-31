project( test_proj )

add_definitions( -D_VARIADIC_MAX=10 )
add_definitions( -D_DEBUG )
add_definitions( -D_MT )
add_definitions( -D_DLL )

add_subdirectory( gtest )
add_subdirectory( simple_test_class )
add_subdirectory( functional_tests )

file( GLOB_RECURSE HEADER_FILES *.h )
file( GLOB_RECURSE SOURCE_FILES *.cpp )

include_directories( ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} )
include_directories( ${PROJECT_SOURCE_DIR} )
include_directories( simple_test_class )

add_executable( test_proj ${SOURCE_FILES} ${HEADER_FILES} )
target_link_libraries( test_proj avl_tree gtest gtest_main )
