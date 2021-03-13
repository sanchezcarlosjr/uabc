//
// Created by cest on 13/03/21.
//

#ifndef UABC_NODE_H
#define UABC_NODE_H
#include <iostream>

template <class T>
class Node {
public:
    T element;
    Node<T>* next = nullptr;
    Node<T>* previous = nullptr;
    Node(T element) {
        this->element = element;
    }
};


#endif //UABC_NODE_H
