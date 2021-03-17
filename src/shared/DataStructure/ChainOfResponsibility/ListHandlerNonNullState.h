//
// Created by cest on 15/03/21.
//
#include "../CollectionState.h"
#include "Handler.h"

#ifndef UABC_LISTHANDLERNONNULLSTATE_H
#define UABC_LISTHANDLERNONNULLSTATE_H

template<class T, class K>
class ListHandlerNonNullState {
private:
    Handler<T,K> *actual;
public:
    ListHandlerNonNullState(Handler<T,K> *root) {
        this->actual = root;
    }

    void setNext(Collection<T, Handler<T,K>> *collection, Handler<T, K> *newNode) {
    }
};


#endif //UABC_LISTHANDLERNONNULLSTATE_H
