#include "gtest/gtest.h"
#include "coord.h"

TEST( Coord, OperatorPlusX ) {
    Coord c1( 1, 1, 1 );
    Coord c2( 1, 1, 1 );
    Coord coord = c1 + c2;
    EXPECT_EQ( 2, coord.x );
}

TEST( Coord, OperatorPlusY ) {
    Coord c1( 1, 1, 1 );
    Coord c2( -1, -1, -1 );
    Coord coord = c1 + c2;
    EXPECT_EQ( 0, coord.y );
}

TEST( Coord, OperatorPlusZ ) {
    Coord c1( 1, 1, 1 );
    Coord c2( -1, -1, -1 );
    Coord coord = c1 + c2;
    EXPECT_EQ( 0, coord.z );
}

TEST( Coord, OperatorMinusX ) {
    Coord c1( 1, 1, 1 );
    Coord c2( 2, 2, 2 );
    Coord coord = c1 - c2;
    EXPECT_EQ( -1, coord.x );
}

TEST( Coord, OperatorMinusY ) {
    Coord c1( 1, 1, 1 );
    Coord c2( 2, 2, 2 );
    Coord coord = c1 - c2;
    EXPECT_EQ( -1, coord.y );
}

TEST( Coord, OperatorMinusZ ) {
    Coord c1( 1, 1, 1 );
    Coord c2( 2, 2, 2 );
    Coord coord = c1 - c2;
    EXPECT_EQ( -1, coord.z );
}

TEST( Coord, OperatorMore1 ) {
    Coord c1( 0, 0, 0 );
    Coord c2( 1, 1, 1 );
    EXPECT_TRUE( c2 > c1 );
}

TEST( Coord, OperatorMore2 ) {
    Coord c1( -1, -1, -1 );
    Coord c2( 1, 1, 1 );
    EXPECT_FALSE( c2 > c1 );
}

TEST( Coord, OperatorLess1 ) {
    Coord c1( 1, 1, 1 );
    Coord c2( 2, 2, 2 );
    EXPECT_TRUE( c1 < c2 );
}

TEST( Coord, OperatorLess2 ) {
    Coord c1( 3, 3, 3 );
    Coord c2( -3, -3, -3 );
    EXPECT_FALSE( c1 < c2 );
}

TEST( Coord, OperatorIsEqual1 ) {
    Coord c1( 0, 0, 0 );
    Coord c2( 0, 0, 0 );
    EXPECT_TRUE( c1 == c2 );
}

TEST( Coord, OperatorIsEqual2 ) {
    Coord c1( -1, -2, -1 );
    Coord c2( 1, 2, 1 );
    EXPECT_TRUE( c1 == c2 );
}

TEST( Coord, OperatorIsEqual3 ) {
    Coord c1( -1, -2, -2 );
    Coord c2( 3, 3, 3 );
    EXPECT_FALSE( c1 == c2 );
}
