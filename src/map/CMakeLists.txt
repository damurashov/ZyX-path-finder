project( map )
add_library( map
    map.h
    map.cpp
    ${map_SOURCE_DIR}/../node/node.h
    ${map_SOURCE_DIR}/../node/node.cpp
)
target_link_libraries( map coord avl_tree )
