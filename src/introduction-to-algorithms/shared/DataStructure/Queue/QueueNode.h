//
// Created by cest on 26/02/21.
//
#ifndef UABC_QUEUE_NODE_H
#define UABC_QUEUE_NODE_H

template<class T>
class QueueNode {
public:
    T element;
    QueueNode<T> *next = nullptr;

    QueueNode(T element) {
        this->element = element;
    }
};

#endif //UABC_QUEUE_NODE_H
