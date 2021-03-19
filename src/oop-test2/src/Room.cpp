//
// Created by cest on 19/03/21.
//

#include "Room.h"

Room::Room() {
    this->beds = new vector<Patient*>(Random::generateNumberBetween(1, 3));
}

string Room::toString() {
    stringstream message;
    string bedsOrBed = (this->beds->size() == 1) ? "bed" : "beds";
    message << this->beds->size() << " " << bedsOrBed << ":" << this->getBedsState();
    return message.str();
}

string Room::getBedsState() {
    string state = "";
    for (int i = 0; i< this->beds->size(); i++) {
        state += " Available";
    }
    return state;
}