//
// Created by cest on 19/03/21.
//

#include "Room.h"

Room::Room() {
    this->beds = Random::generateNumberBetween(1,3);
}

string Room::toString() {
    stringstream message;
    string bedsOrBed = (this->beds == 1) ? "bed" : "beds";
    message << this->beds << " " <<bedsOrBed;
    return message.str();
}