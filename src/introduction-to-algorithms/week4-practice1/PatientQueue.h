//
// Created by cest on 27/02/21.
//

#include "Patient.h"
#include "DataStructure/DataStructure.h"
#include <chrono>
#include <thread>
#include <string>

#ifndef UABC_PATIENT_QUEUE_H
#define UABC_PATIENT_QUEUE_H

class PatientQueue {
private:
    Queue<Patient*> queue;
    string title = "";
    int amount = 1;
public:
    PatientQueue(string title) {
        this->title = title;
    }
    void attend(Patient* newPatient) {
        this->queue.enqueue(newPatient);
        this_thread::sleep_for(std::chrono::milliseconds(1000));
        Patient* actualPatient = this->queue.dequeue();
        cout << "Attending patient "<< this->amount++ << " as " << this->title << "...\n";
        actualPatient->talk();
        this_thread::sleep_for(std::chrono::milliseconds(1500));
        cout << "Ready... Next!";
        cout << "\n\n";
    }
};


#endif //UABC_PATIENT_QUEUE_H
