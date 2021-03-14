//
// Created by cest on 13/03/21.
//
#include "../Iterator.h"
template<class T>
class Stack;

#ifndef UABC_STACKITERATOR_H
#define UABC_STACKITERATOR_H

template<class T>
class StackIterator : public Iterator<T> {
private:
    Stack<T> *stack;

public:
    StackIterator(Stack<T> *stack) {
        this->stack = stack;
    }

    void first() {
    };

    bool isDone() {
        return this->stack->isEmpty();
    };

    T current() {
        return this->stack->peek();
    };

    void next() {
        this->stack->pop();
    };
};


#endif //UABC_STACKITERATOR_H
