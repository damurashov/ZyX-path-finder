#ifndef COORD_H
#define COORD_H

#include "map.h"

struct Map::Coord {
    int x;
    int y;
    int z;

    Coord();
    Coord( const int& x,
        const int& y,
        const int& z);
    Coord( const int& x, const int& y );
    Coord( const Coord& coord);
    const Coord operator+( const Coord& rhs );
    const Coord operator-( const Coord& rhs );
    void operator=( const Coord& rhs );
    bool operator<( const Coord& rhs );
    bool operator>( const Coord& rhs );
    bool operator==( const Coord& rhs );
};

#endif /* end of include guard: COORD_H */
