//
// Created by cest on 17/03/21.
//

#include "Hospital.h"

Hospital::Hospital() {
    int size = print<int>("How many rooms do you start hospital?");
    for(int i=0; i<size; i++) {
        this->database.push_back(new Room());
    }
    cout << "\nHis hospital shows next distribution:\n";
    this->showDistribution();
    cout << "Available beds: 1";
}

void Hospital::simulate() {

}

void Hospital::showDistribution() {
    cout << "Room [1]: 2 beds Available\n";
}

int Hospital::getSize() {
    return this->database.size();
}