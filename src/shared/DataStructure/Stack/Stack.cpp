//
// Created by cest on 20/02/21.
//

#include "Stack.h"

template<class T>
Stack<T>::Stack() {
}

template<class T>
Stack<T>::Stack(string x) {
    int middle = x.length() / 2;
    for (int i = middle; i < x.length(); i++) {
        this->push(x[i]);
    }
}

template<class T>
Stack<T>::Stack(initializer_list<int> list) {
    for (auto i = list.begin(); i != list.end(); i++) {
        this->push(*i);
    }
}


template<class T>
void Stack<T>::push(T element) {
    this->setNext(new StackNode<T>(element));
    this->increase();
}

template<class T>
T Stack<T>::pop() {
    this->ensureIsEmpty();
    this->decrease();
    return this->replaceRoot(this->root->next);
}

template<class T>
T Stack<T>::peek() {
    if (this->isEmpty()) {
        return '\0';
    }
    return this->root->element;
}

template<class T>
CollectionState<T, StackNode<T>> *Stack<T>::instanceNonNullState() {
    return new StackNonNullState<T>(this->root);
}

template<class T>
Iterator<T> *Stack<T>::createIterator() {
    return new StackIterator<T>(this);
}

template<class T>
Stack<T> *Stack<T>::Factory(int size) {
    Stack<T> *stack = new Stack<T>();
    for (int i = 0; i < size; i++) {
        stack->push(Random::Number());
    }
    return stack;
}