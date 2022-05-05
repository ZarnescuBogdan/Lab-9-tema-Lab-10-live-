//
// Created by Bogdan Zarnescu on 05.05.2022.
//

#include "RepoInFile.h"
#include <fstream>

RepoInFile::RepoInFile() = default;

RepoInFile::RepoInFile(const string &filename) {
    this->filename = filename;
    ifstream f(filename);
    while (!f.eof()) {
        int id;
        string code, day;
        int price;
        f >> id >> code >> day >> price;
        if(!code.empty() and !day.empty()) {
            Ticket ticket(id, code, day, price);
            this->tickets.push_back(ticket);
        }
    }
    f.close();
}

RepoInFile::~RepoInFile() {
    fstream f(this->filename);
    if(f.is_open()) {
        f.close();
    }
}

void RepoInFile::saveToFile() {
    ofstream g(this->filename);
    for(Ticket &ticket: this->tickets) {
        g << ticket.getId() << " " << ticket.getCode() << " " << ticket.getDay() << " " << ticket.getPrice() << endl;
    }
    g.close();
}

void RepoInFile::addTicketInFile(Ticket &ticket) {
    this->tickets.push_back(ticket);
    this->saveToFile();
}

void RepoInFile::deleteFromFile(Ticket ticket) {
    for(int i = 0; i < this->tickets.size(); i++) {
        if(tickets[i].getId() == ticket.getId()) {
            tickets.erase(tickets.begin() + i);
        }
    }
    this->saveToFile();
}

void RepoInFile::updateFromFile(Ticket oldTicket, Ticket newTicket) {
    for(int i = 0; i < this->tickets.size(); i++) {
        if(tickets[i].getId() == oldTicket.getId()) {
            tickets[i] = newTicket;
        }
    }
    this->saveToFile();
}

vector<Ticket> RepoInFile::getAllFromFile() {
    return this->tickets;
}

Ticket RepoInFile::getTicketByIdFromFile(int id) {
    for(Ticket &ticket: this->tickets) {
        if(ticket.getId() == id) {
            return ticket;
        }
    }
    throw runtime_error("No ticket with given id found!");
}

bool RepoInFile::find(Ticket ticket) {
    for(Ticket &ticket1: this->tickets) {
        if(ticket1 == ticket) {
            return true;
        }
    }
    return false;
}

int RepoInFile::sizeFile() {
    return (int)tickets.size();
}
