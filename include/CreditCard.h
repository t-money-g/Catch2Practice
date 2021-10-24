//
// Created by tyoun on 10/24/2021.
//

#ifndef CREDITCARD_H
#define CREDITCARD_H

#include <string>
#include <iostream>

class CreditCard {
public:
    CreditCard(const std::string& no,const std::string& nm, int lim, double bal = 0);

    [[nodiscard]] std::string     getNumber() const   { return number; }
    [[nodiscard]] std::string     getName() const     { return name; }
    [[nodiscard]] double          getBalance() const  { return balance; }
    [[nodiscard]] int             getLimit() const    { return limit; }

    bool chargeIt(double price);            // make a charge
    void makePayment(double payment);       // make a payment
private:
    std::string number;
    std::string name;
    int         limit;
    double      balance;
};

std::ostream& operator << (std::ostream& out, const CreditCard& c);

#endif //CREDITCARD_H
