#ifndef NODE_H
#define NODE_H

//#include "coord.h"
//#include "map.h"

class Map::Node {
private:
    const Coord COORD;
    static Coord mDest;
    Node* mParent;
    short mUserCost;
    //unsigned mDist;
    unsigned mCost;
    //unsigned mF;
    bool fIsClosed;

    Node();
public:
    static void notifyDest( const Coord& dest );
    void reset();
    void close();
    void setParent( Node& parent );
    void setUserCost( const short& cost );
    Node& getParent();
    unsigned getF();
    unsigned getDist();
    unsigned getCost();
    short getUserCost();
    const Coord& getCoord();
    //bool operator==( )
    bool isParentPresent();
    bool isClosed();
    bool isObstacle();
    bool operator>( const Node& rhs );
    bool operator<( const Node& rhs );

    Node( const Coord& coord );
    ~Node();
};

//Coord Map::Node::mDest( 0, 0, 0 );

#endif /* end of include guard: NODE_H */
