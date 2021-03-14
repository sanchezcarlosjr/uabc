//
// Created by cest on 26/02/21.
//
#include <functional>
#include "CollectionState.h"
#include "NullState.h"
#include "Iterator.h"
#include <iostream>
using namespace std;

#ifndef UABC_COLLECTION_H
#define UABC_COLLECTION_H

template<class T, class K>
class Collection {
protected:
    K* root = nullptr;
    void setNext(K* node) {
        this->collectionState->setNext(this, node);
    }
private:
    int length = 0;
    CollectionState<T,K>* collectionState;
protected:
    Collection() {
        this->collectionState = new NullState<T,K>();
    }
    void increase() {
        this->length++;
    }

    void decrease() {
        this->length--;
    }

    void ensureIsEmpty() {
        if (this->isEmpty()) {
            throw "This structure is empty";
        }
    }

    virtual CollectionState<T, K> *instanceNonNullState() = 0;

public:
    void forEach(function<void(T element, int index)> callback) {
        Iterator<T> *it = this->createIterator();
        int i = 1;
        for (it->first(); !it->isDone(); it->next()) {
            callback(it->current(), i);
            i++;
        }
    }

    bool isEmpty() {
        return this->length == 0;
    }

    int size() {
        return this->length;
    }

    void setRoot(K *root) {
        if (root != nullptr) {
            this->root = root;
        }
    }
    T replaceRoot(K* newRoot) {
        T element = this->root->element;
        K* formerRoot = this->root;
        this->setRoot(newRoot);
        delete formerRoot;
        return element;
    }
    void setCollectionState(CollectionState<T, K>* collectionState) {
        this->collectionState = collectionState;
    }
    void toNonNullState() {
        this->setCollectionState(this->instanceNonNullState());
    }

    virtual Iterator<T> *createIterator() = 0;
};

#endif //UABC_COLLECTION_H
