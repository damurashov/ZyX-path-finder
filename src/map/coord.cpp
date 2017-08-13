#include "coord.h"

Coord() : x(0), y(0), z(0) {}

Coord(
    const int& x,
    const int& y,
    const int& z ) :
    x(x), y(y), z(z) {}

Coord( const int& x, const int& y ) :
    x(x), y(y), z(0) {};

Coord( const Coord& coord ) {
    x = coord.x;
    y = coord.y;
    z = coord.z;
}

Coord::operator+( const Coord& rhs ) {
    return Coord( x + rhs.x, y + rhs.y, z + rhs.z);
}

Coord Coord::operator-( const Coord& rhs ) {
    return Coord( x - rhs.x, y - rhs.y, z - rhs.z );
}

void Coord::operator=( const Coord& rhs ) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
}

bool Coord::operator<( const Coord& rhs ) {
    if( (long) x + (long) y + (long) z < (long) rhs.x + (long) rhs.y + (long) rhs.z )
        return true;
    return false;
}

bool Coord:operator>( const Coord& rhs ) {
    if( (long) x + (long) y + (long) z > (long) rhs.x + (long) rhs.y + (long) rhs.z )
        return true;
    return false;
}

bool Coord::operator==( const Coord& rhs ) {
    if( (long) x + (long) y + (long) z == (long) rhs.x + (long) rhs.y + (long) rhs.z )
        return true;
    return false;
}
