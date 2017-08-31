#include "map_2d.h"

// --------------------- Constructors, destructors ---------------------
Map2d::Map2d() : SIZE_X( 0 ), SIZE_Y( 0 ) {}

Map2d::Map2d( unsigned short x, unsigned short y ) :
    SIZE_X( x ),
    SIZE_Y( y ) {

    mNodeMap = new Map::Node**[ SIZE_X ] ;
    for( int i = 0; i < SIZE_X; i++ )
        mNodeMap[i] = new Map::Node*[ SIZE_Y ];

    for( int i = 0; i < SIZE_X; i++ )
        for( int j = 0; j < SIZE_Y; j++ )
            mNodeMap[ i ][ j ] = NULL;
}

Map2d::~Map2d() {
    for( auto it = mAllocated.begin(); it != mAllocated.end(); ++it )
        delete *it;

    for( int i = 0; i < SIZE_X; i++ )
        delete [] mNodeMap[ i ];
    delete [] mNodeMap;
}
// ------------------------ Protected methods  -------------------------

void Map2d::formBorderCoords( const Coord& coord ) {
    mBorderCoords.clear();

    for( int i = -1; i < 2; i++ )
        for( int j = -1; j < 2; j++ )
            if( !( i == 0 && j == 0 ) )
                if( isWithinBorders( Coord( coord.x + i, coord.y + j ) ) )
                    mBorderCoords.push_back( Coord( coord.x + i, coord.y + j ) );
}

Map::Node& Map2d::getNode( const Coord& coord ) {
    if( mNodeMap[ coord.x ][ coord.y ] == NULL ) {
        mNodeMap[ coord.x ][ coord.y ] = new Node( coord );
        mAllocated.push_back( mNodeMap[ coord.x ][ coord.y ] );
    }
    return *mNodeMap[ coord.x ][ coord.y ];
}

bool Map2d::isWithinBorders( const Coord& coord ) {
    if( coord.x < SIZE_X
        && coord.y < SIZE_Y
        && coord.x >= 0
        && coord.y >= 0
    )
        return true;
    return false;
}
