//
// Created by cest on 26/02/21.
//
#include <functional>
using namespace std;

#ifndef UABC_QUEUE_H
#define UABC_QUEUE_H

template<class T>
class Queue {
public:
    void forEach(function<void(int index)> callback);
};


#endif //UABC_QUEUE_H
