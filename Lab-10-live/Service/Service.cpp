//
// Created by Bogdan Zarnescu on 05.05.2022.
//

#include "Service.h"
#include <iostream>

Service::Service() = default;

Service::Service(RepoInFile &repo1, Money &money1) {
    this->repo = repo1;
    this->money = money1;
}

void Service::create(Ticket ticket) {
    this->repo.addTicketInFile(ticket);
}

void Service::update(Ticket oldTicket, Ticket newTicket) {
    this->repo.updateFromFile(oldTicket, newTicket);
}

void Service::delete1(Ticket ticket) {
    this->repo.deleteFromFile(ticket);
}

Ticket Service::getById(int id) {
    return this->repo.getTicketByIdFromFile(id);
}

vector<Ticket> Service::getAll() {
    return this->repo.getAllFromFile();
}

int Service::buyTicket(int id, int sum, int bills500, int bills200, int bills100, int bills50, int bills20, int bills10, int bills5, int bills1) {
    int price = this->repo.getTicketByIdFromFile(id).getPrice();
    if(this->repo.find(this->repo.getTicketByIdFromFile(id))) {
        if(sum < price) {
            cout << "The amount introduced is not enough!";
            return 0;
        }
        int sum1 = sum;
        int change = sum - price;
        int change1 = change;
        int chg500 = min(change1 / 500, this->money.getRon500());
        this->money.setRon500(this->money.getRon500() - chg500 + bills500);
        change1 -= 500 * chg500;

        int chg200 = min(change1 / 200, this->money.getRon200());
        this->money.setRon200(this->money.getRon200() - chg200 + bills200);
        change1 -= 200 * chg200;

        int chg100 = min(change1 / 100, this->money.getRon100());
        this->money.setRon100(this->money.getRon100() - chg100 + bills100);
        change1 -= 100 * chg100;

        int chg50 = min(change1 / 50, this->money.getRon50());
        this->money.setRon50(this->money.getRon50() - chg50 + bills50);
        change1 -= 50 * chg50;

        int chg20 = min(change1 / 20, this->money.getRon20());
        this->money.setRon20(this->money.getRon20() - chg20 + bills20);
        change1 -= 20 * chg20;

        int chg10 = min(change1 / 10, this->money.getRon10());
        this->money.setRon10(this->money.getRon10() - chg10 + bills10);
        change1 -= 10 * chg10;

        int chg5 = min(change1 / 5, this->money.getRon5());
        this->money.setRon5(this->money.getRon5() - chg5 + bills5);
        change1 -= 5 * chg5;

        int chg1 = min(change1, this->money.getRon1());
        this->money.setRon1(this->money.getRon1() - chg1 + bills1);
        change1 -= chg1;

        if(change1 == 0) {
            cout << "The change has been made!";
            return change;
        } else {
            cout << "The maximum possible change has been made!";
            return sum - change;
        }

    } else {
        return 0;
    }
}

vector<Ticket> Service::getAllTicketsFromGivenDay(string day) {
    vector<Ticket> tickets;
    for(Ticket &ticket: this->repo.getAllFromFile()) {
        if(ticket.getDay() == day) {
            tickets.push_back(ticket);
        }
    }
    return tickets;
}

Service::~Service() = default;
