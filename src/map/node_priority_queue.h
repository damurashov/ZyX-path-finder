#ifndef NODE_PRIORITY_QUEUE_H
#define NODE_PRIORITY_QUEUE_H

#include "map.h"

class Map::NodePriorityQueue {
private:
    struct List {
        const Node* node;
        List* next;
        List( const Node& node, List* next );
        List();
    };


    /**
     * Inserts new node after "item"
     * @param node Node we want to insert.
     * @param item Item. The node will be inserted after it.
     */
    void insertAfter( const Node& node, List* const item );


    /**
     *  listHeader doesn't point to a node - it is just a kind of mock.
     *    HEADER -> 1 -> 2 -> ... -> NULL
     *    Emtpy list looks the following way: HEADER -> NULL
     */
    List* const listHeader;

// TODO: Реализовать деструкторы везде!
// TODO: Реализовать инициализацию констант во всех конструкторах по умолчанию.

public:
    /**
     * Pushes a new Node-object to a priority queue.
     * @param node Node-object
     */
    void push( const Node* const node );

    /**
     * Erases the whole List
     */
    void clear();

    /**
     * Returns a pointer to a node with the highest priority.
     * @return Node*
     */
    Node* pop();


    /**
     * Checks whether or not the queue is empty. It is if listHeader -> next == NULL
     * @return listHeader -> next = NULL
     */
    bool isEmpty();

    NodePriorityQueue();
    virtual ~NodePriorityQueue();
};

#endif /* end of include guard: NODE_PRIORITY_QUEUE_H */
