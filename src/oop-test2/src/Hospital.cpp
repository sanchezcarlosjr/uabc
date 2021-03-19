//
// Created by cest on 17/03/21.
//

#include "Hospital.h"

Hospital::Hospital() {
    int size = print<int>("How many rooms do you start hospital?");
    for(int i=0; i<size; i++) {
        this->rooms.push_back(new Room());
    }
    cout << "\nHis hospital shows next distribution:\n";
    this->showDistribution();
    cout << "Available beds: "<< Room::getAvailableBeds() <<"\n";
    Console::pause();
}

void Hospital::simulate() {

}

void Hospital::showDistribution() {
    for (int i = 0; i < this->getSize(); i++) {
        cout << "Room ["<< i+1 <<"] "<< this->rooms[i]->toString() <<"\n";
    }
}

int Hospital::getSize() {
    return this->rooms.size();
}