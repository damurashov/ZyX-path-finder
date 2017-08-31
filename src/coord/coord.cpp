#include "coord.h"

#ifndef CSTDLIB_H
#define CSTDLIB_H
#include <cstdlib>
#endif /* end of include guard: CSTDLIB_H */


// ---------------- Constructors, destructors ----------------
Coord::Coord() : x( 0 ), y( 0 ), z( 0 ) {}

Coord::Coord( const Coord& coord ) :
    x( coord.x ),
    y( coord.y ),
    z( coord.z ) {}

Coord::Coord( const int& x, const int& y ) : x( x ), y( y ), z( 0 ) {}

Coord::Coord(
    const int& x,
    const int& y,
    const int& z ) : x( x ), y( y ), z( z ) {}

// -------------------- Public functions --------------------

const Coord Coord::operator+( const Coord& rhs ) {
    return Coord( x + rhs.x,
        y + rhs.y,
        z + rhs.z
    );
}

const Coord Coord::operator-( const Coord& rhs ) {
    return Coord( x - rhs.x,
        y - rhs.y,
        z - rhs.z
    );
}

const Coord Coord::operator=( const Coord& rhs ) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
}

bool Coord::operator>( const Coord& rhs ) {
    return( abs( x ) + abs( y ) + abs( z ) > abs( rhs.x ) + abs( rhs.y ) + abs( rhs.z ) );
}

bool Coord::operator<( const Coord& rhs ) {
    return( abs( x ) + abs( y ) + abs( z ) < abs( rhs.x ) + abs( rhs.y ) + abs( rhs.z ) );
}

bool Coord::operator==( const Coord& rhs ) {
    return( abs( x ) + abs( y ) + abs( z ) == abs( rhs.x ) + abs( rhs.y ) + abs( rhs.z ) );
}
