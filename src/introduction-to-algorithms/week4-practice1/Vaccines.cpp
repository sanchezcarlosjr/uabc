//
// Created by cest on 27/02/21.
//

#include "Vaccines.h"

Vaccines *Vaccines::singleton = nullptr;

Vaccines *Vaccines::GetInstance() {
    if (singleton == nullptr) {
        singleton = new Vaccines();
    }
    return singleton;
}

void Vaccines::increase() {
    if (this->usedVaccines > this->availableVaccines) {
        cout << "\n=====================================================\n";
        cout << "\t\t" << "All vaccines have been used";
        cout << "\n=====================================================\n";
        throw 200;
    }
    this->usedVaccines++;
}