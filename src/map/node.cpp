#include "node.h"

Map::Node() : COORD( new Coord() ) {}

Map::Node( const Coord& coord ) :
    COORD( coord ) {

    fIsClosed = false;
}

void Map::Node::notifyDest( const Coord& dest ) {
    mDest = dest;
}

void Map::Node::setParent( const Node* const parent ) {
    Coord tmpCoord = COORD - mDest;

    mParent = parent;
    mCost = ( parent -> getCost() ) + MOV_COST + mUserCost;
    // mDist:
    mDist = abs( tmpCoord.x ) + abs( tmpCoord.y ) + abs( tmpCoord.z );
    mF = mDist + mCost;
}

void Map::Node::setUserCost( const short& cost ) {
    mUserCost = cost;
}

void Map::Node::close() {
    fIsClosed = true;
}

bool Map::Node::isClosed() {
    return fIsClosed;
}

Map::Node* Map::Node::getParent() {
    return mParent;
}

unsigned Map::Node::getF() {
    return mF;
}

unsigned Map::Node::getDist() {
    return mDist;
}

unsigned Map::Node::getCost() {
    return mCost;
}

bool Map::Node::operator<( const Node& rhs ) {
    return ( mF < rhs.getF() );
}

bool Map::Node::operator>( const Node& rhs ) {
    return ( mF > rhs.getF() );
}

bool Map::Node::operator==( const Node& rhs ) {
    return ( mF == rhs.getF() );
}
