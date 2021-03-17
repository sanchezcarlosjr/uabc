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
    void notifyAboutUrgentImportantPeople() {
        for(int i=0; i<100; i++) {
            this->patientPrioritizer->prioritize(new Patient(ELDERLY, HIGH, FEDERAL_GOVERNMENT));
        }
    }
    void notifyAboutNoUrgentImportantPeople() {
        for(int i=0; i<3; i++) {
            this->patientPrioritizer->prioritize(new Patient(ADULT, HIGH, CITIZEN));
        }
    }
    void notifyAboutUrgentNoImportantPeople() {
        for(int i=0; i<3; i++) {
            this->patientPrioritizer->prioritize(new Patient(ELDERLY, LOW, CITIZEN));
        }
    }
    void notifyAboutOthers() {
        for(int i=0; i<100; i++) {
            this->patientPrioritizer->prioritize(new Patient());
        }
    }
};


#endif //UABC_PATIENTPUBLISHER_H
