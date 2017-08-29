#include "include_routine.h"

TEST( F_getMax, test_1 ) {
	AvlTree<SimpleTestClass> tree;

	SimpleTestClass t1( 3 );
	SimpleTestClass t2( 2 );
	SimpleTestClass t3( 4 );
	SimpleTestClass t4( 4 );

	tree.push( t1 );
	tree.push( t2 );
	tree.push( t3 );
	tree.push( t4 );

	EXPECT_EQ( 4, tree.getMax().value );
}
