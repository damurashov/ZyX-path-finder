#include "include_routine.h"

TEST( F_findKey, test_1 ) {
	AvlTree<SimpleTestClass> tree;

	SimpleTestClass t1( 2 );
	SimpleTestClass t2( 3 );
	SimpleTestClass t3( 4 );
	SimpleTestClass t4( -6 );
	SimpleTestClass t5( 33 );

	tree.push( t1 );
	tree.push( t2 );
	tree.push( t3 );
	tree.push( t4 );

	EXPECT_TRUE( tree.findKey( t1 ) );
	EXPECT_FALSE( tree.findKey( t5 ) );
}
