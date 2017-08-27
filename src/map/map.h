#ifndef MAP_H
#define MAP_H

#include "avl_tree.h"
#include "coord.h"      // TODO: implement class "Coord"
#ifndef LIST_H
    #define LIST_H
    #include <list>
#endif /* end of include guard: LIST_H */


class Map {
protected:
    static const int DEFAULT_COST = 0;
    static const int MOV_COST = 1;
    static const int OBSTACLE = -1;

    //class Node;

    virtual Node& getNode( const Coord& coord ) = 0;
    virtual void formBorderCoords( const Coord& coord ) = 0;

    bool paveWay( const Coord& from, const Coord& to );
    void formWay( const Coord& from, const Coord& to );
    void reset();
    void closeNode( const Node& node );
    void openNode( const Node& parent, const Node& child );
    unsigned newF( const Node& from, const Node& to );

    AvlTree<Node> mOpened;
    AvlTree<Node> mClosed;
    std::list<Coord> mBorderCoords;
    std::list<Coord> mTmpResult;
    std::list<Coord> mUserCost;
    std::list<Coord> mObstacles;
public:
    class Node; // TODO: Do not forget to make it protected
    static const int OBSTACLE = -1;

    std::list<Coord>& getLastPath();
    std::list<Coord>& getPath( const Coord& from, const Coord& to );
    void setCost( const Coord& coord, unsigned char cost );
    void resetCost( const Coord& coord );
    void deleteObstacle( const Coord& coord );
    void addObstacle( const Coord& coord );
    void resetCost();
    void deleteObstacle();
    int getCost( const Coord& coord );

    Map();
    virtual ~Map();
};

#include "node.h" // Implementation of the class "Node"

#endif /* end of include guard: MAP_H */
