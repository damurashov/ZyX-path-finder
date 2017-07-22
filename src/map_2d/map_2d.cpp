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

Node* Map2d::getNode( const Coord& coord ) {
    return mNodeMap[ coord.x ][ coord.y ];
}

std::list<Node*> Map2d::getBorderNodes( Node* currNode ) {
    std::list<Node*> nodes;

    for( int xAdd = -1; xAdd <= 1; xAdd++ ) {
        for( int yAdd = -1; yAdd <= 1; yAdd++) {
            if( xAdd != 0 && yAdd != 0 ) {
                nodes.push_back( mNodeMap[ currNode -> getCoord().x + xAdd ][ currNode -> getCoord().y + yAdd ] );
            }
        }
    }

    return nodes;
}

void Map2d::openNode( const Coord& coord ) {
    Node* toCreate = getNode( coord );
    toCreate = new Node( coord );
}

void Map2d::closeNode( const Coord& coord ) {
    Node* toClose = getNode( coord );
    toClose -> close();
    mClosed.push_back( toClose );
}

void Map2d::addObstacle( const Coord& coord ) {
    getNode( coord ) -> setUserCost( OBSTACLE );
}

void Map2d::setCost( const Coord& coord, const unsigned short& cost ) {
    getNode( coord ) -> setUserCost( cost );
}
