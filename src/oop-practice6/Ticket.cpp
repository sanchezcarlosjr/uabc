//
// Created by cest on 05/03/21.
//

#include "Ticket.h"

int Ticket::amountOfSoldTickets = 0;
int Ticket::amountOfAvailableTickets = 0;

Ticket::Ticket() {
    Ticket::amountOfAvailableTickets++;
    this->id = Random::generateNumberBetween(1000,10000);
}

string Ticket::toString() {
    stringstream s;
    string status = this->sold ? this->person->getName() : "AVAILABLE";
    s << this->id << "\t" << status;
    return s.str();
}

string Ticket::sell(Persons* persons) {
    if (this->sold) {
        return "UNAVAILABLE TICKET!";
    }
    this->person = persons->create();
    Ticket::amountOfSoldTickets++;
    Ticket::amountOfAvailableTickets--;
    this->sold = true;
    return "SOLD TICKET!";
}

int Ticket::getId() {
    return this->id;
}

int Ticket::getAmountOfAvailableTickets() {
    return Ticket::amountOfAvailableTickets;
}

int Ticket::getAmountOfSoldTickets() {
    return Ticket::amountOfSoldTickets;
}

Ticket::~Ticket() {
    if (Ticket::amountOfSoldTickets > 0) {
        Ticket::amountOfSoldTickets--;
    }
    if (Ticket::amountOfAvailableTickets > 0) {
        Ticket::amountOfAvailableTickets--;
    }
}