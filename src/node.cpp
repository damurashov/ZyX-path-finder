#include "map_2d.h"

Map2d::Coord Map2d::Node::mDest( 0, 0 );

Map2d::Node::Node( Map2d::Coord coord ) : COORD( coord ) {
    mParent = NULL;
    mUserCost = 0;
    mDist = 0;
    mCost = 0;
    mF = 0;
    fIsNew = true;
}

bool isNew() const {
    return fIsNew;
}

void Map2d::Node::notifyDest( Coord dest ) {
    mDest = dest;
}

void Map2d::Node::setParent( const Node& parent ) {
    if( fIsNew ) {
        Coord dist;

        dist = COORD - mDest;
        mDist = abs( dist.x ) + abs( dist.y );
        fIsNew = false;
    }
    mParent = &parent;
    mCost = parent.getCost() + MOV_COST + mUserCost;
    mF = mCost + mDist;
}

void Map2d::Node::setUserCost( const short& cost ) {
    mUserCost = cost;
}

Map2d::Node& Map2d::Node::getParent() const {
    return *mParent;
}

unsigned Map2d::Node::getF() const {
    return mF;
}

unsigned Map2d::Node::getDist() const {
    return mDist;
}

unsigned Map2d::Node::getCost() const {
    return mCost;
}

bool Map2d::Node::operator<( const Node& rhs ) {
    return ( mF < rhs.getF() );
}


bool Map2d::Node::operator>( const Node& rhs ) {
    return ( mF > rhs.getF() );
}

bool Map2d::Node::operator==( const Node& rhs ) {
    return ( mF == rhs.getF() );
}
