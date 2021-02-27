//
// Created by cest on 26/02/21.
//
#include "Collection.h"
#include "Node.h"
#include <iostream>
#include <functional>
using namespace std;

#ifndef UABC_QUEUE_H
#define UABC_QUEUE_H

template<class T>
class Queue: public Collection<T> {
private:
    Node<T>* tail = nullptr;
    Node<T>* head = nullptr;
    void createHead();
public:
    void enqueue(T element);
    T dequeue();
    void forEach(function<void(T element, int index)> callback);
};


#endif //UABC_QUEUE_H
