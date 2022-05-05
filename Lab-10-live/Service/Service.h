//
// Created by Bogdan Zarnescu on 05.05.2022.
//

#ifndef LAB_9_LIVE_SERVICE_H
#define LAB_9_LIVE_SERVICE_H

#include "../Repo/RepoInFile.h"
#include "../Money/Money.h"

class Service {
private:
    RepoInFile repo;
    Money money = Money(10, 10, 10, 15, 15, 15, 27, 40);
public:
    Service();
    Service(RepoInFile &repo1, Money &money1);
    void create(Ticket ticket);
    void update(Ticket oldTicket, Ticket newTicket);
    void delete1(Ticket ticket);
    Ticket getById(int id);
    vector<Ticket> getAll();
    int buyTicket(int id, int sum, int bills500, int bills200, int bills100, int bills50, int bills20, int bills10, int bills5, int bills1);
    vector<Ticket> getAllTicketsFromGivenDay(string day);
    ~Service();
};


#endif //LAB_9_LIVE_SERVICE_H
