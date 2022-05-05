//
// Created by Bogdan Zarnescu on 21.04.2022.
//

#include "tests.h"
#include "../Ticket/Ticket.h"
#include <cassert>
#include "../Repo/Repo.h"
#include "../Service/Service.h"
#include "../Repo/RepoInFile.h"
#include <fstream>

using namespace std;

void testConstructorTicket() {
    Ticket ticket;
    assert(ticket.getId() == 0);
    assert(ticket.getCode().empty());
    assert(ticket.getDay().empty());
    assert(ticket.getPrice() == 0.0);
}

void testConstructor2Ticket() {
    Ticket ticket(1, "SB-CJ", "Luni", 50);
    assert(ticket.getId() == 1);
    assert(ticket.getCode() == "SB-CJ");
    assert(ticket.getDay() == "Luni");
    assert(ticket.getPrice() == 50);
}

void testSetterGetter() {
    Ticket ticket;
    ticket.setId(1);
    ticket.setCode("SB-CJ");
    ticket.setDay("Luni");
    ticket.setPrice(50);
    assert(ticket.getId() == 1);
    assert(ticket.getCode() == "SB-CJ");
    assert(ticket.getDay() == "Luni");
    assert(ticket.getPrice() == 50);
}

void testRepoAddTicket() {
    Repo repo;
    Ticket t1, t2, t3;
    t1.setId(1);
    t1.setCode("SB-CJ");
    t1.setDay("Luni");
    t1.setPrice(50);

    t2.setId(2);
    t2.setCode("CJ-BV");
    t2.setDay("Marti");
    t2.setPrice(40);

    t3.setId(3);
    t3.setCode("CJ-GL");
    t3.setDay("Miercuri");
    t3.setPrice(100);

    repo.addTicket(t1);
    repo.addTicket(t2);
    repo.addTicket(t3);
    assert(repo.getSize() == 3);
    assert(repo.getTicketById(1) == t1);
    assert(repo.getTicketById(2) == t2);
    assert(repo.getTicketById(3) == t3);
}

void testRepoDeleteTicket() {
    Repo repo;
    Ticket t1, t2, t3;
    t1.setId(1);
    t1.setCode("SB-CJ");
    t1.setDay("Luni");
    t1.setPrice(50);

    t2.setId(2);
    t2.setCode("CJ-BV");
    t2.setDay("Marti");
    t2.setPrice(40);

    t3.setId(3);
    t3.setCode("CJ-GL");
    t3.setDay("Miercuri");
    t3.setPrice(100);

    repo.addTicket(t1);
    repo.addTicket(t2);
    repo.addTicket(t3);

    assert(repo.getSize() == 3);

    repo.deleteTicket(t2);

    assert(repo.getSize() == 2);
}

void testRepoUpdateTicket() {
    Repo repo;
    Ticket t1, t2, t3;
    t1.setId(1);
    t1.setCode("SB-CJ");
    t1.setDay("Luni");
    t1.setPrice(50);

    t2.setId(2);
    t2.setCode("CJ-BV");
    t2.setDay("Marti");
    t2.setPrice(40);

    t3.setId(2);
    t3.setCode("CJ-GL");
    t3.setDay("Miercuri");
    t3.setPrice(100);

    repo.addTicket(t1);
    repo.addTicket(t2);

    assert(repo.getTicketById(2) == t2);

    repo.modifyTicket(t2, t3);

    assert(repo.getTicketById(2) == t3);
}

void testServiceCreate() {
    Service service;
    Ticket t1(1, "SB-CJ", "Luni", 50);
    Ticket t2(2, "CJ-BV", "Marti", 40);
    Ticket t3(3, "CJ-GL", "Miercuri", 100);
    service.create(t1);
    service.create(t2);
    service.create(t3);

    assert(service.getAll().size() == 3);
    assert(service.getById(1) == t1);
}

void testServiceDelete() {
    Service service;
    Ticket t1(1, "SB-CJ", "Luni", 50);
    Ticket t2(2, "CJ-BV", "Marti", 40);
    Ticket t3(3, "CJ-GL", "Miercuri", 100);
    service.create(t1);
    service.create(t2);
    service.create(t3);

    assert(service.getAll().size() == 3);

    service.delete1(t1);

    assert(service.getAll().size() == 2);
}

void testServiceUpdate() {
    Service service;
    Ticket t1(1, "SB-CJ", "Luni", 50);
    Ticket t2(2, "CJ-BV", "Marti", 40);
    Ticket t3(2, "CJ-GL", "Miercuri", 100);
    service.create(t1);
    service.create(t2);

    assert(service.getById(2) == t2);

    service.update(t2, t3);

    assert(service.getById(2) == t3);
}

