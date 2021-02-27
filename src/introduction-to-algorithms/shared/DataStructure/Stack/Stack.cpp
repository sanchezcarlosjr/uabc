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
    this->top = new Node<T>(element, this->top);
    this->length++;
}

template <class T>
int Stack<T>::size() {
    return this->length;
}

template <class T>
T Stack<T>::pop() {
    this->ensureIsNotEmpty();
    this->length--;
    return Node<T>::moveToNext(this->top);
}

template <class T>
void Stack<T>::ensureIsNotEmpty() {
    if (this->isEmpty()) {
        throw "Stack cannot pop.";
    }
}


template <class T>
T Stack<T>::peek() {
    return this->top->element;
}