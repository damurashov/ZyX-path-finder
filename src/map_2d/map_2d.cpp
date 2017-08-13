include "map_2d.h"

//using namespace Map;

Map2d::Map2d() : SIZE_X(2), SIZE_Y(2) {}

Map2d::Map2d( const unsigned short& x,
        const unsigned short& y ) :
        SIZE_X( x ),
        SIZE_Y( y ) {}

// Node* Map2d::getNode( Node* currNode, const Direction direction ) {
//     switch( direction ) {
//     case Direction::N:
//         return mNodeMap[ currNode -> getCoord().x ][ currNode -> getCoord().y + 1 ];
//     case Direction::S:
//         return mNodeMap[ currNode -> getCoord().x ][ currNode -> getCoord().y - 1 ];
//     case Direction::E:
//         return mNodeMap[ currNode -> getCoord().x + 1 ][ currNode -> getCoord().y ];
//     case Direction::W:
//         return mNodeMap[ currNode -> getCoord().x - 1 ][ currNode -> getCoord().y ];
//     case Direction::NE:
//         return mNodeMap[ currNode -> getCoord().x + 1 ][ currNode -> getCoord().y + 1 ];
//     case Direction::SE:
//         return mNodeMap[ currNode -> getCoord().x + 1 ][ currNode -> getCoord().y - 1 ];
//     case Direction::SW:
//         return mNodeMap[ currNode -> getCoord().x - 1 ][ currNode -> getCoord().y - 1 ];
//     case Direction::NW:
//         return mNodeMap[ currNode -> getCoord().x - 1 ][ currNode -> getCoord().y + 1 ];
//     }
// }

Node* Map2d::createNode( const Coord& coord ) {
    mNodeMap[ coord.x ][ coord.y ] = new Node( coord );
    return mNodeMap[ coord.x ][ coord.y ];
}

Node* Map2d::getNode( const Coord& coord ) {
    return mNodeMap[ coord.x ][ coord.y ];
}

std::list<Coord> Map2d::getBorderCoords( const Coord& coord ) {
    std::list<Coord> toReturn;

    for( int xAdd = -1; xAdd <= 1; xAdd++ ) {
        for( int yAdd = -1; yAdd <= 1; yAdd++ ) {
            if( coord.x + xAdd >= 0
                && coord.y + yAdd >= 0
                && coord.x + xAdd < SIZE_X
                && coord.y + yAdd < SIZE_Y ) {
                //--
                toReturn.push_front( Coord( coord.x + xAdd, coord.y + yAdd ) );
            }
        }
    }

    return toReturn;
}
