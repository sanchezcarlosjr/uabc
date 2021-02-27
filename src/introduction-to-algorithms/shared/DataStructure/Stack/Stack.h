//
// Created by cest on 20/02/21.
//
#include "Node.h"
#include <string>
using namespace std;
#ifndef UABC_STACK_H
#define UABC_STACK_H

template<class T>
class Stack {
private:
    int length = 0;
    Node<T>* top = nullptr;
    void ensureIsNotEmpty();
public:
    Stack() {}
    Stack(string x) {
        int middle = x.length()/2;
        for (int i=middle; i<x.length(); i++) {
            this->push(x[i]);
        }
    }
    bool isEmpty();
    void push(T element);
    T peek();
    T pop();
    int size();
};

#endif //UABC_STACK_H