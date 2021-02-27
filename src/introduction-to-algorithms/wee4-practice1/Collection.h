//
// Created by cest on 26/02/21.
//
#include <functional>

using namespace std;
#ifndef UABC_COLLECTION_H
#define UABC_COLLECTION_H

template<class T>
class Collection {
private:
    int length = 0;
protected:
    void increase() {
        this->length++;
    }
    void decrease() {
        this->length--;
    }
public:
    virtual void forEach(function<void(int index)> callback);
    void ensureIsEmpty() {
        if (this->isEmpty()) {
            throw "This structure is empty";
        }
    }
    bool isEmpty() {
        return this->length == 0;
    }
    int size() {
        return this->length;
    }
};


#endif //UABC_COLLECTION_H
