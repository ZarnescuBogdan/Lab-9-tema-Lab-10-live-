//
// Created by Bogdan Zarnescu on 21.04.2022.
//

#include "Repo.h"

Repo::Repo() = default;

void Repo::addTicket(Ticket &ticket) {
    this->tickets.push_back(ticket);
}

void Repo::deleteTicket(Ticket ticket) {
    for(int i = 0; i < tickets.size(); i++) {
        if(tickets[i].getId() == ticket.getId()) {
            tickets.erase(tickets.begin() + i);
        }
    }
}

void Repo::modifyTicket(Ticket oldTicket, Ticket newTicket) {
    for(int i = 0; i < tickets.size(); i++) {
        if(tickets[i].getId() == oldTicket.getId()) {
            tickets[i] = newTicket;
        }
    }
}

Ticket Repo::getTicketById(int id) {
    for(Ticket &ticket: tickets) {
        if(ticket.getId() == id) {
            return ticket;
        }
    }
    throw runtime_error("No ticket with given id was found!");
}

vector<Ticket> Repo::getAll() {
    return this->tickets;
}

int Repo::getSize() {
    return this->tickets.size();
}

Repo::~Repo() = default;
