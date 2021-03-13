//
// Created by cest on 13/03/21.
//
#include "../Node.h"
#include "../CollectionState.h"
#ifndef UABC_STACKNONNULLSTATE_H
#define UABC_STACKNONNULLSTATE_H

template <class T>
class StackNonNullState: public CollectionState<T> {
private:
    Node<T>* actual;
public:
    StackNonNullState(Node<T>* root) {
        this->actual = root;
    }
    void setNext(Collection<T>* collection, Node<T>* node) {
        node->next = this->actual;
        this->actual = node;
        collection->setRoot(node);
    }
};


#endif //UABC_STACKNONNULLSTATE_H
