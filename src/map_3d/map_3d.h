#ifndef MAP_3D_H
#define MAP_3D_H

#include "map.h"

class Map3d : public Map {
private:
    const unsigned short SIZE_X;
    const unsigned short SIZE_Y;
    const unsigned short SIZE_Z;
    Map::Node**** mNodeMap; // Node* mNodeMap[x][y][z]
    std::list<Map::Node*> mAllocated;
protected:
    virtual Map::Node& getNode( const Coord& coord ) override;
    virtual void formBorderCoords( const Coord& coord ) override;
    virtual bool isWithinBorders( const Coord& coord ) override;

    Map3d();
public:
    Map3d( unsigned short x,
        unsigned short y,
        unsigned short z );
    ~Map3d();
};

#endif /* end of include guard: MAP_3D_H */
