//
// Created by cest on 13/03/21.
//
#include "../Iterator.h"
#include "StackNode.h"
template<class T>
class Stack;

#ifndef UABC_STACKITERATOR_H
#define UABC_STACKITERATOR_H

template<class T>
class StackIterator : public Iterator<T> {
private:
    Stack<T> *stack;
    StackNode<T> *node;

public:
    StackIterator(Stack<T> *stack) {
        this->stack = stack;
    }

    void first() {
        this->node = this->stack->getRoot();
    };

    bool isDone() {
        return this->node == nullptr;
    };

    T current() {
        return this->node->element;
    };

    void next() {
        this->node = this->node->next;
    };
};


#endif //UABC_STACKITERATOR_H
