#include "avl_tree_container.h"

/*************************************************
 *          Constructors, destructors            *
 *************************************************/

AvlTreeContainer::AvlTreeContainer() {}

AvlTreeContainer::AvlTreeContainer( int( *comp )( void*, void* ) ) :
    mRoot( NULL ),
    mComparator( comp ) {}

AvlTreeContainer::~AvlTreeContainer() {
    clear( mRoot );
}

AvlTreeContainer::AvlNode::AvlNode( void* key ) :
    height( 0 ),
    left( NULL ),
    right( NULL ) {
    keystack.push( key );
}

/************************************************
 *              Private functions               *
 ************************************************/

AvlTreeContainer::AvlNode* AvlTreeContainer::rotateLeft( AvlNode* q ) {
    AvlNode* p = q -> right;
    q -> right  = p -> left;
    p -> left = q;
    fixHeight( q );
    fixHeight( p );
    return p;
}

AvlTreeContainer::AvlNode* AvlTreeContainer::rotateRight( AvlNode* p ) {
    AvlNode* q = p -> left;
    p -> left = q -> right;
    q -> right = p;
    fixHeight( p );
    fixHeight( q );
    return q;
}

AvlTreeContainer::AvlNode* AvlTreeContainer::balance( AvlNode* node ) {
    fixHeight( node );
    if( balanceFactor( node ) == 2 ) {
        if( balanceFactor( node -> right ) < 0 )
            node -> right = rotateRight( node -> right );
        return rotateLeft( node );
    }
    if( balanceFactor( node ) == -2 ) {
        if( balanceFactor( node -> left ) > 0 )
            node -> left = rotateLeft( node -> left );
        return rotateRight( node );
    }
    return node;
}

AvlTreeContainer::AvlNode* AvlTreeContainer::getMin( AvlNode* subtree ) {
    return subtree -> left ? getMin( subtree -> left ) : subtree;
}

AvlTreeContainer::AvlNode* AvlTreeContainer::getMax( AvlNode* subtree ) {
    return subtree -> right ? getMax( subtree -> right ) : subtree;
}

AvlTreeContainer::AvlNode* AvlTreeContainer::scratchMin( AvlNode* subtree ) {
    if( ! subtree -> left )
        return subtree -> right;
    subtree -> left = scratchMin( subtree -> left );
    return balance( subtree );
}

AvlTreeContainer::AvlNode* AvlTreeContainer::insertKey( AvlNode* subtree, void* key ) {
    if( ! subtree ) {
        return new AvlNode( key );
    } else if( compare( key, subtree -> keystack.top() ) == 0 ) {
        subtree -> keystack.push( key );
        return subtree;
    } else if( compare( key, subtree -> keystack.top() ) < 0 ) {
        subtree -> left = insertKey( subtree -> left, key );
    } else { // key > subtree -> keystack.top()
        subtree -> right = insertKey( subtree -> right, key );
    }
    return balance( subtree );
}

AvlTreeContainer::AvlNode* AvlTreeContainer::removeKey( AvlNode* subtree, void* key ) {
    if( ! subtree ) {
        return NULL;
    } else if( compare( key, subtree -> keystack.top() ) < 0 ) {
        subtree -> left = removeKey( subtree -> left, key );
    } else if( compare( key, subtree -> keystack.top() ) > 0  ) {
        subtree -> right = removeKey( subtree -> right, key );
    } else {
        AvlNode* subleft = subtree -> left;
        AvlNode* subright = subtree -> right;
        AvlNode* min;

        subtree -> keystack.pop();
        if( subtree -> keystack.empty() ) {
            delete subtree;
            if( ! subright )
                return subleft;
            min = getMin( subright );
            min -> right = scratchMin( subright );
            min -> left = subleft;
            return balance( min );
        } else {
            return subtree;
        }
    }
    return balance( subtree );
}

AvlTreeContainer::AvlNode* AvlTreeContainer::findKey( AvlNode* subtree, void* key ) {
    if( ! subtree ) {
        return NULL;
    } else if( compare( key, subtree -> keystack.top() ) < 0 ) {
        return findKey( subtree -> left, key );
    } else if( compare( key, subtree -> keystack.top() ) > 0 ) {
        return findKey( subtree -> right, key );
    } else { // ==
        return subtree;
    }
}

int AvlTreeContainer::balanceFactor( AvlNode* node ) {
    return height( node -> right ) - height( node -> left );
}

int AvlTreeContainer::height( AvlNode* node ) {
    return node ? node -> height : 0;
}

int AvlTreeContainer::compare( void* lhs, void* rhs ) {
    return (*mComparator)( lhs, rhs );
}

void AvlTreeContainer::fixHeight( AvlNode* node ) {
    int l = height( node -> left );
    int r = height( node -> right );
    node -> height = ( l > r ? l : r ) + 1;
}

void AvlTreeContainer::clear( AvlNode* subtree ) {
    if( subtree ) {
        if( subtree -> left )
            clear( subtree -> left );
        if( subtree -> right )
            clear( subtree -> right );
        delete subtree;
    }
    mRoot = NULL;
}

/************************************************
 *               Public functions               *
 ************************************************/

bool AvlTreeContainer::findKey( void* key ) {
    AvlNode* node = findKey( mRoot, key );
    return node == NULL ? false : true;
}

bool AvlTreeContainer::isEmpty() {
    return mRoot == NULL ? true : false;
}

void AvlTreeContainer::push( void* key ) {
    mRoot = insertKey( mRoot, key );
}

void AvlTreeContainer::clear() {
    clear( mRoot );
}

void AvlTreeContainer::removeKey( void* key ) {
    mRoot = removeKey( mRoot, key );
}

void* AvlTreeContainer::getMin() {
    return getMin( mRoot ) -> keystack.top();
}

void* AvlTreeContainer::getMax() {
    return getMax( mRoot ) -> keystack.top();
}

void* AvlTreeContainer::popMin() {
    void* key = getMin( mRoot ) -> keystack.top();
    mRoot = removeKey( mRoot, key );
    return key;
}

void* AvlTreeContainer::popMax() {
    void* key = getMax( mRoot ) -> keystack.top();
    mRoot = removeKey( mRoot, key );
    return key;
}
