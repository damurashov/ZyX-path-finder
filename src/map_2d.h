#ifndef MAP2D_H
#define MAP2D_H

#include <list>
#include <set>


class Map2d {
public:

    struct Coord;

    std::list<Coord> getPath( Coord start, Coord dest ) const;

    void addObstacle( Coord coord );

    void setCost( Coord coord, unsigned short cost );

    Map2d(
        int xSize,
        int ySize,
        unsigned short cost );

private:
    static const int OBSTACLE = -1;

    enum class Direction { N, NE, E, SE, S, SW, W, NW }
    class Node;

    const int X_SIZE;
    const int Y_SIZE;

    Map2d();

};

//Coord operator+(  )

struct Map2d::Coord {
    int x;
    int y;
    Coord( int x, int y );
    Coord( const Coord& coord);
    const Coord operator+( const Coord& rhs );
    const Coord operator-( const Coord& rhs );
    void operator=( const Coord& rhs );
    bool operator<( const Coord& rhs );
    bool operator>( const Coord& rhs );
    bool operator==( const Coord& rhs );
};

class Map2d::Node {
public:
    static void notifyDest( Coord dest );
    void setParent( const Node& parent );
    void setUserCost( const short& cost );
    Node& getParent();
    int getHeuristic();
    Node( Coord coord );

    //int getUserCost();
private:
    const Coord     COORD;
    static Coord    mDest;
    Node*           mParent;
    int             mHeuristic;
    unsigned short  mUserCost;
};

#endif /* end of include guard: MAP2D_H */
