#include "map_2d.h"

Map2d::Coord::Coord( int x, int y ) :
    x(x), y(y) {}

Map2d::Coord::Coord( const Coord& coord ) {
    x = coord.x;
    y = coord.y;
}

Map2d::Coord Map2d::Coord::operator+( const Coord& rhs ) {
    return Coord( x + rhs.x, y + rhs.y);
}

Map2d::Coord Map2d::Coord::operator-( const Coord& rhs ) {
    return Coord( x - rhs.x, y - rhs.y);
}

void Map2d::Coord::operator=( const Coord& rhs ) {
    x = rhs.x;
    y = rhs.y;
}

bool Map2d::Coord::operator<( const Coord& rhs ) {
    if( ( x < rhs.x ) ||  ( x == rhs.x && y < rhs.y ) )
        return true;
    return false;
}

bool Map2d::Coord:operator>( const Coord& rhs ) {
    if( ( x > rhs.x ) || ( x == rhs.x && y > rhs.y ) )
        return true;
    return false;
}

bool Map2d::Coord::operator==( const Coord& rhs ) {
    if( x == rhs.x && y = rhs.y )
        return true;
    return false;
}
