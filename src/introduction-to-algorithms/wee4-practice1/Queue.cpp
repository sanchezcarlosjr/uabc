//
// Created by cest on 26/02/21.
//

#include "Queue.h"

template<class T>
void Queue<T>::forEach(function<void(int)> callback) {
    for(int i=0; i<5; i++) {
        callback(i+1);
    }
}

template <class T>
void Queue<T>::enqueue(T element) {
    this->increase();
    this->tail = new Node<T>(element, this->tail);
    this->createHead();
}

template <class T>
void Queue<T>::createHead() {
    bool isANewHead = this->size()-1 == 0;
    if (isANewHead) {
        this->head = this->tail;
    }
}

template <class T>
T Queue<T>::dequeue() {
    this->ensureIsEmpty();
    this->decrease();
    return this->head->moveToPrevious();
}