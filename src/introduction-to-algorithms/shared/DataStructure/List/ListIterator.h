//
// Created by cest on 13/03/21.
//

#ifndef UABC_LISTITERATOR_H
#define UABC_LISTITERATOR_H

#include "../Iterator.h"
#include "ListNode.h"

template<class T>
class List;

template<class T>
class ListIterator : public Iterator<T> {
private:
    List<T> *list;
    ListNode<T> *node;

public:
    ListIterator(List<T> *list) {
        this->list = list;
    }

    void first() {
        this->node = this->list->getRoot();
    };

    bool isDone() {
        return this->node == nullptr;
    };

    T current() {
        return this->node->element;
    };

    void next() {
        this->node = this->node->previous;
    };
};


#endif //UABC_LISTITERATOR_H
