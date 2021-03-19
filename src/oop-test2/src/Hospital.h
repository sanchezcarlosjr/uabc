//
// Created by cest on 17/03/21.
//

#include "../System/system.h"
#include "Room.h"
#include "../Math/Random.h"
#include <vector>
using namespace std;

#ifndef UABC_HOSPITAL_H
#define UABC_HOSPITAL_H

class Hospital {
private:
    vector <Room*> rooms;
public:
    Hospital();
    void simulate();
    void showDistribution();
    int incomePatients();
    int outcomePatients();
    int getSize();
};


#endif //UABC_HOSPITAL_H
