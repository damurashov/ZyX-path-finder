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
            &&( ! border.isParentPresent() || newF( from, to ) < border.getF() )
        ) // end of condition
            openNode( current, border );
    }

    return paveWay( mOpened.popMin().getCoord(), to );
}

void formWay( const Coord& from, const Coord& to ) {
    mTmpResult.push_front( to );
    if( !( from.x == to.x && from.y == to.y && form.z == to.z ) );
        formWay( from, getNode( to ).getParent().getCoord() );
}

void reset() {
    while( ! mOpened.isEmpty() )
        mOpened.popMin().reset();
    while( ! mClosed.isEmpty() )
        mOpened.popMin().reset();
}
