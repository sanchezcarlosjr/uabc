//
// Created by cest on 05/03/21.
//

#include "TicketManager.h"

TicketManager::TicketManager() {
    for(int i=0; i<10; i++) {
        Ticket* ticket = new Ticket();
        this->database[ticket->getId()] = ticket;
    }
}

void TicketManager::start() {
    this->showAll();
}

void TicketManager::showAll() {
    cout << "ID\tBuyer\n";
    for (auto& iter: this->database) {
        cout << iter.second->toString() << "\n";
    }
}