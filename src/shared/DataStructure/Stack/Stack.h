//
// Created by cest on 20/02/21.
//
#include "../Collection.h"
#include "../../Math/Random.h"
#include "StackNonNullState.h"
#include "StackIterator.h"
#include <string>
#include <vector>
using namespace std;
#ifndef UABC_STACK_H
#define UABC_STACK_H

template<class T>
class Stack : public Collection<T, StackNode<T>> {
    friend class StackIterator<T>;
protected:
    Collection<T, StackNode<T>>* create();

public:
    Stack();

    Stack(string x);

    Stack(initializer_list<int> list);

    void push(T element);


    T peek();

    CollectionState<T, StackNode<T>> *instanceNonNullState();

    T pop();

    Iterator<T> *createIterator();


    static Stack *Factory(int size);
};

#endif //UABC_STACK_H
