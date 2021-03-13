//
// Created by cest on 13/03/21.
//

#ifndef UABC_NULLSTATE_H
#define UABC_NULLSTATE_H

#include "CollectionState.h"
#include "Node.h"

template <class T>
class NullState: public CollectionState<T> {
public:
    void setNext(Collection<T>* collection, Node<T>* root) {
        collection->setRoot(root);
        collection->toNonNullState();
    }
};


#endif //UABC_NULLSTATE_H
