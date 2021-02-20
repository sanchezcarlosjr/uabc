//
// Created by cest on 20/02/21.
//
#include <iostream>
using namespace std;
#include <typeinfo>

#ifndef UABC_STACK_H
#define UABC_STACK_H

template<class T>
class Stack {
private:
    int length = 0;
    struct Node {
        T element;
        Node* next;
    };
    Node* top = NULL;
public:
    bool isEmpty();
    void push(T element);
    T peek();
    T pop();
    int size();
};

#endif //UABC_STACK_H