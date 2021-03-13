//
// Created by cest on 08/03/21.
//

#include "../Collection.h"
#ifndef UABC_LIST_H
#define UABC_LIST_H

template <class T>
class List: public Collection<T> {
public:
    void push(T);
};

#endif //UABC_LIST_H
