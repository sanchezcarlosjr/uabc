//
// Created by cest on 17/03/21.
//

#include "Hospital.h"

Hospital::Hospital() {
    int size = print<int>("How many rooms do you start hospital?");
    for(int i=0; i<size; i++) {
        this->database.push_back(new Room());
    }
}

void Hospital::simulate() {

}

int Hospital::getSize() {
    return this->database.size();
}