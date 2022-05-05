//
// Created by Bogdan Zarnescu on 05.05.2022.
//

#ifndef LAB_9_LIVE_MONEY_H
#define LAB_9_LIVE_MONEY_H


class Money {
private:
    int ron500, ron200, ron100, ron50, ron20, ron10, ron5, ron1;
public:
    Money();
    Money(int ron500, int ron200, int ron100, int ron50, int ron20, int ron10, int ron5, int ron1);
    int getRon500();
    int getRon200();
    int getRon100();
    int getRon50();
    int getRon20();
    int getRon10();
    int getRon5();
    int getRon1();
    void setRon500(int ron500);
    void setRon200(int ron200);
    void setRon100(int ron100);
    void setRon50(int ron50);
    void setRon20(int ron20);
    void setRon10(int ron10);
    void setRon5(int ron5);
    void setRon1(int ron1);
    ~Money();
};


#endif //LAB_9_LIVE_MONEY_H
