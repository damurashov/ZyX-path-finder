#ifndef AVL_TREE_CONTAINER_H
#define AVL_TREE_CONTAINER_H

#ifndef STACK_H
#define STACK_H
#include <stack>
#endif /* end of include guard: STACK_H */

class AvlTreeContainer {
private:
    struct AvlNode {
        std::stack<void*> keystack;
        int height;
        AvlNode* left;
        AvlNode* right;
        AvlNode( void* key );
    };

    AvlNode* rotateLeft( AvlNode* node );
    AvlNode* rotateRight( AvlNode* node );
    AvlNode* balance( AvlNode* node );
    AvlNode* getMin( AvlNode* subtree );
    AvlNode* getMax( AvlNode* subtree );
    AvlNode* scratchMin( AvlNode* subtree );
    AvlNode* insertKey( AvlNode* subtree, void* key );
    AvlNode* removeKey( AvlNode* subtree, void* key );
    AvlNode* findKey( AvlNode* subtree, void* key );
    int balanceFactor( AvlNode* node );
    int height( AvlNode* node );
    int compare( void* lhs, void* rhs );
    void fixHeight( AvlNode* node );
    void clear( AvlNode* subtree );
    AvlTreeContainer();

    AvlNode* mRoot;
    int( *mComparator )( void*, void* );

public:
    bool findKey( void* key );
    bool isEmpty();
    void clear();
    void push( void* key );
    void removeKey( void* key );
    void* getMin();
    void* getMax();
    void* popMin();
    void* popMax();

    AvlTreeContainer( int (*comparator)(void*, void*) );
    virtual ~AvlTreeContainer();
};
#endif /* end of include guard: AVL_TREE_CONTAINER_H */
