//
// Created by cest on 20/02/21.
//
#include "Node.h"
#ifndef UABC_STACK_H
#define UABC_STACK_H

template<class T>
class Stack {
private:
    int length = 0;
    Node<T>* top = nullptr;
public:
    bool isEmpty();
    void push(T element);
    T peek();
    T pop();
    int size();
};

#endif //UABC_STACK_H