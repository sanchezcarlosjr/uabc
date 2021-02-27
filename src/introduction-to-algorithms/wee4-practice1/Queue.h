//
// Created by cest on 26/02/21.
//
#include <functional>
using namespace std;

#ifndef UABC_QUEUE_H
#define UABC_QUEUE_H

class Queue {
public:
    void forEach(function<void(int value)> callback);
};


#endif //UABC_QUEUE_H
