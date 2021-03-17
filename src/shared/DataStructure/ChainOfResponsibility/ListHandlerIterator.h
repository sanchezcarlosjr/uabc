//
// Created by cest on 15/03/21.
//
#include "../Iterator.h"
#include "Handler.h"

#ifndef UABC_LISTHANDLERITERATOR_H
#define UABC_LISTHANDLERITERATOR_H

template<class T, class K>
class ListHandler;

template<class T, class K>
class ListHandlerIterator : public Iterator<T> {
private:
    ListHandler<T,K>* list;
public:
    void first() {}
    bool isDone() {
        return true;
    }
    T current() {
        return nullptr;
    }
    void next() {

    }
};


#endif //UABC_LISTHANDLERITERATOR_H
