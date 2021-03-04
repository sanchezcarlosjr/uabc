//
// Created by cest on 04/03/21.
//

#include "NodeHandler.h"
#ifndef UABC_NODEHANDLERBMOCK_H
#define UABC_NODEHANDLERBMOCK_H

class NodeHandlerBMock: public NodeHandler<int, int> {
public:
    bool canHandle(int request) override {
        return request < 0;
    }
    int reply(int request) override {
        return -10;
    }
};


#endif //UABC_NODEHANDLERBMOCK_H
