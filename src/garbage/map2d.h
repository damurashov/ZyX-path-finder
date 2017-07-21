#ifndef MAP2D_H
#define MAP2D_H

#ifndef LIST_H
#define LIST_H
#include <list>
#endif /* end of include guard: LIST_H */

// #ifndef SET_H
// #define SET_H
// #include <set>
// #endif /* end of include guard: SET_H */

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif /* end of include guard: STDLIB_H */


class Map2d {
private:
    enum class Direction { N, NE, E, SE, S, SW, W, NW };
    class Node;
    class NodePriorityQueue;

    static const int OBSTACLE = -1;
    static const int MOV_COST = 1;
    const int X_SIZE;
    const int Y_SIZE;

    // Strictly ordered priority queue of points
    //   to be checked.
    NodePriorityQueue opened;

    // TODO: What about closed points?

    Map2d();
public:

    // TODO: Pay attention on verifying user input during implementation of Map2d.

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
    void setCost( const Coord& coord, unsigned short cost );


    /**
     * Constructor
     * @param xSize X-axis-size of the field
     * @param ySize Y-axis-size of the field
     * @param cost  Default cost. It will be set for each point.
     */
    Map2d(
        int xSize,
        int ySize,
        short cost );

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
     * Checks whether or not the node had a parent
     * @return Returns fIsNew
     */
    bool isNew() const;


    /**
     * Changes mDest to the current destination point.
     * @param dest Coordinates of the destination point
     */
    static void notifyDest( Coord dest );


    /**
     * Algorithm routine.
     *   Warning: chagnes mF, mCost, fIsNew and once sets mDist!
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
    Node& getParent() const;


    /**
     * Algorithm routine. f(x) = g(x) + h(x)
     * @return Returns mF
     */
    unsigned getF() const;


    /**
     * Algorithm routine. Returns h(x) - distance
     * @return mDist
     */
    unsigned getDist() const;


    /**
     * Algorithm routine. Returns g(x) - cost.
     * @return Returns mCost
     */
    unsigned getCost() const;


    //void operator=( const Node& rhs );
    bool operator<( const Node& rhs );
    bool operator>( const Node& rhs );
    bool operator==( const Node& rhs );


    /**
     * @param coord Coordinates of the current node.
     */
    Node( const Coord& coord );
private:
    const Coord     COORD;
    static Coord    mDest;
    Node*           mParent;
    short           mUserCost;
    unsigned        mF;
    unsigned        mDist;
    unsigned        mCost;
    bool            fIsNew;

    Node();
};

class Map2d::NodePriorityQueue {
private:
    struct List {
        const Node* node;
        List* next;
        List( const Node& node, List* next );
        List();
    };


    /**
     * Inserts new node after "item"
     * @param node Node we want to insert.
     * @param item Item. The node will be inserted after it.
     */
    void insertAfter( const Node& node, List* const item );


    /**
     *  listHeader doesn't point to a node - it is just a kind of mock.
     *    HEADER -> 1 -> 2 -> ... -> NULL
     *    Emtpy list looks the following way: HEADER -> NULL
     */
    List* const listHeader;

// TODO: Реализовать деструкторы везде!
// TODO: Реализовать инициализацию констант во всех конструкторах по умолчанию.

public:
    void push( const Node& node );
    Node* pop();
    NodePriorityQueue();
    ~NodePriorityQueue();
};

#endif /* end of include guard: MAP2D_H */
