//
// Created by cest on 13/03/21.
//

#include "../Iterator.h"
#include "QueueNode.h"
template<class T>
class Queue;

#ifndef UABC_QUEUEITERATOR_H
#define UABC_QUEUEITERATOR_H

template<class T>
class QueueIterator : public Iterator<T> {
private:
    Queue<T> *queue;
    QueueNode<T> *node;

public:
    QueueIterator(Queue<T> *queue) {
        this->queue = queue;
    }

    void first() {
        this->node = this->queue->getRoot();
    };

    bool isDone() {
        return this->node == nullptr;
    };

    T current() {
        return this->node->element;
    };

    void next() {
        this->node = this->node->previous;
    };
};


#endif //UABC_QUEUEITERATOR_H
