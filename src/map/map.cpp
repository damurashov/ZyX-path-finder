#include "map.h"

// ----------------- Constructors, destructors -----------------

Map::Map() {}

Map::~Map() {}

// -------------------- Protected functions --------------------

bool Map::paveWay( const Coord& from, const Coord& to ) {
    Node& current = getNode( from );

    if( from.x == to.x && from.y == to.y && from.z == to.z )
        return true;
    else if( mOpened.isEmpty() )
        return false;

    if( current.isClosed() )
        return paveWay( mOpened.popMin().getCoord(), to );
    else
        closeNode( current );

    formBorderCoords( from );

    for( auto it = mBorderCoords.begin(); it != mBorderCoords.end(); ++it ) {
        Node& border = getNode( * it );
        if( ! border.isClosed()
            && ! border.isObstacle()
            &&( ! border.isParentPresent() || newF( current, border ) < border.getF() )
        ) // end of condition
            openNode( current, border );
    }

    return paveWay( mOpened.popMin().getCoord(), to );
}

void Map::formWay( const Coord& from, const Coord& to ) {
    mTmpResult.push_front( to );
    if( !( from.x == to.x && from.y == to.y && from.z == to.z ) )
        formWay( from, getNode( to ).getParent().getCoord() );
}

void Map::reset() {
    while( ! mOpened.isEmpty() )
        mOpened.popMin().reset();
    while( ! mClosed.isEmpty() )
        mOpened.popMin().reset();
}

void Map::closeNode( Node& node ) {
    node.close();
    mClosed.push( node );
}

void Map::openNode( Node& parent, Node& child ) {
    child.setParent( parent );
    mOpened.push( child );
}

unsigned Map::newF( Node& from, Node& to ) {
    return( from.getCost() + MOV_COST + to.getUserCost() + to.getDist() );
}

// --------------------- Public functions ---------------------

std::list<Coord>& Map::getLastPath() {
    return mTmpResult;
}

std::list<Coord>& Map::getPath( const Coord& from, const Coord& to ) {
    reset();
    mTmpResult.clear();
    Node::notifyDest( to );
    mOpened.push( getNode( from ) );
    if( paveWay( from, to ) )
        formWay( from, to );
    return mTmpResult;
}

void Map::setCost( const Coord& coord, unsigned char cost ) {
    getNode( coord ).setUserCost( cost );
    mUserCost.push_back( coord );
}

void Map::resetCost( const Coord& coord ) {
    getNode( coord ).setUserCost( DEFAULT_COST );
}

void Map::deleteObstacle( const Coord& coord ) {
    getNode( coord ).setUserCost( DEFAULT_COST );
}

void Map::addObstacle( const Coord& coord ) {
    getNode( coord ).setUserCost( OBSTACLE );
    mObstacles.push_back( coord );
}

void Map::resetCost() {
    for( auto it = mUserCost.begin(); it != mUserCost.end(); ++it ) {
        resetCost( *it );
    }
    mUserCost.clear();  // TODO: Check whether or not this is the proper functions
                        // for content erasing
}

void Map::deleteObstacle() {
    for( auto it = mObstacles.begin(); it != mObstacles.end(); ++it ) {
        deleteObstacle( *it );
    }
}

int Map::getCost( const Coord& coord ) {
    return getNode( coord ).getUserCost();
}
