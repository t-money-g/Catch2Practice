//
// Created by tyoun on 10/24/2021.
//
#include <vector>
#include "CreditCard.h"
#include <iostream>

using std::vector, std::cout;

void testCard() {

    vector<CreditCard*> wallet(10);                 // vector of 10 CreditCard pointers
    wallet[0] = new CreditCard("1111 5135 8013 1559", "John Bowman", 2500);
    wallet[1] = new CreditCard("1121 5135 8013 1559", "John Bowman", 3500);
    wallet[2] = new CreditCard("8001 5235 8013 1552", "John Bowman", 5000);

    for (int j=1; j <= 16; j++) {                       // make some charges
        wallet[0]->chargeIt(double(j));                 // explicitly cast to double
        wallet[1]->chargeIt(2 * j);                // implicitly cast to double
        wallet[2]->chargeIt(double(3 * j));
    }

    cout << "Card payments:\n";
    for (int i = 0; i < 3; i++) {
        cout << *wallet[i];

        while (wallet[i]->getBalance() > 100.0) {
            wallet[i]->makePayment(100.0);
            cout << "New balance = " << wallet[i]->getBalance() << "\n";
        }
        cout << "\n";
        delete wallet[i];
    }

}
