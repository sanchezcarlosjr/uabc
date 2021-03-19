//
// Created by cest on 17/03/21.
//

#include "../System/system.h"
#include "Room.h"
#include <vector>
using namespace std;

#ifndef UABC_HOSPITAL_H
#define UABC_HOSPITAL_H

class Hospital {
private:
    vector <Room*> database;
public:
    Hospital();
    void simulate();
    int getSize();
};


#endif //UABC_HOSPITAL_H
