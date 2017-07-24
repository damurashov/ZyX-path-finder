#ifndef NODE_H
#define NODE_H

class Map::Node {
public:
    /**
     * Checks whether or not the node has a parent
     * @return Returns fIsNew
     */
    //bool isNew() const;


    /**
     * Changes mDest to the current destination point.
     * @param dest Coordinates of the destination point
     */
    static void notifyDest( const Coord& dest );


    /**
     * Algorithm routine.
     *   Sets a parent, chagnes mF, mCost and mDist!
     *   See: https://en.wikipedia.org/wiki/A*_search_algorithm
     * @param parent Parental node
     */
    void setParent( const Node* const parent );


    /**
     * See Map2d::setCost(...)
     * @param cost The cost value.
     */
    void setUserCost( const short& cost );


    /**
     * Sets fIsClosed equal true
     */
    void close();


    /**
     * Checks whether or not the current node is closed.
     * @return fIsClosed
     */
    bool isClosed();


    /**
     * @return Returns a refer to a parent node.
     */
    Node* getParent() const;


    /**
     * Algorithm routine. f(x) = g(x) + h(x)
     * @return Returns mF
     */
    unsigned getF() const;


    /**
     * Algorithm routine. Returns h(x) - distance
     * @return mDist
     */
    unsigned getDist() const;


    /**
     * Algorithm routine. Returns g(x) - cost.
     * @return Returns mCost
     */
    unsigned getCost() const;


    /**
     * Returns coordinates of the current node
     * @return returns COORD
     */
    Coord& getCoord();


    /**
     * Returns mUserCost
     * @return short mUserCost
     */
    short getUserCost();


    //void operator=( const Node& rhs );
    bool operator<( const Node& rhs );
    bool operator>( const Node& rhs );
    bool operator==( const Node& rhs );


    /**
     * @param coord Coordinates of the current node.
     */
    Node( const Coord& coord );
private:
    const Coord     COORD;
    static Coord    mDest;
    Node*           mParent;
    short           mUserCost;
    unsigned        mF;
    unsigned        mDist;
    unsigned        mCost;
    bool            fIsClosed;
    //bool            fIsNew;

    Node();
};

#endif /* end of include guard: NODE_H */
