//
// Created by tyoun on 10/18/2021.
// Simple example on running tests with catch


#include <catch2/catch.hpp>

unsigned int Factorial(unsigned int number) {
    return number > 1 ? Factorial(number -1 ) * number : 1;
}

TEST_CASE("Facts are facts and are not cap", "[factorial]") {
    REQUIRE(Factorial(0) == 1);
    REQUIRE(Factorial(1) == 1);
    REQUIRE(Factorial(2) == 2);
    REQUIRE(Factorial(3) == 6);
    REQUIRE(Factorial(10) == 3'628'800);
}


