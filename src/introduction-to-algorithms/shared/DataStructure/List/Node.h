//
// Created by cest on 08/03/21.
//

#ifndef UABC_NODE_H
#define UABC_NODE_H

class Node {
private:
    Node* previous;
    Node* next;
public:
    Node(Node* previous, Node* next) {
        this->next = next;
        this->previous = previous;
    }
};


#endif //UABC_NODE_H
