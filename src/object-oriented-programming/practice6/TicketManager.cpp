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
    for (int i = 0; i < 10; i++) {
        this->showAll();
        int id = this->ask();
        if (this->contains(id)) {
            cout << this->database[id]->sell() << "\n";
        } else {
            cout << id << " doesn't exist. "<< "\n";
        }
        system("sleep 5; clear");
    }
}

void TicketManager::showAll() {
    cout << "Available: " << Ticket::getAmountOfAvailableTickets() << " Sold Tickets: "<< Ticket::getAmountOfSoldTickets() << "\n";
    cout << "ID\tBuyer\n";
    for (auto& iter: this->database) {
        cout << iter.second->toString() << "\n";
    }
}

int TicketManager::ask() {
    int id = 0;
    cout << "Which ticket do you want sell? ";
    cin >> id;
    return id;
}

bool TicketManager::contains(int id) {
    map<int,Ticket*>::iterator it = this->database.find(id);
    if (it != this->database.end())
        return true;
    return false;
}