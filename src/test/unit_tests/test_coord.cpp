#include "gtest/gtest.h"
#include "coord.h"

TEST( Coord, operatorMinus ) {
    Coord c1( 1, 0, 3 );
    Coord c2( -1, 12, -36 );
    Coord c = c1 - c2;
    EXPECT_TRUE( c.x == 2 && c.y == -12 && c.z == 39 );
}

TEST( Coord, operatoPlus ) {
    Coord c1( -222, 100, 300 );
    Coord c2( 1, 1 );
    Coord c = c1 + c2;
    EXPECT_TRUE( c.x == -221 && c.y == 101 && c.z == 300 );
}

TEST( Coord, operatorAssign ) {
    Coord c1;
    Coord c2( 2, 2, 2 );
    c2 = c1;
    EXPECT_TRUE( c2.x == 0 && c2.y == 0 && c2.z == 0 );
}

TEST( Coord, operatorMore ) {
    Coord c1( 0, 0, 0 );
    Coord c2( 1, 1, 1 );
    EXPECT_TRUE( c2 > c1 );
}

TEST( Coord, operatorLess ) {
    Coord c1( -1, 0, 0 );
    Coord c2( 1, 1, 1 );
    EXPECT_TRUE( c1 < c2 );
}

TEST( Coord, operatorEqual ) {
    Coord c1( -1, 1, 1 );
    Coord c2( 1, -1, -1 );
    EXPECT_TRUE( c1 == c2 );
}
