cmake_minimum_required( VERSION 2.6 )
set( CMAKE_CXX_STANDARD 11 )


include_directories( coord
    map
    map_2d
    map_3d
    node
    avl/avl_tree
)

# TODO: Do not forget to add all these folders to this list.

add_subdirectory( coord )
add_subdirectory( test )
add_subdirectory( map )
add_subdirectory( avl )
add_subdirectory( map_2d )
add_subdirectory( map_3d )
