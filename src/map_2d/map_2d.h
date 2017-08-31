#ifndef MAP_2D_H
#define MAP_2D_H

#include "map.h"

class Map2d : public Map {
public:
//private: TODO: uncomment all the viewspaces!
    const unsigned short SIZE_X;
    const unsigned short SIZE_Y;

    Map::Node*** mNodeMap; //Node* mNodeMap[ SIZE_X ][ SIZE_Y ]
    std::list<Node*> mAllocated;
//protected:
    virtual void formBorderCoords( const Coord& coord ) override;
    virtual Map::Node& getNode( const Coord& coord ) override;
    bool isWithinBorders( const Coord& coord ) override;

    Map2d();
public:
    Map2d( unsigned short x, unsigned short y );
    virtual ~Map2d();
};

#endif /* end of include guard: MAP_2D_H */
