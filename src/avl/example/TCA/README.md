# Template Cpp AVL

**TCA** is a fast and simple-to-use cpp implementation of balanced binary tree.

## Example
To use TCA with your own classes you have to implement only 2 comparsion operators (just like in the following code).
```
#include <iostream>
#include "avl_tree.h"
#include <stack>

class SimpleTestClass {
public:
	int value;

	SimpleTestClass( int value ) : value( value ) {}

    // First comparsion operator
	bool operator<( const SimpleTestClass& rhs ) {
		return this -> value < rhs.value;
	}

    // Second comparsion operator
	bool operator>( const SimpleTestClass& rhs ) {
		return this -> value > rhs.value;
	}
};
```
Now we can use it.
```
int main( void ) {
    	AvlTree<SimpleTestClass> queue;
	std::stack<SimpleTestClass> stack;

	for( int i = 0; i < 100; i++ ) {
		stack.push( SimpleTestClass( i*3 ) );
		queue.push( stack.top() );
	}
	while( ! tree.isEmpty() ) {
		std::cout << queue.popMin().value << std::endl;
	}
}
```
Take note of the variable "stack". In this example "stack" is being used as a container. AvlTree is not a container! It contains references to your objects but not objects.
