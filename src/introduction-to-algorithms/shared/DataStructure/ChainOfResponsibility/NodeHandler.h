//
// Created by cest on 04/03/21.
//

#include "Handler.h"
#ifndef UABC_NODEHANDLER_H
#define UABC_NODEHANDLER_H

template <class T, class K>
class NodeHandler: public Handler<T, K> {
private:
    Handler<T, K>* next = nullptr;
    void moveToNext(T request) {
        if (this->next != nullptr) {
            this->next->handle(request);
        }
    }
public:
    void setNext(Handler<T, K>* next) {
        this->next = next;
    }
    K handle(T request) {
       if (this->canHandle(request)) {
           return this->reply(request);
       }
       this->moveToNext(request);
    }
    virtual bool canHandle(T request) = 0;
    virtual K reply(T request) = 0;
};


#endif //UABC_NODEHANDLER_H
