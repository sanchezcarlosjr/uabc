//
// Created by cest on 19/03/21.
//

#include "Room.h"

int Room::TotalAvailableBeds = 0;

Room::Room() {
    this->beds = new vector<Patient *>(Random::generateNumberBetween(1, 3));
    this->availableBeds = this->beds->size();
    Room::TotalAvailableBeds += this->availableBeds;
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
        state += " " + this->isAvailableBed(i);
    }
    return state;
}

string Room::isAvailableBed(int index) {
    if (this->beds->at(index) == nullptr) {
        return "Available";
    }
    return this->beds->at(index)->toString();
}

bool Room::thereIsAvailableBed() {
    return this->availableBeds != 0;
}

void Room::storePatient() {
    int wherePatientWillStore = this->beds->size() - this->availableBeds;
    this->beds->at(wherePatientWillStore) = new Patient();
    this->availableBeds--;
    Room::TotalAvailableBeds--;
}

int Room::outcomePatients() {
    int acc = 0;
    for (int index = 0; index < this->beds->size(); index++) {
        if (this->beds->at(index) != nullptr && this->beds->at(index)->canExit()) {
            this->beds->at(index) = nullptr;
            acc++;
            this->availableBeds++;
            Room::TotalAvailableBeds++;
        }
    }
    return acc;
}


int Room::getAvailableBeds() {
    return Room::TotalAvailableBeds;
}