//
// Created by cest on 13/03/21.
//

#ifndef UABC_NULLSTATE_H
#define UABC_NULLSTATE_H

#include "CollectionState.h"

template <class T, class K>
class NullState: public CollectionState<T, K> {
public:
    void setNext(Collection<T,K>* collection, K* root) {
        collection->setRoot(root);
        collection->toNonNullState();
    }
};


#endif //UABC_NULLSTATE_H
