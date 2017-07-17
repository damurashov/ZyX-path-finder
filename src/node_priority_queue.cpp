#include "map_2d.h"

Map2d::NodePriorityQueue::NodePriorityQueue() : listHeader( new List() ) {
    listHeader -> next = NULL;
}

Map2d::NodePriorityQueue::~NodePriorityQueue() {
    // HEADER -> 1 -> 2 -> 3 -> ... -> NULL
    List* left = listHeader;
    List* right = listHeader;

    while( right = right -> next ) {
        delete left;
        left = right;
    }
}

Map2d::NodePriorityQueue::List( const Node& node, ListItem* next ) :
    node( &node ),
    next( next ) {}

Map2d::NodePriorityQueue::List() : node( NULL ), next( NULL ) {}

void Map2d::NodePriorityQueue::insertAfter( const Node& node, List* const item ) {
    item -> next = new List( node, item -> next );
}

void Map2d::NodePriorityQueue::push( const Node& node ) {
    List* ptr = listHeader;

    // if( listHeader -> next != NULL ) {
    //     while( node > ptr -> next -> node ) {
    //         ptr = ptr -> next;
    //     }
    // }

    while( ptr -> next ) {
        if( node <= ptr -> next -> node ) {
            break;
        }
        ptr = ptr -> next
    }
    insertAfter( node, ptr );
}

Map2d::Node* Map2d::NodePriorityQueue::pop() {
    if( listHeader -> next != NULL ) {
        List* toDelete = listHeader -> next;
        Map2d::Node* toReturn = listHeader -> next -> node;

        listHeader -> next = listHeader -> next -> next;

        delete toDelete;
        return toReturn;
    }
    return NULL;
}
