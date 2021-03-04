//
// Created by cest on 04/03/21.
//
#include "../Collection.h"
#include "Handler.h"
#include <vector>

#ifndef UABC_LISTHANDLER_H
#define UABC_LISTHANDLER_H

template <class T, class K>
class ListHandler: public Collection<Handler<T, K>*> {
private:
    Handler<T, K>* head = nullptr;
    Handler<T, K>* actual = nullptr;
    void createHead() {
        if (this->isEmpty()) {
            this->head = this->actual;
        }
    }
    void linkActualToNext(Handler<T,K>* element) {
        if (actual != 0) {
            actual->setNext(element);
        }
    }
public:
    ListHandler() {}
    ListHandler(Handler<T,K>* element) {
        this->push(element);
    }

    ListHandler(vector<Handler<T,K>*> handlers) {
        this->push(handlers);
    }

    void push(Handler<T,K>* element) {
        this->linkActualToNext(element);
        this->actual = element;
        this->createHead();
        this->increase();
    }

    void push(vector<Handler<T,K>*> handlers) {
        for(typename vector<Handler<T,K>*>::iterator iter = handlers.begin();  iter != handlers.end(); ++iter )
        {
            this->push(*iter);
        }
    }

    K execute(T request) {
        if (this->isEmpty()) {
            return 0;
        }
        return this->head->handle(request);
    }
};


#endif //UABC_LISTHANDLER_H
