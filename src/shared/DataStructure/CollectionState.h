//
// Created by cest on 13/03/21.
//

template <class T, class K>
class Collection;

#ifndef UABC_COLLECTIONSTATE_H
#define UABC_COLLECTIONSTATE_H

template <class T, class K>
class CollectionState {
public:
    virtual void setNext(Collection<T,K>* collection, K* node) = 0;
};


#endif //UABC_COLLECTIONSTATE_H
