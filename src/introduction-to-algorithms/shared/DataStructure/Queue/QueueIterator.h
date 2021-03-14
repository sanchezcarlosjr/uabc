//
// Created by cest on 13/03/21.
//

#include "../Iterator.h"

template<class T>
class Queue;

#ifndef UABC_QUEUEITERATOR_H
#define UABC_QUEUEITERATOR_H

template<class T>
class QueueIterator : public Iterator<T> {
private:
    Queue<T> *queue;
    T actual;

public:
    QueueIterator(Queue<T> *queue) {
        this->queue = queue;
    }

    void first() {
    };

    bool isDone() {
        return this->queue->isEmpty();
    };

    T current() {
        return this->actual;
    };

    void next() {
        this->actual = this->queue->dequeue();
    };
};


#endif //UABC_QUEUEITERATOR_H
