//
// Created by tyoun on 11/1/2021.
// cppbyexample.com/createfiles.html

#include <catch2/catch.hpp>
#include <fstream>
#include <iostream>

TEST_CASE("Just creating a file and writing to it ")
{
    std::ofstream  output("example.txt");
    output << "The answer to life, the universe and everything ";
    output << 42 << std::endl;
}