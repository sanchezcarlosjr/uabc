//
// Created by cest on 05/03/21.
//

#include <iostream>
#include "Person.h"
#include <map>
#include "Ticket.h"
using namespace std;

#ifndef UABC_TICKETMANAGER_H
#define UABC_TICKETMANAGER_H

class TicketManager {
private:
    map <int,Ticket*> database;
    void showAll();
public:
    TicketManager();
    void start();
};


#endif //UABC_TICKETMANAGER_H
