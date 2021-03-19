//
// Created by cest on 17/03/21.
//

#include "Hospital.h"

Hospital::Hospital() {
    this->size = print<int>("How many rooms do you start hospital?");
}

void Hospital::simulate() {

}

int Hospital::getSize() {
    return this->size;
}