//
// Created by cest on 27/02/21.
//
#include "PatientPublisher.h"
#include "PatientPrioritizer.h"
#ifndef UABC_SIMULATOR_H
#define UABC_SIMULATOR_H
#include <thread>

void notifyAboutUrgentImportantPeopleThread(PatientPublisher patientPublisher)
{
    patientPublisher.notifyAboutUrgentImportantPeople();
}

void notifyNoUrgentImportantPeopleThread(PatientPublisher patientPublisher)
{
    patientPublisher.notifyAboutNoUrgentImportantPeople();
}

void notifyUrgentNoImportantPeopleThread(PatientPublisher patientPublisher)
{
    patientPublisher.notifyAboutUrgentNoImportantPeople();
}

void notifyOtherPeopleThread(PatientPublisher patientPublisher)
{
    patientPublisher.notifyAboutOthers();
}

class Simulator {
public:
    void simulate() {
        PatientPublisher patientPublisher(new PatientPrioritizer());
        cout << "Bootstrapping...\n";
        thread urgentImportantPeopleFirstThread (notifyAboutUrgentImportantPeopleThread,patientPublisher);
        thread urgentImportantPeopleSecondThread (notifyAboutUrgentImportantPeopleThread,patientPublisher);
        thread noUrgentImportantPeopleThread (notifyNoUrgentImportantPeopleThread,patientPublisher);
        thread urgentNoImportantPeopleThread (notifyUrgentNoImportantPeopleThread,patientPublisher);
        thread otherPeopleThread (notifyOtherPeopleThread,patientPublisher);
        urgentImportantPeopleFirstThread.join();
        urgentImportantPeopleSecondThread.join();
        noUrgentImportantPeopleThread.join();
        urgentNoImportantPeopleThread.join();
        otherPeopleThread.join();
        cout << "Completed.\n";
    }
};


#endif //UABC_SIMULATOR_H
