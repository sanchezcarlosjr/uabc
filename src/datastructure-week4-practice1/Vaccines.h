//
// Created by cest on 27/02/21.
//
#include <iostream>

using namespace std;
#ifndef UABC_VACCINES_H
#define UABC_VACCINES_H

class Vaccines {
private:
    static Vaccines* singleton;
    int availableVaccines = 500;
    int usedVaccines = 0;
public:
    static Vaccines *GetInstance();
    void increase();
};


#endif //UABC_VACCINES_H
