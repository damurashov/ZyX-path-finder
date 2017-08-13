#include "map.h"

/*************************************************
 *          Constructors, descructors            *
 *************************************************/

 Map::Map() {}

 Map::~Map() {}

/*************************************************
 *              Protected functions              *
 *************************************************/

bool Map::paveWay( const Coord& from, const Coord& to ) {
    std::list<Coord> border

    if( from == to )
        return true;
    else if( mOpened.isEmpty() )
        return false;

    // Since the tree "mOpened" can contain pointers to equal nodes, there is an
    //   opportunity to receive a node that have already
    //   been closed. It means all the nodes that borders to the received one have already
    //   been created and "adopted", and there is no need to do the same again.
    if( ! getNode( from ).isClosed() )
        closeNode( from );
    else    // Otherwise there's no need to check border nodes again.
        return paveWay( mOpened.popMin().getCoord(), to );

    border = getBorderCoords( from );
    for( auto it = border.begin(); it != border.end(); ++it ) { // Bypass all the "neighbours"
        Node& node = getNode( *it );
        if( !( node.isObstacle() || node.isClosed() ) ) {
            if( ! node.isParent() ) {
                node.setParent( getNode( from ) );
                mOpened.push( node );
            } else if ( newF( from, to ) < node.getF() ) {
                node.setParent( getNode( from ) );
                mOpened.push( node );   // That is why there is an opportunity
                                        //   to push "twins" in the tree.
                                        //   We set a new parent to a node and
                                        //   push the node in the tree one more
                                        //   time.
            }
        }
    }

    return paveWay( mOpened.popMin().getCoord(), to );
}

void Map::buildWay( const Coord& from, const Coord& to ) {
    if( from == to ) {
        mTmpResult.push_front( getNode( from ).getCoord() );
        return;
    }
    mTmpResult.push_front( getNode( to ).getCoord() );
    buildWay( from, getNode( to ).getParent().getCoord() );
}

void Map::closeNode( const Coord& coord ) {
    getNode( coord ).close();
    mClosed.push( getNode( coord ) );
}

void Map::reset() {
    while( ! mClosed.isEmpty() )
        mClosed.popMin().reset();
    while( ! mOpened.isEmpty() )
        mOpened.popMin().reset();
}

/***********************************************************
 *                      Public functions                   *
 ***********************************************************/

std::list<Coord>& Map::getPath( const Coord& from, const Coord& to ) {
    Node::notifyDest( to );
    mTmpResult.clear();
    mOpened.push( getNode( from ) );
    if( paveWay( from, to ) )
        buildWay( from, to );
    reset();
    return mTmpResult;
    // TODO: Clear all the nodes.
}

std::list<Coord>& Map::getLastPath() {
    return mTmpResult;
}

void Map::resetCost() {
    for( auto it = mUserCost.begin(); it != mUserCost.end(); ++it )
        getNode( *it ).setUserCost( DEFAULT_COST );
    mUserCost.clear();
}

void Map::setCost( const Coord& coord, unsigned char cost ) {
    getNode( coord ).setUserCost( cost );
    mUserCost.push_back( coord );
}

void Map::resetCost( const Coord& coord ) {
    getNode( coord ).setUserCost( DEFAULT_COST );
}

int Map::getCost( const Coord& coord ) {
    return getNode( coord ).getUserCost();
}

bool Map::isObstacle( const Coord& coord ) {
    return getNode( coord ).isObstacle();
}

void Map::deleteObstacle() {
    for( auto it = mObstacles.begin(); it != mObstacles.end(); ++it )
        getNode( *it ).setUserCost( DEFAULT_COST );
}

void Map::deleteObstacle( const Coord& coord ) {
    getNode( coord ).setUserCosT( DEFAULT_COST );
}

void Map::addObstacle( const Coord& coord ) {
    mObstacles.push_back( coord );
    getNode( coord ).setUserCost( OBSTACLE );
}
