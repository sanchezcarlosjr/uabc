//
// Created by cest on 13/03/21.
//
#include "StackNode.h"
#include "../CollectionState.h"
#ifndef UABC_STACKNONNULLSTATE_H
#define UABC_STACKNONNULLSTATE_H

template <class T>
class StackNonNullState: public CollectionState<T, StackNode<T>> {
private:
    StackNode<T>* actual;
public:
    StackNonNullState(StackNode<T>* root) {
        this->actual = root;
    }
    void setNext(Collection<T,StackNode<T>>* collection, StackNode<T>* node) {
        node->next = this->actual;
        this->actual = node;
        collection->setRoot(node);
    }
};


#endif //UABC_STACKNONNULLSTATE_H
