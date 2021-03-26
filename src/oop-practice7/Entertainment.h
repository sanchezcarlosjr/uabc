//
// Created by cest on 26/03/21.
//
#include "Company.h"
#include <string>
#include <vector>
using namespace std;
#ifndef UABC_ENTERTAINMENT_H
#define UABC_ENTERTAINMENT_H

class Entertainment: public Company {
protected:
    string medium;
private:
    vector<string> categories;
public:
    Entertainment() {
    }
    Entertainment(string name): Company(name) {
    }
};


#endif //UABC_ENTERTAINMENT_H
