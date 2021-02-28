//
// Created by cest on 27/02/21.
//
#include "PatientPrioritizer.h"
#include "Patient.h"

#ifndef UABC_PATIENTPUBLISHER_H
#define UABC_PATIENTPUBLISHER_H

class PatientPublisher {
private:
    PatientPrioritizer* patientPrioritizer;
public:
    PatientPublisher(PatientPrioritizer* patientPrioritizer) {
        this->patientPrioritizer = patientPrioritizer;
    }
    void notify() {
        this->patientPrioritizer->prioritize(new Patient());
        this->patientPrioritizer->prioritize(new Patient());
        this->patientPrioritizer->prioritize(new Patient());
    }
};


#endif //UABC_PATIENTPUBLISHER_H
