#ifndef MAP_2D_H
#define MAP_2D_H

#include "map.h"

class Map2d : public Map {
    const short SIZE_X;
    const short SIZE_Y;

    //Node* getNode( Node* currNode, const Direction direction );
    Node* getNode( const Coord& coord );
    std::list<Node*> getBorderNodes( Node* currNode );
    void closeNode( Node* node );
    void openNode( Node* node );
    void adoptNode( Node* parent, Node* child );
    Map2d();

    Node* mNodeMap[SIZE_X][SIZE_Y] = {NULL};

public:
    std::list<Coord> getPath( const Coord& start, const Coord& dest ) override;
    void addObstacle( const Coord& coord ) override;
    void setCost( const Coord& coord, const unsigned short& cost ) override;

    Map2d( const unsigned short& x,
        const unsigned short& y);
};

#endif /* end of include guard: MAP_2D_H */
