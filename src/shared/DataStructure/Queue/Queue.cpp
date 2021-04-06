//
// Created by cest on 26/02/21.
//

#include "Queue.h"

template <class T>
void Queue<T>::enqueue(T element) {
    this->setNext(new QueueNode<T>(element));
    this->increase();
}

template <class T>
T Queue<T>::dequeue() {
    this->ensureIsEmpty();
    this->decrease();
    return this->replaceRoot(this->root->previous);
}

template<class T>
CollectionState<T, QueueNode<T>> *Queue<T>::instanceNonNullState() {
    return new QueueNonNullState<T>(this->root);
}

template<class T>
Iterator<T> *Queue<T>::createIterator() {
    return new QueueIterator<T>(this);
}

template<class T>
Collection<T, QueueNode<T>> *Queue<T>::factory() {
	return new Queue<T>();
}
