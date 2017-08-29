#include "gtest/gtest.h"
#include "map.h"

TEST( Node, createNodeObject ) {
    Map::Node node( Coord( 1, 1, 1 ) );
    //node.getDist();
    node.isParentPresent();
}

TEST( Node, notifyDest ) {
    Map::Node node( Coord( 3, 3 ) );
    Map::Node::notifyDest( Coord( 3, 3 ) );
    EXPECT_EQ( node.getDist(), 0 );
}

TEST( Node, setParent_isParentPresent ) {
    bool flag1, flag2;

    Map::Node parent( Coord( -13, -13 ) );
    Map::Node child( Coord::Coord() );

    //child.isParentPresent();
    flag1 = (! child.isParentPresent() );
    child.setParent( parent );
    flag2 = child.isParentPresent();
    EXPECT_TRUE( flag1 && flag2 );
}

TEST( Node, setParent_getParent ) {
    Map::Node parent( Coord( -13, -13 ) );
    Map::Node child( Coord::Coord() );
    child.setParent( parent );
    EXPECT_EQ( -13, child.getParent().getCoord().x );
}

TEST( Node, setUserCost_getUserCost ) {
    Map::Node node( Coord::Coord() );
    node.setUserCost( 12 );
    EXPECT_EQ( node.getUserCost(), 12 );
}

TEST( Node, close_isClosed ) {
    bool flag1;
    bool flag2;
    Map::Node node( Coord::Coord() );
    flag1 = !node.isClosed();
    node.close();
    flag2 = node.isClosed();
    EXPECT_TRUE( flag1 && flag2 );
}

TEST( Node, getDist ) {
    Map::Node node( Coord( 1, 2, 3 ) );
    Map::Node::notifyDest( Coord( -1, -12, -3 ) );
    EXPECT_EQ( 2 + 14 + 6, node.getDist() );
}

TEST( Node, getCost ) {
    Map::Node parent( Coord::Coord() );
    Map::Node child( Coord( 1, 1, 1 ) );
    child.setUserCost( 2 );
    child.setParent( parent );
    EXPECT_EQ( 3, child.getCost() );
}

TEST( Node, isObstacle ) {
    Map::Node node( Coord::Coord() );
    node.setUserCost( Map::OBSTACLE );
    EXPECT_TRUE( node.isObstacle() );
}

TEST( Node, getF ) {
    Map::Node parent( Coord::Coord() );
    Map::Node child( Coord( 1, 2, 3 ) );
    Map::Node::notifyDest( Coord( 3, 3, 3 ) );
    child.setParent( parent );
    EXPECT_EQ( 4, child.getF() );
}

TEST( Node, getCoord ) {
    Map::Node node( Coord( 2, 2, 2 ) );
    EXPECT_EQ( 6, node.getCoord().x + node.getCoord().y + node.getCoord().z );
}

TEST( Node, reset ) {
    Map::Node parent( Coord::Coord() );
    Map::Node child( Coord( 1, 2, 3 ) );
    Map::Node::notifyDest( Coord( 3, 3, 3 ) );
    child.setUserCost( 5 );
    child.close();
    child.reset();
    bool flag1 = !child.isParentPresent();
    bool flag2 = ( child.getCost() == 0 );
    bool flag3 = ( child.getUserCost() == 5 );
    bool flag4 = ( child.getCoord().x == 1 );
    bool flag5 = !child.isClosed();
    bool flag6 = ( child.getDist() == 3 );
    EXPECT_TRUE( flag1 && flag2 && flag3 && flag4 && flag5 && flag6 );
}

TEST( Node, operatorMore ) {
    Map::Node parent( Coord::Coord() );
    Map::Node child( Coord( 1, 2, 3 ) );
    Map::Node::notifyDest( Coord( 3, 3, 3 ) );
    child.setParent( parent );
    EXPECT_TRUE( parent > child );
}

TEST( Node, operatorLess) {
    Map::Node parent( Coord::Coord() );
    Map::Node child( Coord( 1, 2, 3 ) );
    Map::Node::notifyDest( Coord( 3, 3, 3 ) );
    child.setParent( parent );
    EXPECT_TRUE( child < parent );
}
