//
// Created by cest on 04/03/21.
//

#ifndef UABC_HANDLER_H
#define UABC_HANDLER_H

template<class T, class K>
class Handler {
public:
    virtual void setNext(Handler<T,K>* handle) = 0;
    virtual K handle(T request) = 0;
};


#endif //UABC_HANDLER_H
