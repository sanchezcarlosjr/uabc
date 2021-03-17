//
// Created by cest on 13/03/21.
//
#include "../CollectionState.h"
#include "QueueNode.h"
#ifndef UABC_QUEUENONNULLSTATE_H
#define UABC_QUEUENONNULLSTATE_H

template <class T>
class QueueNonNullState : public CollectionState<T, QueueNode<T>> {
private:
    QueueNode<T> *actual;
public:
    QueueNonNullState(QueueNode<T> *root) {
        this->actual = root;
    }

    void setNext(Collection<T, QueueNode<T>> *collection, QueueNode<T> *newNode) {
        newNode->setNext(this->actual);
        this->actual = newNode;
    }
};


#endif //UABC_QUEUENONNULLSTATE_H
