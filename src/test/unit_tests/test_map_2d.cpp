#include "map_2d.h"
#include "gtest/gtest.h"

//Map2d map( 7, 7 )

TEST( Map2d, isWithinBorders ) {
    Map2d map( 7, 7 );

    bool flag1 = !map.isWithinBorders( Coord( 7, 7 ) );
    bool flag2 = map.isWithinBorders( Coord( 6, 6 ) );
    bool flag3 = !map.isWithinBorders( Coord( -1, -1 ) );
    bool flag4 = map.isWithinBorders( Coord( 0, 0 ) );
    EXPECT_TRUE( flag1 && flag2 && flag3 && flag4 );
}

TEST( Map2d, getCost_setCost_resetCost ) {
    Map2d map( 7, 7 );

    bool flag1 = ( map.getCost( Coord( 2, 2 ) ) == 0 );
    map.setCost( Coord( 2, 2 ), 1 ) ;
    map.setCost( Coord( 2, 3 ), 2 ) ;
    bool flag2 = ( map.getCost( Coord( 2, 2 )) == 1 );
    bool flag3 = ( map.getCost( Coord( 2, 3 )) == 2 );
    map.resetCost( Coord( 2, 2 ) );
    bool flag4 = ( map.getCost( Coord( 2, 2 ) ) == 0 );
    map.resetCost();
    bool flag5 = ( map.getCost( Coord( 2, 3 ) ) == 0 );
}

TEST( Map2d, addObstacle_deleteObstacle ) {
    Map2d map( 7, 7 );
    map.addObstacle( Coord( 0, 0 ) );
    map.addObstacle( Coord( 1, 1 ) );
    bool flag1 = ( map.getCost( Coord( 0, 0 ) ) == Map::OBSTACLE );
    bool flag2 = ( map.getCost( Coord( 1, 1 ) ) == Map::OBSTACLE );
    map.deleteObstacle( Coord( 0, 0 ) );
    bool flag3 = ( map.getCost( Coord( 0, 0 ) ) == 0 );
    bool flag4 = ( map.getCost( Coord( 1, 1 ) ) == Map::OBSTACLE );
    map.deleteObstacle();
    bool flag5 = ( map.getCost( Coord( 0, 0 ) ) == 0 );
    bool flag6 = ( map.getCost( Coord( 1, 1 ) ) == 0 );
    EXPECT_TRUE( flag1 && flag2 && flag3 && flag4 && flag5 && flag6 );
}