void testRepoInFileAdd() {
    remove("ticket.txt");
    fstream file;
    file.open("ticket.txt", ios::in);
    file.open("ticket.txt", ios::out);
    RepoInFile repoInFile("ticket.txt");
    Ticket ticket(1, "SB-CJ", "Luni", 50);
    repoInFile.addTicketInFile(ticket);
    assert(repoInFile.getAllFromFile().size() == 1);
}

void testRepoInFileDelete() {
    remove("ticket.txt");
    fstream file;
    file.open("ticket.txt", ios::in);
    file.open("ticket.txt", ios::out);
    RepoInFile repoInFile("ticket.txt");
    Ticket ticket(1, "SB-CJ", "Luni", 50);
    repoInFile.addTicketInFile(ticket);
    assert(repoInFile.getAllFromFile().size() == 1);
    repoInFile.deleteFromFile(ticket);
    assert(repoInFile.getAllFromFile().size() == 0);
}

void testRepoInFileUpdate() {
    remove("ticket.txt");
    fstream file;
    file.open("ticket.txt", ios::in);
    file.open("ticket.txt", ios::out);
    RepoInFile repoInFile("ticket.txt");
    Ticket t1(1, "SB-CJ", "Luni", 50);
    Ticket t2(1, "CJ-BV", "Marti", 40);
    repoInFile.addTicketInFile(t1);
    assert(repoInFile.getTicketByIdFromFile(1) == t1);
    repoInFile.updateFromFile(t1, t2);
    assert(repoInFile.getTicketByIdFromFile(1) == t2);
}

void testRepoInFile() {
    remove("ticketsTest.txt");
    fstream f;
    f.open("ticketsTest.txt", ios::in);
    f.open("ticketsTest.txt", ios::out);
    RepoInFile repoInFile("ticketsTest.txt");

    Ticket t1(1, "SB-CJ", "Luni", 50);
    Ticket t2(2, "CJ-BV", "Marti", 40);
    Ticket t3(3, "CJ-GL", "Miercuri", 100);

    repoInFile.addTicketInFile(t1);
    repoInFile.addTicketInFile(t2);
    repoInFile.addTicketInFile(t3);

    assert(repoInFile.sizeFile() == 3);
    assert(repoInFile.getTicketByIdFromFile(1) == t1);
}

void testBuyTicket() {
    remove("ticketsTest.txt");
    fstream f;
    f.open("ticketsTest.txt", ios::in);
    f.open("ticketsTest.txt", ios::out);
    RepoInFile repoInFile("ticketsTest.txt");
    Money money = Money(10, 10, 10, 15, 15, 15, 27, 40);

    Service service(repoInFile, money);
    Ticket t1(1, "SB-CJ", "Luni", 50);
    Ticket t2(2, "CJ-BV", "Marti", 40);
    Ticket t3(3, "CJ-GL", "Miercuri", 100);

    service.create(t1);
    service.create(t2);
    service.create(t3);

    int change = service.buyTicket(1, 50, 0, 0, 0, 1, 0, 0, 0, 0);
    assert(change == 0);
    change = service.buyTicket(2, 45, 0, 0, 0, 0, 2, 1, 0, 0);
    assert(change == 5);
    change = service.buyTicket(3, 80, 0, 0, 0, 1, 1, 1, 0, 0);
    assert(change == 0);
}

void testGetAllTicketsFromGivenDay() {
    remove("ticketsTeste.txt");
    fstream f;
    f.open("ticketsTeste.txt", ios::in);
    f.open("ticketsTeste.txt", ios::out);
    RepoInFile repoInFile("ticketsTeste.txt");
    Money money;

    Service service(repoInFile, money);
    Ticket t1(1, "SB-CJ", "Luni", 50);
    Ticket t2(2, "CJ-BV", "Marti", 40);
    Ticket t3(3, "CJ-GL", "Marti", 100);

    service.create(t1);
    service.create(t2);
    service.create(t3);

    vector<Ticket> tickets = service.getAllTicketsFromGivenDay("Marti");
    assert(tickets.size() == 2);
    assert(tickets[0] == t2);
    assert(tickets[0] == t3);
}

void testAll() {
    testConstructorTicket();
    testConstructor2Ticket();
    testSetterGetter();
    testRepoAddTicket();
    testRepoDeleteTicket();
    testRepoUpdateTicket();
    testServiceCreate();
    testServiceDelete();
    testServiceUpdate();
    testRepoInFileAdd();
    testRepoInFileDelete();
    testRepoInFileUpdate();
    testRepoInFile();
    testBuyTicket();
}
