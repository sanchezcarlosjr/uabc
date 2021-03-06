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
Collection<T, ListNode<T>> *List<T>::create() {
	return new List<T>();
}
