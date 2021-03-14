//
// Created by cest on 13/03/21.
//
#include "../CollectionState.h"
#include "ListNode.h"

#ifndef UABC_LISTNONNULLSTATE_H
#define UABC_LISTNONNULLSTATE_H

template<class T>
class ListNonNullState : public CollectionState<T, ListNode<T>> {
private:
    ListNode<T> *actual;
public:
    ListNonNullState(ListNode<T> *root) {
        this->actual = root;
    }

    void setNext(Collection<T, ListNode<T>> *collection, ListNode<T> *newNode) {
        newNode->setNext(this->actual);
        this->actual = newNode;
    }
};


#endif //UABC_LISTNONNULLSTATE_H
