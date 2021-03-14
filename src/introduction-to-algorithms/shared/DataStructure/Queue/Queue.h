//
// Created by cest on 26/02/21.
//
#include "../Collection.h"
#include "QueueNode.h"
#include "QueueNonNullState.h"
#include <functional>
#include <iostream>
using namespace std;

#ifndef UABC_QUEUE_H
#define UABC_QUEUE_H

template<class T>
class Queue : public Collection<T, QueueNode<T>> {
private:
    QueueNode<T> *tail = nullptr;
public:
    void enqueue(T element);

    T dequeue();

    void forEach(function<void(T element, int index)> callback);

    CollectionState<T, QueueNode<T>> *instanceNonNullState();
};


#endif //UABC_QUEUE_H
