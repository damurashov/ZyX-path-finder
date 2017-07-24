#include "map_3d.h"

Map3d::Map3d() :
    SIZE_X( 2 ),
    SIZE_Y( 2 ),
    SIZE_Z( 2 ) {}

Map3d::Map3d( const unsigned short& x,
    const unsigned short& y,
    const unsigned short& z ) :
    SIZE_X( x ),
    SIZE_Y( y ),
    SIZE_Z( z ) {}

Node* Map3d::createNode( const Coord& coord ) {
    mNodeMap[ coord.x ][ coord.y ][ coord.z ] = new Node( coord );
    return mNodeMap[ coord.x ][ coord.y ][ coord.z ];
}

Node* Map3d::getNode( const Coord& coord ) {
    return mNodeMap[ coord.x ][ coord.y ][ coord.z ];
}

std::list<Coord> getBorderCoord( const Coord& coord ) {
    std::list<Coord> toReturn;
    for( int xAdd = -1; xAdd <= 1; xAdd++ ) {
        for( int yAdd = -1; yAdd <= 1; yAdd++ ) {
            for( int zAdd = -1; zAdd <= 1; zAdd++ ) {
                if( coord.x + xAdd >= 0
                    && coord.y + yAdd >= 0
                    && coord.z + zAdd >= 0
                    && coord.x + xAdd < SIZE_X
                    && coord.y + yAdd < SIZE_Y
                    && coord.z + zAdd < SIZE_Z) {
                    //--
                    toReturn.push_front( Coord(
                        coord.x + xAdd,
                        coord.y + yAdd,
                        coord.z + zAdd ) );
                }
            }
        }
    }

    return toReturn;
}
