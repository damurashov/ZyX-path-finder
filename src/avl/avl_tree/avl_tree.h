/*
 *  AvlTree is a template class which is being used as a facade or a
 *  wrapper for AvlTreeContainer in order to provide a simple interface
 *  for an end-up user.
 */

#ifndef AVL_TREE_H
#define AVL_TREE_H

// #ifndef STACK_H
// #define STACK_H
// #include <stack>
// #endif /* end of include guard: STACK_H */

#include "avl_tree_container.h"
//#define template ## < ## typename T ## >    template< typename T >
//#define AvlTree## < ## T ## >                    AvlTree< T >

/***************************************************************
 *                        Declaration                          *
 ***************************************************************/

template < typename T >
class AvlTree {
public:
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

private:
    static int compare( void* lhs, void* rhs );

    AvlTreeContainer tree;
    //std::stack<const T&> stack;
};

/***************************************************************
 *                       Implementation                        *
 ***************************************************************/

template< typename T >
void AvlTree<T>::clear() {
    tree.clear();
}


template< typename T >
void AvlTree< T >::push( const T* ptr ) {
    if( ptr )
        tree.push( static_cast<void*>( const_cast<T*>( ptr ) ) );
}

template< typename T >
void AvlTree< T >::push( const T& ref ) {
    //stack.push( ref );
    tree.push( static_cast<void*>( const_cast<T*>( &ref ) ) );
}

template< typename T >
void AvlTree< T >::removeKey( const T& ref ) {
    tree.removeKey( static_cast<void*>( const_cast<T*>( &ref ) ) );
}

template< typename T >
bool AvlTree< T >::findKey( const T& ref ) {
    return tree.findKey( static_cast<void*>( const_cast<T*>( &ref ) ) );
}

template< typename T >
bool AvlTree< T >::isEmpty() {
    return tree.isEmpty();
}

template< typename T >
T& AvlTree< T >::getMin() {
    return *( static_cast<T*>( tree.getMin() ) );
}

template< typename T >
T& AvlTree< T >::getMax() {
    return *( static_cast<T*>( tree.getMax() ) );
}

template< typename T >
T& AvlTree< T >::popMin() {
    return *( static_cast<T*>( tree.popMin() ) );
}

template< typename T >
T& AvlTree< T >::popMax() {
    return *( static_cast<T*>( tree.popMax() ) );
}

template< typename T >
AvlTree< T >::AvlTree() : tree( compare /* int(void*,void*) */ ) {}

template< typename T >
AvlTree< T >::~AvlTree() {}

template< typename T >
int AvlTree< T >::compare( void* lhs, void* rhs ) {
    T* l = static_cast<T*>( lhs );
    T* r = static_cast<T*>( rhs );

    if( *l < *r )
        return -1;
    else if( *l > *r )
        return 1;
    else // r == l
        return 0;
}

#endif /* end of include guard: AVL_TREE_H */
