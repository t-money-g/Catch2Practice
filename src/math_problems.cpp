//
// Created by tyoun on 10/30/2021.
//


#include <catch2/catch.hpp>
#include <iostream>

using std::cout, std::endl;
// write a program that calculates and prints the sum of all natural
// numbers divisible by either 3 or 5 up to a given limit
void print_three_and_five_divisibles( const int& limit) {

    int i = 1;

    while(i <= limit) {
        if(i % 3 == 0)
            cout << i << " is divisible by 3" << endl;
        if(i % 5 == 0)
            cout << i << " is divisible by 5" << endl;
        i++;
    }

}

TEST_CASE("print divisible numbers by 3 or 5 up to a limit") {

    print_three_and_five_divisibles(100);
}

TEST_CASE("FizzBuzz") {
    
        int i = 1;
    
        while(i <= 100) {
            if(i % 3 == 0 && i % 5 == 0)
                cout << "FizzBuzz" << endl;
            else if(i % 3 == 0)
                cout << "Fizz" << endl;
            else if(i % 5 == 0)
                cout << "Buzz" << endl;
            else
                cout << i << endl;
            i++;
        }
}

