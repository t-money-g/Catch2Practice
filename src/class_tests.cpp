//
// Created by tyoun on 11/1/2021.
//

#include <catch2/catch.hpp>
#include <iostream>
#include <string> 
// cppbyexample

struct Affection {
    int rubs = 0;
    int pats = 0;
    int scritches = 0;
};

class Dog {
public:
    void pet(const Affection& affection) {
        happiness += 1 * affection.rubs;
        happiness += 2 * affection.pats;
        happiness += 3 * affection.scritches;
    }

    void bark() {
        if (happiness <= 50)
        {
            std::cout << "woof\n";
        }
        else
        {
            std::cout << "WOOF WOOF!\n";
        }

    }
private:
    int happiness = 40;
};



