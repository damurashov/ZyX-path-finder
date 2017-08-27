//#include "node.h"
#include "map.h"

#ifndef CSTDLIB_H
#define CSTDLIB_H
#include <cstdlib>
#endif /* end of include guard: CSTDLIB_H */

// ------------------ Constructors, destructors ------------------

Map::Node::Node() : COORD( -1, -1, -1 ) {}

Map::Node::Node( const Coord& coord ) : COORD( coord ) {
    mParent = NULL;
    mUserCost = Map::DEFAULT_COST;
    mDist = 0;
    mCost = 0;
    mF = 0;
    fIsClosed = false;
}

Map::Node::~Node() {}

// ----------------------- Public functions -----------------------

void Map::Node::notifyDest( const Coord& coord ) {
    mDest = coord;
}

void Map::Node::reset() {
    mParent = NULL;
    mDist = 0;
    mCost = 0;
    mF = 0;
    fIsClosed = false;
}

void Map::Node::close() {
    fIsClosed = true;
}

void Map::Node::setParent( const Node& parent ) {
    mParent = &parent;
    mCost = parent.getCost() + Map::MOV_COST + getUserCost();
}

void Map::Node::setUserCost( const short& cost ) {
    mUserCost = cost;
}

Node&  Map::Node::getParent() {
    return *mParent;
}

Coord& getCoord() {
    return COORD;
}

unsigned  Map::Node::getF() {
    return getDist() + getCost();
}

unsigned  Map::Node::getDist() {
    Coord vector( mDest - COORD );
    return( abs( vector.x ) + abs( vector.y ) + abs( vector.z ) );
}

unsigned  Map::Node::getCost() {
    return mCost;
}

unsigned  Map::Node::getUserCost() {
    return mUserCost;
}

bool  Map::Node::isParentPresent() {
    return mParent == NULL ? false : true;
}

bool  Map::Node::isClosed() {
    return fIsClosed;
}

bool Map::Node::isObstacle() {
    return mUserCost == Map::OBSTACLE ? true : false;
}

bool Map::Node::operator>( const Node& rhs ) {
    return getF() > rhs.getF();
}

bool Map::Node::operator<( const Node& rhs ) {
    return getF() < rhs.getF();
}
