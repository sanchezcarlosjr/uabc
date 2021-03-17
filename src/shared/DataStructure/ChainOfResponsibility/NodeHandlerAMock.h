//
// Created by cest on 04/03/21.
//

#include "NodeHandler.h"
#ifndef UABC_A_H
#define UABC_A_H

class NodeHandlerAMock: public NodeHandler<int, int> {
public:
    bool canHandle(int request) override {
        return request > 0;
    }
    int reply(int request) override {
        return 10;
    }
};


#endif //UABC_A_H
