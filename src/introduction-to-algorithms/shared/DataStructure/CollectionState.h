//
// Created by cest on 13/03/21.
//
#include "Node.h"
template <class T>
class Collection;

#ifndef UABC_COLLECTIONSTATE_H
#define UABC_COLLECTIONSTATE_H

template <class T>
class CollectionState {
public:
    virtual void setNext(Collection<T>* collection, Node<T>* node) = 0;
};


#endif //UABC_COLLECTIONSTATE_H
