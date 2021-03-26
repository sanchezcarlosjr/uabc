//
// Created by cest on 26/03/21.
//
#include "Entertainment.h"
#ifndef UABC_CINEMA_H
#define UABC_CINEMA_H

class Cinema: public Entertainment {
public:
    Cinema(string name): Entertainment(name) {
        this->medium = "Physical";
    }
    string toString() {
        string str = "";
        return str+"Good by Walt Disney and his "+this->name+"!";
    }
};


#endif //UABC_CINEMA_H
