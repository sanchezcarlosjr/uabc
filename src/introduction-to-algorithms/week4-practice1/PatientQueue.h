//
// Created by cest on 27/02/21.
//

#include "Patient.h"
#include "DataStructure/DataStructure.h"

#ifndef UABC_PATIENT_QUEUE_H
#define UABC_PATIENT_QUEUE_H

class PatientQueue {
private:
    Queue<Patient*> queue;
public:
    void attend(Patient* patient) {
        this->queue.enqueue(patient);
    }
};


#endif //UABC_PATIENT_QUEUE_H
