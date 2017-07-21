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

class Map {
protected:
    static const int OBSTACLE = -1;
    static const int MOV_COST = 1;

    /**
     * Up, Down, East, West, North, South
     */
    enum class Direction {  N, NE, E, SE, S, SW, W, NW,             // 2D
                            UN, UNE, UE, USE, US, USW, UW, UNW,     // 3D
                            DN, DNE, DE, DSE, DS, DSW, DW, DNW };
    class Node;
    class NodePriorityQueue;

    NodePriorityQueue mOpened;      // Algorithm routine - contains
                                    //   opened vertices as a priority queue
    std::list<Coord> mTempResult;   // Contains the last computed result

public:
    struct Coord;

    /**
     * Fills in and returns mTmpResult which is a bidirectional straigt-ordered
     *   list of coordinates (class Coord):
     *   List begin ( the start point of a route ) -> ... -> List end ( the end point of a route )
     * @param  start Start point
     * @param  dest  End point
     * @return       mTmpResult
     */
    virtual std::list<Coord>& getPath( const Coord& start, const Coord& dest ) = 0;

    /**
     * Adds an obstacle to a map
     * @param coord Coordinates of the obstacle point
     */
    virtual void addObstacle( const Coord& coord ) = 0;

    /**
     * Adds additional cost to some vertex
     * @param coord The vertex coordinates
     * @param cost  The vertex cost
     */
    virtual void setCost( const Coord& coord, const unsigned short& cost ) = 0;

    Map();
    virtual ~Map();
};


#endif /* end of include guard: MAP_H */
