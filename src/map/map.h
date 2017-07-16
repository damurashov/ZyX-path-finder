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


class Map {
protected:
    /**
     * Up, Down, East, West, North, South
     */
    enum class Direction {  N, NE, E, SE, S, SW, W, NW,
                            UN, UNE, UE, USE, US, USW, UW, UNW,
                            DN, DNE, DE, DSE, DS, DSW, DW, DNW };
    class Node;
    class NodePriorityQueue;

    NodePriorityQueue opened;

    static const int OBSTACLE = -1;
    static const int MOV_COST = 1;

    virtual Map();
public:
    struct Coord;

    std::list<Coord>
};


#endif /* end of include guard: MAP_H */
