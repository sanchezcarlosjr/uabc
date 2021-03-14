//
// Created by cest on 13/03/21.
//

#ifndef UABC_NODE_H
#define UABC_NODE_H
#include <iostream>

template <class T>
class StackNode {
public:
    T element;
    StackNode<T>* next = nullptr;
    StackNode(T element) {
        this->element = element;
    }
};


#endif //UABC_NODE_H
