//
// Created by Bogdan Zarnescu on 21.04.2022.
//

#include "Ticket.h"

#include <utility>

Ticket::Ticket() {
    this->id = 0;
    this->code = "";
    this->day = "";
    this->price = 0;
    this->stock = 0;
}

Ticket::Ticket(const Ticket &ticket) {
    this->id = ticket.id;
    this->code = ticket.code;
    this->day = ticket.day;
    this->price = ticket.price;
}

Ticket::Ticket(int id1, string code1, string day1, int price1, int stock1) {
    this->id = id1;
    this->code = move(code1);
    this->day = move(day1);
    this->price = price1;
    this->stock = stock1;
}

void Ticket::setId(int id1) {
    this->id = id1;
}

void Ticket::setCode(string code1) {
    this->code = move(code1);
}

void Ticket::setDay(string day1) {
    this->day = move(day1);
}

void Ticket::setPrice(int price1) {
    this->price = price1;
}

void Ticket::setStock(int stock1) {
    this->stock = stock1;
}

int Ticket::getId() {
    return this->id;
}

string Ticket::getCode() {
    return this->code;
}

string Ticket::getDay() {
    return this->day;
}

int Ticket::getPrice() {
    return this->price;
}

int Ticket::getStock() {
    return this->stock;
}

Ticket::~Ticket() {
    this->id = 0;
    this->code = "";
    this->day = "";
    this->price = 0.0;
}

Ticket &Ticket::operator=(const Ticket &ticket) {
    this->setId(ticket.id);
    this->setCode(ticket.code);
    this->setDay(ticket.day);
    this->setPrice(ticket.price);
    return *this;
}

bool Ticket::operator==(const Ticket &ticket) {
    return ((this->code == ticket.code) and (this->day == ticket.day) and (this->price == ticket.price));
}


