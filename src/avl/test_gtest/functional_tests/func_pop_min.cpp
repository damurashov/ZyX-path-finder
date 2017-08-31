#include "include_routine.h"

TEST( F_popMin, test_1 ) {
	AvlTree<SimpleTestClass> tree;

	SimpleTestClass t1( 3 );
	SimpleTestClass t2( 2 );
	SimpleTestClass t3( 2 );
	SimpleTestClass t4( 4 );

	tree.push( t1 );
	tree.push( t2 );
	tree.push( t3 );
	tree.push( t4 );

	EXPECT_EQ( 2, tree.popMin().value );
	EXPECT_EQ( 2, tree.popMin().value );
	EXPECT_EQ( 3, tree.popMin().value );
}
