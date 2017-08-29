#include <iostream>
#include "avl_tree.h"
#include <stack>

class SimpleTestClass {
public:
	int value;
	SimpleTestClass( int value ) : value( value ) {}
	bool operator<( const SimpleTestClass& rhs ) {
		return this -> value < rhs.value;
	}
	bool operator>( const SimpleTestClass& rhs ) {
		return this -> value > rhs.value;
	}
};

int main( void ) {
    AvlTree<SimpleTestClass> tree;
	std::stack<SimpleTestClass> stack;

	for( int i = 0; i < 100; i++ ) {
		stack.push( SimpleTestClass( i*3 ) );
		tree.push( stack.top() );
	}
	while( ! tree.isEmpty() ) {
		std::cout << tree.popMin().value << std::endl;
	}
}
