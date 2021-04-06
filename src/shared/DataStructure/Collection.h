//
// Created by cest on 26/02/21.
//
#include <functional>
#include "CollectionState.h"
#include "NullState.h"
#include "Iterator.h"
#include "../Math/Random.h"
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
    virtual Collection<T,K>* create() = 0;
    virtual void push(T node) = 0;
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
    Collection<T,K>* factory(int size) {
        for (int i = 0; i < size; i++) {
            this->push(Random::Number());
        }
        return this;
    }

    Collection<T,K>* factory(function<bool(T value)> isTrue, function<T()> creator) {
        T value;
        do {
            value = creator();
            if (!isTrue(value)) {
                return this;
            }
            this->push(value);
        } while (isTrue(value));
        return this;
    }

    Collection<T,K>* forEach(function<void(T element, int index)> callback) {
        Iterator<T> *it = this->createIterator();
        int i = 0;
        for (it->first(); !it->isDone(); it->next()) {
            callback(it->current(), i);
            i++;
        }
        return this;
    }

    Collection<T,K>* forEach(function<void(T element)> callback) {
        Iterator<T> *it = this->createIterator();
        for (it->first(); !it->isDone(); it->next()) {
            callback(it->current());
        }
        return this;
    }

    Collection<T,K>* map(function<T(T element, int index)> callback) {
        Collection<T,K>*  collection = this->factory();
        this->forEach([collection, callback](T element, int index) {
            collection->push(callback(element, index));
        });
        return collection;
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

    T replaceRoot(K *newRoot) {
        T element = this->root->element;
        K *formerRoot = this->root;
        this->setRoot(newRoot);
        delete formerRoot;
        return element;
    }

    K *getRoot() {
        return this->root;
    }

    void setCollectionState(CollectionState<T, K> *collectionState) {
        this->collectionState = collectionState;
    }

    void toNonNullState() {
        this->setCollectionState(this->instanceNonNullState());
    }

    virtual Iterator<T> *createIterator() = 0;
};

#endif //UABC_COLLECTION_H
