//
// Created by cest on 17/03/21.
//

#include "Hospital.h"

Hospital::Hospital() {
    int size = print<int>("How many rooms do you start hospital?");
    for (int i = 0; i < size; i++) {
        this->rooms.push_back(new Room());
    }
    cout << "\nHis hospital shows next distribution:\n";
    this->showDistribution();
    cout << "Available beds: " << Room::getAvailableBeds() << "\n";
    Console::pauseAndClear();
}

void Hospital::simulate() {
    int day = 1;
    int availableBeds = Room::getAvailableBeds();
    cout << "Day\tIncome\t Outcome\tAvailable\n";
    int patients = this->incomePatients();
    cout << day << "\t  " << patients << "\t    " << "0" << "\t\t    " << availableBeds << "\n";
    this->showDistribution();
    Console::pauseAndClear();
}

int Hospital::incomePatients() {
    int patients = Random::generateNumberBetween(1, 5);
    for (int i = 0; i < patients; i++) {
        for (auto &room : this->rooms) {
            if (room->thereIsAvailableBed()) {
                room->storePatient();
                break;
            }
        }
    }
    return patients;
}

void Hospital::outcomePatients() {
    for (auto &room : this->rooms) {
        room->outcomePatients();
    }
}

void Hospital::showDistribution() {
    for (int i = 0; i < this->getSize(); i++) {
        cout << "Room [" << i + 1 << "] " << this->rooms[i]->toString() << "\n";
    }
}

int Hospital::getSize() {
    return this->rooms.size();
}