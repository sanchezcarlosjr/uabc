//
// Created by cest on 19/03/21.
//

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "Patient.h"
#include "../Math/Random.h"
using namespace std;
#ifndef UABC_ROOM_H
#define UABC_ROOM_H


class Room {
private:
    vector<Patient*>* beds;
    static int TotalAvailableBeds;
    int availableBeds;
    string getBedsState();
public:
    Room();
    string toString();
    string isAvailableBed(int index);
    bool thereIsAvailableBed();
    void storePatient();
    static int getAvailableBeds();
};


#endif //UABC_ROOM_H
