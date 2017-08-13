#ifndef MAP_2D_H
#define MAP_2D_H

#include "map.h"

class Map2d : public Map {
    const unsigned SIZE_X;
    const unsigned SIZE_Y;

    //Node* getNode( Node* currNode, const Direction direction );
    Map2d();

    Node* mNodeMap[ SIZE_X ][ SIZE_Y ] = {NULL};

protected:
    Node* createNode( const Coord& coord ) override;
    Node* getNode( const Coord& coord ) override;
    std::list<Coord> getBorderCoords( const Coord& coord) override;

public:
    Map2d( const unsigned short& x,
        const unsigned short& y);
};

#endif /* end of include guard: MAP_2D_H */
