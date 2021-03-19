//
// Created by cest on 19/03/21.
//

#include "Room.h"


string Room::toString() {
    int beds = Random::generateNumberBetween(1,3);
    stringstream message;
    string bedsOrBed = (beds == 1) ? "bed" : "beds";
    message << beds << " " <<bedsOrBed;
    return message.str();
}