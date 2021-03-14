//
// Created by cest on 26/02/21.
//
#ifndef UABC_QUEUE_NODE_H
#define UABC_QUEUE_NODE_H

template<class T>
class QueueNode {
public:
    T element;
    QueueNode *next;
    QueueNode *previous;

    QueueNode(T data) {
        this->element = data;
    }

    void setNext(QueueNode<T> *next) {
        this->next = next;
        this->next->previous = this;
    }
};

#endif //UABC_QUEUE_NODE_H
