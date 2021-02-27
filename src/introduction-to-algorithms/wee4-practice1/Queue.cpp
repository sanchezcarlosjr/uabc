//
// Created by cest on 26/02/21.
//

#include "Queue.h"

template<class T>
void Queue<T>::forEach(function<void(T, int)> callback) {
    int index = 0;
    while(!this->isEmpty()) {
        callback(this->dequeue(), index);
        index++;
    }
}

template <class T>
void Queue<T>::enqueue(T element) {
    this->tail = new Node<T>(element, this->tail);
    this->createHead();
    this->increase();
}

template <class T>
void Queue<T>::createHead() {
    if (this->isEmpty()) {
        this->head = this->tail;
    }
}

template <class T>
T Queue<T>::dequeue() {
    this->ensureIsEmpty();
    this->decrease();
    return this->head->moveToPrevious();
}