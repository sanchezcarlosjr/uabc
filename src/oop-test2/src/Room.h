//
// Created by cest on 19/03/21.
//

#include <string>
#include <sstream>
#include "Math/Random.h"
using namespace std;
#ifndef UABC_ROOM_H
#define UABC_ROOM_H


class Room {
private:
    int beds = 0;
public:
    Room();
    string toString();
};


#endif //UABC_ROOM_H
