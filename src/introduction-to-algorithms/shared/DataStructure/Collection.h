//
// Created by cest on 26/02/21.
//
#include <functional>
#include "CollectionState.h"
#include "NullState.h"
using namespace std;

#ifndef UABC_COLLECTION_H
#define UABC_COLLECTION_H

template<class T>
class Collection {
protected:
    Node<T>* root = nullptr;
    void setNext(Node<T>* node) {
        this->collectionState->setNext(this, node);
    }
private:
    int length = 0;
    CollectionState<T>* collectionState;
protected:
    Collection() {
        this->collectionState = new NullState<T>();
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
public:
    void forEach(function<void(T element, int index)> callback);
    bool isEmpty() {
        return this->length == 0;
    }
    int size() {
        return this->length;
    }
    void setRoot(Node<T>* root) {
        this->root = root;
    }
    T replaceRoot(Node<T>* newRoot) {
        T element = this->root->element;
        Node<T>* formerRoot = this->root;
        this->setRoot(newRoot);
        delete formerRoot;
        return element;
    }
    void setCollectionState(CollectionState<T>* collectionState) {
        this->collectionState = collectionState;
    }
    void toNonNullState() {
        this->setCollectionState(this->instanceNonNullState());
    }
    virtual CollectionState<T>* instanceNonNullState() = 0;
};

#endif //UABC_COLLECTION_H
