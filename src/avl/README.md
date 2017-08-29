# Template Cpp AVL

**TCA** is a fast and simple-to-use template cpp implementation of balanced binary tree.

## Example
To use TCA with your own classes you have to implement only 2 comparsion operators (just like in the following code).
```cpp
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
```cpp
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
Take note of the variable "stack". In this example "stack" is being used as a container. AvlTree is not a container. It contains references to your objects but not objects.

## Getting started
To link TCA with your project using CMake, follow these steps.
1. Download this repository and place it in folder "TCA" (of course you can choose any name).
2. In your CMake file write the following code:
```cmake

# ... your project build routine here ...

add_subdirectory( TCA )
include_directories( TCA/avl_tree )
target_link_libraries( _MY_PROJECT avl_tree )
	# _MY_PROJECT, your_project, the_best_program_ever etc...

# ... your project build routine here ...

```

See folder **"example"** to get sample program.

## Interface
```cpp
    /**
     * Erase the whole content of the tree.
     */
    void clear();

    /**
     * Adds a pointer to an object in the tree.
     *   DOES NOT make a copy of the object!
     *
     * @param ptr A non-null pointer to a key
     */
    void push( const T* ptr );


    /**
     * Adds a new object in the tree.
     *   DOES NOT make a copy of the object!
     *
     * @param ref A reference to a key
     */
    void push( const T& ref );


    /**
     * Removes a key from the tree.
     * @param ref The key.
     */
    void removeKey( const T& ref );


    /**
     * Checks whether or not a key is present in the tree.
     * @param  ref The key.
     * @return     bool.
     */
    bool findKey( const T& ref );


    /**
     * Checks whether or not the tree is empty.
     * @return bool
     */
    bool isEmpty();


    /**
     * Returns the minimal element of the tree.
     */
    T& getMin();


    /**
     * Returns the maximal element of the tree.
     */
    T& getMax();


    /**
     * Returns the minimal element of the tree and REMOVES it from the container.
     */
    T& popMin();


    /**
     * Returns the maximal element of the tree and REMOVES it from the container.
     */
    T& popMax();

    AvlTree();
    virtual ~AvlTree();
```
