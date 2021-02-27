//
// Created by cest on 26/02/21.
//
#include "Collection.h"
#include <functional>
using namespace std;

#ifndef UABC_QUEUE_H
#define UABC_QUEUE_H

template<class T>
class Queue: public Collection<T> {
public:
    void enqueue(T element);
    T dequeue();
    void forEach(function<void(int index)> callback);
};


#endif //UABC_QUEUE_H
