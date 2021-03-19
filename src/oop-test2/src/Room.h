//
// Created by cest on 19/03/21.
//

#include <string>
#include <vector>
#include <sstream>
#include "Patient.h"
#include "../Math/Random.h"
using namespace std;
#ifndef UABC_ROOM_H
#define UABC_ROOM_H


class Room {
private:
    vector<Patient*>* beds;
    string getBedsState();
public:
    Room();
    string toString();
};


#endif //UABC_ROOM_H
