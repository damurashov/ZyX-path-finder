add_definitions( -D_VARIADIC_MAX=10 )
add_definitions( -D_DEBUG )
add_definitions( -D_MT )
add_definitions( -D_DLL )

add_subdirectory( gtest )
include_directories( ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} )

add_subdirectory( unit_tests )
