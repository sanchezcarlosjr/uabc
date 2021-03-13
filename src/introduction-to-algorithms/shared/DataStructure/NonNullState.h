//
// Created by cest on 13/03/21.
//

#ifndef UABC_NONNULLSTATE_H
#define UABC_NONNULLSTATE_H

#include "CollectionState.h"
#include "Node.h"

template <class T>
class NonNullState: public CollectionState<T> {
private:
    Node<T>* actual;
public:
    NonNullState(Node<T>* root) {
        this->actual = root;
    }
    void setNext(Collection<T>* collection, Node<T>* node) {
        node->next = this->actual;
        this->actual = node;
        collection->setRoot(node);
    }
};



#endif //UABC_NONNULLSTATE_H
