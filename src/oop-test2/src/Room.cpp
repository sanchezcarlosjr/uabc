//
// Created by cest on 19/03/21.
//

#include "Room.h"

int Room::availableBeds = 0;

Room::Room() {
    this->beds = new vector<Patient *>(Random::generateNumberBetween(1, 3));
    Room::availableBeds += this->beds->size();
}

string Room::toString() {
    stringstream message;
    string bedsOrBed = (this->beds->size() == 1) ? "bed" : "beds";
    message << this->beds->size() << " " << bedsOrBed << ":" << this->getBedsState();
    return message.str();
}

string Room::getBedsState() {
    string state = "";
    for (int i = 0; i < this->beds->size(); i++) {
        state += " " + this->isBedAvailable(i);
    }
    return state;
}

string Room::isBedAvailable(int index) {
    if (this->beds->at(index) == nullptr) {
        return "Available";
    }
    return "";
}

int Room::getAvailableBeds() {
    return Room::availableBeds;
}