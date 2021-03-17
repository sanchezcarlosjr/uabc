//
// Created by cest on 05/03/21.
//

#include <iostream>
#include "Persons.h"
#include <map>
#include <vector>
#include "Ticket.h"
#include <stdlib.h>
using namespace std;

#ifndef UABC_TICKETMANAGER_H
#define UABC_TICKETMANAGER_H

class TicketManager {
private:
    map <int,Ticket*> database;
    Persons persons;
    void showAll();
    int ask();
public:
    TicketManager();
    bool contains(int id);
    void start();
};


#endif //UABC_TICKETMANAGER_H
