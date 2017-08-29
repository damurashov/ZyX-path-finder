#include "include_routine.h"

TEST( F_isEmpty, test_1 ) {
	AvlTree<int> tree;
	int value = 12;
	EXPECT_TRUE( tree.isEmpty() );
	tree.push( value );
	EXPECT_FALSE( tree.isEmpty() );
	tree.popMax();
	EXPECT_TRUE( tree.isEmpty() );
}
