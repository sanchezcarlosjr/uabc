//
// Created by cest on 20/02/21.
//

#include "Stack.h"

template<class T>
void Stack<T>::forEach(function<void(T, int)> callback) {
    int index = 0;
    while(!this->isEmpty()) {
        callback(this->pop(), index);
        index++;
    }
}

template <class T>
void Stack<T>::push(T element) {
    this->setNext(new StackNode<T>(element));
    this->increase();
}

template <class T>
T Stack<T>::pop() {
    this->ensureIsEmpty();
    this->decrease();
    return this->replaceRoot(this->root->next);
}

template <class T>
T Stack<T>::peek() {
    if (this->isEmpty()) {
        return '\0';
    }
    return this->root->element;
}