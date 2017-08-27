#ifndef COORD_H
#define COORD_H

class Coord {
public:
    const Coord operator+( const Coord& rhs );
    const Coord operator-( const Coord& rhs );
    const Coord operator=( const Coord& rhs );
    bool operator>( const Coord& rhs );
    bool operator<( const Coord& rhs );
    bool operator==( const Coord& rhs );

    int x, y, z;

    Coord();
    Coord( const Coord& );
    Coord( const int& x, const int& y );
    Coord( const int& x,
        const int& y,
        const int& z
    );

};

#endif /* end of include guard: COORD_H */
