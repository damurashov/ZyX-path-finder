#ifndef MAP_2D_H
#define MAP_2D_H

#include <list>
#include <set>


class Map2d {
private:
    enum class Direction { N, NE, E, SE, S, SW, W, NW };

    class Node;

    static const int OBSTACLE = -1;
    const int X_SIZE;
    const int Y_SIZE;

    Map2d();

public:

    /**
     * X, Y and some arithmetic operators
     */
    struct Coord;


    /**
     * Returns the path.
     * @param  start Start point
     * @param  dest  Destination point
     * @return       Returns the seeking path as a list.
     *                       Direct order:
     *                       getPath(...).begin() - point "from"
     *                       getPath(...).end() - point "to"
     *                       Example of usage: http://www.cplusplus.com/reference/list/
     */
    std::list<Coord> getPath( Coord start, Coord dest ) const;


    /**
     * Adds an obstacle.
     * @param coord Coordinates of the obstacle.
     */
    void addObstacle( const Coord& coord );


    /**
     * Provides an opportunity to set your own cost to a point. The higher value
     *   has been set, the less proirity the point has.
     * @param coord Coordinates
     * @param cost  Cost
     */
    void setCost( Coord coord, unsigned short cost );


    /**
     * Constructor
     * @param xSize X-axis-size of the field
     * @param ySize Y-axis-size of the field
     * @param cost  Default cost. It will be set for each point.
     */
    Map2d(
        int xSize,
        int ySize,
        unsigned short cost );

};


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
    /**
     * Changes mDest to the current destination point.
     * @param dest Coordinates of the destination point
     */
    static void notifyDest( Coord dest );


    /**
     * Algorithm routine.
     *   See: https://en.wikipedia.org/wiki/A*_search_algorithm
     * @param parent Parental node
     */
    void setParent( const Node& parent );


    /**
     * See Map2d::setCost(...)
     * @param cost The cost value.
     */
    void setUserCost( const short& cost );


    /**
     * @return Returns a refer to a parent node.
     */
    Node& getParent();


    /**
     * Algorithm routine.
     * @return Returns f(x) = h(x) + g(x)
     */
    int getHeuristic();


    /**
     * @param coord Coordinates of the current node.
     */
    Node( Coord coord );

private:
    const Coord     COORD;
    static Coord    mDest;
    Node*           mParent;
    int             mHeuristic;
    unsigned short  mUserCost;

    Node();
};

#endif /* end of include guard: MAP_2D_H */
