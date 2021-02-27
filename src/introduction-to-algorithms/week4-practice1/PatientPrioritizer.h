//
// Created by cest on 27/02/21.
//

#include "Patient.h"
#include "PatientQueue.h"

#ifndef UABC_PATIENTPRIORITIZER_H
#define UABC_PATIENTPRIORITIZER_H


class PatientPrioritizer {
private:
    PatientQueue urgentImportantPatientQueue;
    PatientQueue noUrgentImportantPatientQueue;
    PatientQueue urgentNoImportantPatientQueue;
    PatientQueue noUrgentNoImportantPatientQueue;
public:
    void prioritize(Patient* patient) {
        switch(patient->getPriority()) {
            case URGENT_IMPORTANT:
                this->urgentImportantPatientQueue.attend(patient);
                break;
            case NO_URGENT_IMPORTANT:
                this->noUrgentImportantPatientQueue.attend(patient);
                break;
            case URGENT_NO_IMPORTANT:
                this->urgentNoImportantPatientQueue.attend(patient);
                break;
            case NO_URGENT_NO_IMPORTANT:
                this->noUrgentNoImportantPatientQueue.attend(patient);
                break;
        }
    }
};


#endif //UABC_PATIENTPRIORITIZER_H
