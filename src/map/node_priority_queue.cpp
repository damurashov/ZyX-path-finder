#include "node_priority_queue.h"

Map::NodePriorityQueue::NodePriorityQueue() : listHeader( new List() ) {
    listHeader -> next = NULL;
}

Map::NodePriorityQueue::~NodePriorityQueue() {
    // HEADER -> 1 -> 2 -> 3 -> ... -> NULL
    List* left = listHeader;
    List* right = listHeader;

    while( right = right -> next ) {
        delete left;
        left = right;
    }
}

Map::NodePriorityQueue::List( const Node& node, ListItem* next ) :
    node( &node ),
    next( next ) {}

Map::NodePriorityQueue::List() : node( NULL ), next( NULL ) {}

void Map::NodePriorityQueue::insertAfter( const Node& node, List* const item ) {
    item -> next = new List( node, item -> next );
}

void Map::NodePriorityQueue::push( const Node& node ) {
    List* ptr = listHeader;

    // if( listHeader -> next != NULL ) {
    //     while( node > ptr -> next -> node ) {
    //         ptr = ptr -> next;
    //     }
    // }

    while( ptr -> next ) {
        if( node < ptr -> next -> node || node == ptr -> next -> node ) {
            break;
        }
        ptr = ptr -> next
    }
    insertAfter( node, ptr );
}

void Map::NodePriorityQueue::clear() {
    List* left = listHeader -> next;
    List* right = listHeader ->  next;

    while( right = right -> next ) {
        delete left;
        left = right;
    }
    listHeader -> next = NULL;
}

bool Map::NodePriorityQueue::isEmpty() {
    return ( listHeader -> next == NULL );
}

Map::Node* Map::NodePriorityQueue::pop() {
    if( listHeader -> next != NULL ) {
        List* toDelete = listHeader -> next;
        Map::Node* toReturn = listHeader -> next -> node;

        listHeader -> next = listHeader -> next -> next;

        delete toDelete;
        return toReturn;
    }
    return NULL;
}
