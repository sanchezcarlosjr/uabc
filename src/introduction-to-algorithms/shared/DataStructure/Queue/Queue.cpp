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
    this->setNext(new QueueNode<T>(element));
    this->increase();
}

template <class T>
T Queue<T>::dequeue() {
    this->ensureIsEmpty();
    this->decrease();
    return this->replaceRoot(nullptr);
}

template <class T>
CollectionState<T, QueueNonNullState<T>>* Queue<T>::instanceNonNullState()  {
    return new QueueNonNullState<T>(this->root);
}