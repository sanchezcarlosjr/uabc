//
// Created by cest on 08/03/21.
//

#include <functional>
#include "../Collection.h"
#include "ListNode.h"
#include "../../Math/Random.h"
#include "ListNonNullState.h"
#include "ListIterator.h"

using namespace std;

#ifndef UABC_LIST_H
#define UABC_LIST_H

template<class T>
class List : public Collection<T, ListNode<T>> {
public:
    List() {}

    List(initializer_list <T> list);


    void push(T);

    CollectionState<T, ListNode<T>> *instanceNonNullState();

    Iterator<T> *createIterator();

    List<T> *map(function<T(T element, int index)> callback);

    static List<T> *Factory(int size);

    static List<T> *Factory(function<bool(T value)>, function<T()>);
};

#endif //UABC_LIST_H
