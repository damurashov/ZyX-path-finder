project( avl_tree_container )
file( GLOB SOURCE_FILES *.cpp )
file( GLOB HEADER_FILES *.h )
add_library(
    avl_tree
    ${SOURCE_FILES}
    ${HEADER_FILES}
)
