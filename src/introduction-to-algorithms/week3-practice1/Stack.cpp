//
// Created by cest on 20/02/21.
//

#include "Stack.h"

template <class T>
bool Stack<T>::isEmpty() {
    return this->length == 0;
}

template <class T>
void Stack<T>::push(T element) {
    Node* node = new Node();
    node->element = element;
    node->node = this->head;
    this->head = node;
    this->length++;
}

template <class T>
int Stack<T>::size() {
    return this->length;
}

template <class T>
T Stack<T>::pop() {
    return 1;
}