//
// Created by cest on 27/02/21.
//
#include "PatientPrioritizer.h"
#include "Patient.h"
#include <chrono>
#include <thread>

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
       for(int i=0; i<3; i++) {
            this->patientPrioritizer->prioritize(new Patient(ELDERLY, HIGH, FEDERAL_GOVERNMENT));
            this_thread::sleep_for(std::chrono::milliseconds(1000));
       }
        for(int i=0; i<3; i++) {
            this->patientPrioritizer->prioritize(new Patient(ADULT, HIGH, CITIZEN));
            this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
        for(int i=0; i<3; i++) {
            this->patientPrioritizer->prioritize(new Patient(ELDERLY, LOW, CITIZEN));
            this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
        for(int i=0; i<100; i++) {
            this->patientPrioritizer->prioritize(new Patient());
            this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }
};


#endif //UABC_PATIENTPUBLISHER_H
