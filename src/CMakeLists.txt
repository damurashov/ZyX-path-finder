cmake_minimum_required( VERSION 2.6 )
set( CMAKE_CXX_STANDARD 11 )


include_directories( coord )
include_directories( map )

# TODO: Do not forget to add all these folders to this list.

add_subdirectory( coord )
add_subdirectory( test )
#add_subdirectory( map )
