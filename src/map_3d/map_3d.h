#ifndef MAP_3D_H
#define MAP_3D_H

#include "map.h"

class Map3d : public Map {
    const unsigned SIZE_X;
    const unsigned SIZE_Y;
    const unsigned SIZE_Z;

    Map3d();

    Node* mNodeMap[ SIZE_X ][ SIZE_Y ][ SIZE_Z ] = {NULL};

protected:
    Node* createNode( const Coord& coord ) override;
    Node* getNode( const Coord& coord ) override;
    std::list<Coord> getBorderCoords( const Coord& coord) override;

public:
    Map3d( const unsigned short& x,
        const unsigned short& y,
        const unsigned short& z );
};

#endif /* end of include guard: MAP_3D_H */
