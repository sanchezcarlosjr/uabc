//
// Created by cest on 26/03/21.
//
#include "Entertainment.h"
#ifndef UABC_STREAMING_H
#define UABC_STREAMING_H

class Streaming: public Entertainment {
public:
    Streaming(string name): Entertainment(name) {
        this->medium = "Internet";
    }
    string toString() {
        string str = "";
        return str+"I am "+this->name+" and I'm better than Cinema because my medium is "+this->medium+".";
    }
};


#endif //UABC_STREAMING_H
