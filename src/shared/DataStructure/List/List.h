//
// Created by cest on 08/03/21.
//

#include <functional>
#include "../Collection.h"
#include "ListNode.h"
#include "ListNonNullState.h"
#include "ListIterator.h"

using namespace std;

#ifndef UABC_LIST_H
#define UABC_LIST_H

template<class T>
class List : public Collection<T, ListNode<T>> {
protected:
    Collection<T, ListNode<T>> *create();
public:
    List() {}

    List(initializer_list <T> list);

    void push(T);

    CollectionState<T, ListNode<T>> *instanceNonNullState();

    Iterator<T> *createIterator();

};

#endif //UABC_LIST_H
