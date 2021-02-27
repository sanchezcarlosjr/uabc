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
}

template <class T>
T Queue<T>::dequeue() {
    this->decrease();
    return 1;
}