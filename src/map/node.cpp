#include "node.h"

Map::Node() : COORD( new Coord() ) {}

Map::Node( const Coord& coord ) :
    COORD( coord ) {

    mUserCost = 0;
    mParent = NULL;
    fIsClosed = false;
}

void Map::Node::notifyDest( const Coord& dest ) {
    mDest = dest;
}

void Map::Node::reset() {
    mParent = NULL;
    fIsClosed = false;
    mCost = 0;
}

void Map::Node::setParent( const Node& parent ) {
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

bool Map::Node::isObstacle() {
    return mUserCost == Map::OBSTACLE ? true : false;
}

Map::Node& Map::Node::getParent() {
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

Coord& getCoord() {
    return COORD;
}

bool Map::Node::isParent() {
    return mParent == NULL ? false : true;
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
