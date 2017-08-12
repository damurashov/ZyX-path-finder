// TODO: Reset and null-init
// TODO: List of closed
//

#ifndef MAP_H
#define MAP_H

#ifndef LIST_H
#define LIST_H
#include <list>
#endif /* end of include guard: LIST_H */

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif /* end of include guard: STDLIB_H */

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif /* end of include guard: STDLIB_H */

#ifndef COORD_H
#define COORD_H
#include "coord.h"
#endif /* end of include guard: COORD_H */

#ifndef AVL_TREE_H
#define AVL_TREE_H
#include "avl_tree.h"
#endif /* end of include guard: AVL_TREE_H */



class Map {
protected:
    static const int OBSTACLE = -1;
    static const int MOV_COST = 1;

    class Node;

    virtual Node* createNode( const Coord& coord ) = 0;
    virtual Node* getNode( const Coord& coord ) = 0;
    virtual std::list<Node*> getBorderCoords( const Coord& coord ) = 0;

    /**
     * Returns estimated F for "B" after step from "A" to "B"
     * @param  from A
     * @param  to   B
     * @return      cost( A ) + cost( STEP ) + userCost( B ) + distance( B )
     */
    unsigned estF( const Node* const from, const Node* const to );

    /**
     * Adds node to mClosed and calls "node -> close()"
     * @param node Node to be closed
     */
    void closeNode( Node* const node );

    AvlTree<Node> mOpened;
    AvlTree<Node> mClosed;
    std::list<Coord> mTmpResult;

public:
    struct Coord;

    /**
     * Fills in and returns mTmpResult which is a bidirectional straigt-ordered
     *   list of coordinates (struct Coord):
     *   List begin ( the start point of a route ) -> ... -> List end ( the end point of a route )
     * @param  start Start point
     * @param  dest  End point
     * @return       mTmpResult
     */
    virtual std::list<Coord> getPath( const Coord& start, const Coord& dest );

    /**
     * Adds an obstacle to a map
     * @param coord Coordinates of the obstacle point
     */
    virtual void addObstacle( const Coord& coord );

    /**
     * Adds additional cost to some vertex
     * @param coord The vertex coordinates
     * @param cost  The vertex cost
     */
    virtual void setCost( const Coord& coord, const unsigned short& cost );


    /**
     * After the path is computed, there is no need to the same path again.
     * @return Returns mTmpResult
     */
    std::list<Coord> getPrevPath();


    Map();
    virtual ~Map();
};


#endif /* end of include guard: MAP_H */
