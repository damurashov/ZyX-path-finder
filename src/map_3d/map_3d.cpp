#include "map_3d.h"

// --------------------- Constructors, destructors  ---------------------

Map3d::Map3d() : SIZE_X( 0 ), SIZE_Y( 0 ), SIZE_Z( 0 ) {}

Map3d::Map3d( unsigned short x,
    unsigned short y,
    unsigned short z ) :
    SIZE_X( x ),
    SIZE_Y( y ),
    SIZE_Z( z ) {

    mNodeMap = new Map::Node***[ SIZE_X ];
    for( int i = 0; i < SIZE_X; i ++ ) {
        mNodeMap[ i ] = new Map::Node**[ SIZE_Y ];
        for( int j = 0; j < SIZE_Y; j++ )
            mNodeMap[ i ][ j ] = new Map::Node*[ SIZE_Z ];
    }

    for( int i = 0; i < SIZE_X; i++ )
        for( int j = 0; j < SIZE_Y; j++ )
            for( int k = 0; k < SIZE_Z; k++ )
                mNodeMap[ i ][ j ][ k ] = NULL;
}

Map3d::~Map3d() {
    for( auto it = mAllocated.begin(); it != mAllocated.end(); ++it )
        delete *it;

    for( int i = 0; i < SIZE_X; i++ ) {
        for( int j = 0; j < SIZE_Y; j++ )
            delete [] mNodeMap[ i ][ j ];
        delete [] mNodeMap[ i ];
    }
    delete [] mNodeMap;
}

// ------------------------- Protected methods  -------------------------

Map::Node& Map3d::getNode( const Coord& coord ) {
    if( mNodeMap[ coord.x ][ coord.y ][ coord.z ] == NULL ) {
        mNodeMap[ coord.x ][ coord.y ][ coord.z ] = new Node( coord );
        mAllocated.push_back( mNodeMap[ coord.x ][ coord.y ][ coord.z ] );
    }
    return *mNodeMap[ coord.x ][ coord.y ][ coord.z ];
}

void Map3d::formBorderCoords( const Coord& coord ) {
    mBorderCoords.clear();

    for( int i = -1; i < 2; i++ )
        for( int j = -1; j < 2; j++ )
            for( int k = -1; k < 2; k++ )
                if( !( i == j && j == k && k == i )
                    && isWithinBorders( coord )
                )
                    mBorderCoords.push_back( Coord( coord.x + i,
                        coord.y + j,
                        coord.z + k )
                    );
}

bool Map3d::isWithinBorders( const Coord& coord ) {
    if( coord.x < SIZE_X
        && coord.y < SIZE_Y
        && coord.z < SIZE_X
        && coord.x >= 0
        && coord.y >= 0
        && coord.z >= 0
    )
        return true;
    return false;
}
