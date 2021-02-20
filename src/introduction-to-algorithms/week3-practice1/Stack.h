//
// Created by cest on 20/02/21.
//
#include <iostream>
#include "Node.h"
using namespace std;

#ifndef UABC_STACK_H
#define UABC_STACK_H

template<class T>
class Stack {
private:
    int length = 0;
    Node<T>* top = NULL;
public:
    bool isEmpty();
    void push(T element);
    T peek();
    T pop();
    int size();
    void forEach();
};

#endif //UABC_STACK_H