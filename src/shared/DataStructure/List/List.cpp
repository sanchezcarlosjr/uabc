//
// Created by cest on 08/03/21.
//

#include "List.h"

template<class T>
List<T>::List(initializer_list <T> list) {
    for (T element : list) {
        this->push(element);
    }
}

template<class T>
void List<T>::push(T element) {
    this->setNext(new ListNode<T>(element));
    this->increase();
}

template<class T>
CollectionState<T, ListNode<T>> *List<T>::instanceNonNullState() {
    return new ListNonNullState<T>(this->root);
}

template<class T>
Iterator<T> *List<T>::createIterator() {
    return new ListIterator<T>(this);
}

template<class T>
List<T> *List<T>::Factory(int size) {
    List<T> *list = new List<T>();
    for (int i = 0; i < size; i++) {
        list->push(Random::Number());
    }
    return list;
}

template<class T>
List<T> *List<T>::Factory(function<bool(T value)> isTrue, function<T()> creator) {
    List<T> *list = new List<T>();
    T value;
    do {
        value = creator();
        if (!isTrue(value)) {
            return list;
        }
        list->push(value);
    } while (isTrue(value));
    return list;
}

template<class T>
Collection<T, ListNode<T>> *List<T>::factory() {
	return new List<T>();
}
