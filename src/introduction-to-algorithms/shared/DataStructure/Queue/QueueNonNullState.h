//
// Created by cest on 13/03/21.
//
#include "../Stack/StackNode.h"
#include "../CollectionState.h"
#include <iostream>
using namespace std;
#ifndef UABC_QUEUENONNULLSTATE_H
#define UABC_QUEUENONNULLSTATE_H

template <class T>
class QueueNonNullState: public CollectionState<T, QueueNonNullState<T>> {
private:
    QueueNonNullState<T>* actual;
public:
    QueueNonNullState(QueueNonNullState<T>* root) {
        this->actual = root;
    }
    void setNext(Collection<T, QueueNonNullState<T>>* collection, QueueNonNullState<T>* next) {
        this->actual = next;
    }
};


#endif //UABC_QUEUENONNULLSTATE_H
