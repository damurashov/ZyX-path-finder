#include "map_2d.h"
#include "map_3d.h"
#include <iostream>

Map2d map( 7, 7 );

int main( void ) {
    std::list<Coord>& path = map.getPath( Coord( 0, 0), Coord( 5, 5 ) );
    for( auto it = path.begin(); it != path.end(); ++it )
        std::cout << it -> x << "\t" << it -> y << std::endl;
}
