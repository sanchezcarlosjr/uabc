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
    this->length++;
    Node* node = new Node();
    node->element = element;
    node->next = this->top;
    this->top = node;
}

template <class T>
int Stack<T>::size() {
    return this->length;
}

template <class T>
T Stack<T>::pop() {
    if (this->isEmpty()) {
        return 0;
    }
    this->length--;
    T element = this->top->element;
    Node* formerTop = this->top;
    this->top = this->top->next;
    delete formerTop;
    return element;
}