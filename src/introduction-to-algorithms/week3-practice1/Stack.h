//
// Created by cest on 20/02/21.
//
#include <iostream>
using namespace std;

#ifndef UABC_STACK_H
#define UABC_STACK_H

template<class T>
class Stack {
private:
    int length = 0;
    struct Node {
        T element;
        Node* node;
    };
    Node* head = NULL;
public:
    bool isEmpty();
    void push(T element);
    int size();
};

#endif //UABC_STACK_H