//
// Created by cest on 17/03/21.
//

#include "Hospital.h"

Hospital::Hospital() {
    int size = print<int>("How many rooms do you start hospital? ");
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
    int outcomes = 0;
    int availableBeds = 0;
    int patients = 0;
    do {
        cout << "Day\tIncome\t Outcome\tAvailable\n";
        if (day != 1) {
            outcomes = this->outcomePatients();
        }
        patients = this->incomePatients();
        availableBeds = Room::getAvailableBeds();
        cout << day << "\t  " << patients << "\t    " << outcomes << "\t\t    " << availableBeds << "\n";
        this->showDistribution();
        day++;
        Console::pauseAndClear();
    }while(Room::getAvailableBeds() > 0);
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

int Hospital::outcomePatients() {
    int acc = 0;
    for (auto &room : this->rooms) {
        acc += room->outcomePatients();
    }
    return acc;
}

void Hospital::showDistribution() {
    for (int i = 0; i < this->getSize(); i++) {
        cout << "Room [" << i + 1 << "] " << this->rooms[i]->toString() << "\n";
    }
}

int Hospital::getSize() {
    return this->rooms.size();
}