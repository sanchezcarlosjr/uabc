//
// Created by cest on 13/03/21.
//
#include "../Iterator.h"

#ifndef UABC_STACKITERATOR_H
#define UABC_STACKITERATOR_H

template<class T>
class StackIterator : public Iterator<T> {
    void first() {};

    bool isDone() {
        return false;
    };

    T current() {
        return 0;
    };

    void next() {
    };
};


#endif //UABC_STACKITERATOR_H
