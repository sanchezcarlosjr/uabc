//
// Created by cest on 20/02/21.
//
#include "../Collection.h"
#include "../../Math/Random.h"
#include <string>
#include <vector>
using namespace std;
#ifndef UABC_STACK_H
#define UABC_STACK_H

template<class T>
class Stack: public Collection<T> {
public:
    Stack() {}
    Stack(string x) {
        int middle = x.length()/2;
        for (int i=middle; i<x.length(); i++) {
            this->push(x[i]);
        }
    }
    Stack(initializer_list<int> list) {
        for (auto i = list.begin(); i != list.end(); i++) {
            this->push(*i);
        }
    }
    void push(T element);
    void forEach(function<void(T element, int index)> callback);
    T peek();
    T pop();
    static Stack* Factory(int size) {
        Stack<T>* stack = new Stack<T>();
        for (int i = 0; i < size; i++) {
            stack->push(Random::generateNumberBetween(10,100));
        }
        return stack;
    }
};

#endif //UABC_STACK_H