//
// Created by cest on 26/02/21.
//

#include "Queue.h"

void Queue::forEach(function<void(int)> callback) {
    for(int i=0; i<5; i++) {
        callback(i+1);
    }
}