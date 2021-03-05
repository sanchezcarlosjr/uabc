//
// Created by cest on 05/03/21.
//

#include <string>
#include <sstream>
#include "Person.h"
#include "Math/Random.h"
using namespace std;

#ifndef UABC_TICKET_H
#define UABC_TICKET_H

class Ticket {
private:
    int id;
    static int amountOfAvailableTickets;
    static int amountOfSoldTickets;
    bool sold;
    Person* person;
public:
    Ticket();
    ~Ticket();
    string sell();
    string toString();
    int getId();
    int static getAmountOfAvailableTickets();
    int static getAmountOfSoldTickets();
};


#endif //UABC_TICKET_H
