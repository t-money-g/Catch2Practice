//
// Created by tyoun on 11/1/2021.
// Yes, this is extremely simple and rudimentary but this can still be
// useful as a reference
// Check out https://cppbyexample.com/print.html

#include <catch2/catch.hpp>
#include <iostream>
#include <utility>


void print_hello() {
    std::cout << "Hello, World!\n";
}

struct Point {
    float x,y,z;
};

std::ostream& operator<<(std::ostream& o, const Point& p) {
    o << p.x << ", " << p.y << ", " << p.z;
    return o;
}

// more comfortable just Print()
// using a function template to just forward args to the left shift opertor
template <typename ...Args>
void print(Args&& ...args) {
    (std::cout << ... << std::forward<Args>(args));
}

TEST_CASE("Printing to the console") {

    SECTION("simple printing") {
        print_hello();
    }

    SECTION("chain multiple objects together of different types") {
        std::cout << "Mars is " << 1.5 << "AU from the Sun.\n";
    }

    SECTION("Printing a custom type") {
        Point p {1.0f, 2.0f, 3.0f};
        std::cout << p << "\n";
    }

    SECTION("more printing with a function template") {
        print("Mars is ", 1.5, "AU from the sun.\n");
    }
}