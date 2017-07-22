#include "map.h"

Map::Map() {}

Map::~Map() {}

void Map::getPath( const Coord& start, const Coord& end ) {
    Node* currNode;
    std::list<Coord> buf;

    // Check whether or not the start point is an obstacle
    if( getNode( start ) == NULL ) {
        currNode = createNode( start );
    } else if( getNode( start ) -> getCost() == OBSTACLE || getNode( end ) -> getCost() == OBSTACLE ) {
        return mTmpResult;
    }

    // Open border nodes for the start point
    buf = getBorderCoords( start );
    for( auto it = buf.begin(); it != buf.end(); ++it ) {
        if( getNode( *it ) != NULL ) {
            if( getNode( *it ) -> getCost() != OBSTACLE ) {
                mOpened.push( getNode( *it ) );
            }
        } else {
            mOpened.push( createNode( *it ) );
            getNode( *it ) -> setParent( currNode );
        }
    }

    // Main loop.
    while( !( currNode -> getCoord() == end ) && !( mOpened.isEmpty() ) ) {
        // 1. ------------------------ Step to the cheapest node
        currNode = mOpened.push();
        closeNode( currNode );

        // 2. ------------------------ Open border nodes
        buf = getBorderCoords( currNode -> getCoord() );

        for( auto it = buf.begin(); it != buf.end(); ++it ) {
            // If ptr is NULL
            if( getNode( *it ) == NULL ) {
                mOpened.push( createNode( *it ) );
                getNode( *it ) -> setParent( currNode );
            // Otherwise check if there's an opportunity to set the current node
            //   as a parent to the current border node
            } else if( ! currNode -> isClosed()
                && ! currNode -> getCost() == OBSTACLE
                && estF( currNode, getNode( *it ) ) < getNode( *it ) -> getF() ) {
        // 3. ------------------------ Set parent
                getNode( *it ) -> setParent( currentNode );
            }
        }

    }

    // Form the path
    if( getNode( end ) != NULL ) {
        if( getNode( end ) -> getParent() != NULL ) {
            currNode = getNode( end );
            mTmpResult.push_front( currNode -> getCoord() );
            while( ! currNode -> getCoord() == getNode( start ) -> getCoord() ) {
                currNode = currNode -> getParent();
                mTmpResult.push_front( currNode -> getCoord() );
            }
        }
    }
}
