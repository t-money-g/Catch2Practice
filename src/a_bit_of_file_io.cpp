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

TEST_CASE("Reading a single file with istream")
{
    std::string filename {"file_with_single_number.txt"};
    std::ifstream input{filename};

    if(!input.is_open())
    {
        std::cerr << "Coulding read file: " << filename << "\n";
    }

    int number = 0;
    input >> number;
    std::cout << "The number is " << number << ".\n";
}

TEST_CASE("reading multiple lines from a file")
{
    std::string filename{"file_with_multiple_lines.txt"};
    std::ifstream input{filename};

    if(!input.is_open()) {
        std::cerr << "Couldn't read file: " << filename << "\n";
    }

    std::vector<std::string> lines;
    for (std::string line; std::getline(input, line); ) {
        // move the value of line into lines
        lines.push_back(std::move(line));
    }

    for (const auto& line :lines)
    {
        std::cout << line << "\n";
    }
}