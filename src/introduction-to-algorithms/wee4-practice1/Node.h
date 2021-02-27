//
// Created by cest on 26/02/21.
//

#ifndef UABC_NODE_H
#define UABC_NODE_H

template<class T>
class Node {
private:
    Node* next;
    T data;
    Node* previous;
public:
    Node(T data, Node* next) {
        this->data = data;
        this->next = next;
        if (this->next != 0) {
            this->next->previous = this;
        }
    }
    T moveToPrevious() {
        T element = this->data;
        Node* previous = this->previous;
        this->next = previous->next;
        this->data = previous->data;
        if (previous->previous != 0) {
            this->previous = previous->previous;
            delete previous;
        }
        return element;
    }
};

#endif //UABC_NODE_H
