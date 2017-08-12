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
    static const int DEFAULT_COST = 0;

    class Node;

    virtual Node& getNode( const Coord& coord ) = 0; // Returns a node. Creates if the creation is needed.
    virtual std::list<Coord> getBorderCoords( const Coord& coord ) = 0;

    bool paveWay( const Coord& from, const Coord& to );
    void buildWay( const Coord& from, const Coord& to );
    void closeNode( const Coord& coord );


    /**
     * Set nodes states to default.
     */
    void reset();
    unsigned newF( const Coord& from, const Coord& to );

    AvlTree<Node> mOpened;
    AvlTree<Node> mClosed;
    std::list<Coord> mTmpResult;
    std::list<Coord> mUserCost;
    std::list<Coord> mObstacles;

public:
    struct Coord;

    /**
     * Fills in and returns mTmpResult which is a bidirectional straigt-ordered
     *   list of coordinates (struct Coord):
     *   List begin ( the start point of a route ) -> ... -> List end ( the end point of a route )
     * @param  start Start point
     * @param  dest  End point
     * @return       std::list
     */
    virtual std::list<Coord>& getPath( const Coord& start, const Coord& dest );


    /**
     * Returns the last computed path without recurring computing.
     * @return std::list
     */
    virtual std::list<Coord>& getLastPath();


    /**
     * Set default cost to every node.
     */
    virtual void resetCost();


    /**
     * Set additional cost to a node.
     * @param coord Coordinates of the node.
     */
    virtual void setCost( const Coord& coord, unsigned char cost );


    /**
     * Set default cost to a node.
     * @param coord Coordinates of the node
     */
    virtual void resetCost( const Coord& coord );


    /**
     * Get the cost of a node.
     * @param  coord Coordinates of the node.
     * @return       int
     */
    virtual int getCost( const Coord& coord );


    /**
     * Checks whether or not a node is an obstacle
     * @param  coord Coordinates of the node
     * @return       bool
     */
    virtual bool isObstacle( const Coord& coord );


    /**
     * Delete all obstacles
     */
    virtual void deleteObstacle();


    /**
     * Delete an obstacle.
     * @param coord Coordinates of the obstacle
     */
    virtual void deleteObstacle( const Coord& coord );

    /**
     * Adds an obstacle to a map
     * @param coord Coordinates of the obstacle point
     */
    virtual void addObstacle( const Coord& coord );

    Map();
    virtual ~Map();
};


#endif /* end of include guard: MAP_H */
