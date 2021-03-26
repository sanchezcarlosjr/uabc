//
// Created by cest on 26/03/21.
//
#include "Company.h"
#include <string>
using namespace std;
#ifndef UABC_RESTAURANT_H
#define UABC_RESTAURANT_H

class Restaurant: public Company {
private:
    string nameChef = "";
    string address = "";
public:
    Restaurant() {}
    Restaurant(string nameChef, string address, string name): Company(name) {
        this->nameChef = nameChef;
        this->address = address;
    }
    string toString() {
        string str = "";
        return str+"\nMy name is "+this->name+" and you can visit me in "+this->address+". \nOur international chef is "+this->nameChef+".";
    }
};


#endif //UABC_RESTAURANT_H
