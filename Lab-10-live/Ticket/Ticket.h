//
// Created by Bogdan Zarnescu on 21.04.2022.
//

#ifndef LAB_9_LIVE_TICKET_H
#define LAB_9_LIVE_TICKET_H
#include <string>

using namespace std;

class Ticket {
private:
    int id;
    string code;
    string day;
    int price;
    int stock;
public:
    Ticket();
    Ticket(const Ticket &ticket);
    Ticket(int id1, string code1, string day1, int price1, int stock1);
    void setId(int id1);
    void setCode(string code1);
    void setDay(string day1);
    void setPrice(int price1);
    void setStock(int stock1);
    int getId();
    string getCode();
    string getDay();
    int getPrice();
    int getStock();
    Ticket &operator=(const Ticket& ticket);
    bool operator==(const Ticket& ticket);
    ~Ticket();
};


#endif //LAB_9_LIVE_TICKET_H
