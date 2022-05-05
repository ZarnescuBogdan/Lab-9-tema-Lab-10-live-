//
// Created by Bogdan Zarnescu on 21.04.2022.
//

#ifndef LAB_9_LIVE_REPO_H
#define LAB_9_LIVE_REPO_H

#include "../Ticket/Ticket.h"
#include <vector>

using namespace std;

class Repo {
protected:
    int amountInTheCashRegister;
    int bills500;
    int bills200;
    int bills100;
    int bills50;
    int bills20;
    int bills10;
    int bills5;
    int bills1;
    vector<Ticket> tickets;
public:
    Repo();
    void addTicket(Ticket &ticket);
    void deleteTicket(Ticket ticket);
    void modifyTicket(Ticket oldTicket, Ticket newTicket);
    vector<Ticket> getAll();
    Ticket getTicketById(int id);
    int getSize();
    ~Repo();
};


#endif //LAB_9_LIVE_REPO_H
