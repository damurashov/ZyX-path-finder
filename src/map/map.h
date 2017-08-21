#ifndef MAP_H
#define MAP_H

#include "avl_tree.h"
#include "coord.h"      // TODO: implement class "Coord"

class Map {
protected:
    static const int DEFAULT_COST = 0;
    static const int MOV_COST = 1;

    class Node; // TODO: implement class "Node"

    virtual Node& getNode( const Coord& coord ) = 0;
    virtual std::list<Coord> getBorderCoords( const Coord& coord ) = 0;

    bool paveWay( const Coord& from, const Coord& to );
    void formWay( const Coord& from, const Coord& to );
    unsigned newF( const Coord& from, const Coord& to );

    AvlTree<Node> mOpened;
    AvlTree<Node> mClosed;
    std::list<Coord> mTmpResult;
    std::list<Coord> mUserCost;
    std::list<Coord> mObstacles;
public:
    static const int OBSTACLE = -1;

    std::list<Coord>& getLastPath();
    std::list<Coord>& getPath( const Coord& from, const Coord& to );
    void setCost( const Coord& coord, unsigned char cost );
    void resetCost( const Coord& coord );
    void deleteObstacle( const Coord& coord );
    void addObstacle( const Coord& coord );
    int getCost( const Coord& coord );
    void resetCost();
    void deleteObstacle();

    Map();
    ~Map();
};

#endif /* end of include guard: MAP_H */
