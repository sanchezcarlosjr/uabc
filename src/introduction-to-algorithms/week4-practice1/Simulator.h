//
// Created by cest on 27/02/21.
//
#include "PatientPublisher.h"
#include "PatientPrioritizer.h"
#ifndef UABC_SIMULATOR_H
#define UABC_SIMULATOR_H

class Simulator {
public:
    void simulate() {
        PatientPublisher patientPublisher(new PatientPrioritizer());
        patientPublisher.notify();
    }
};


#endif //UABC_SIMULATOR_H
