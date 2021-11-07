//
// Created by tyoun on 11/7/2021.
//

#include <catch2/catch.hpp>
#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

TEST_CASE("Using std::find to find an element by value")
{
    std::array arr{ 13, 90, 99, 5, 40, 80 };

    std::cout << "Enter a value to search for and replace with: ";
    int search {};
    int replace {};
    std::cin >> search >> replace;

    // Input validation omitted

    // std::find returns n iterator pointing to the found element (or the end of the container)
    // we'll store it in a variable using type inference to deduce the type of
    // the interator (since we don't care )

    auto found{ std::find(arr.begin(), arr.end(), search) };

    // algorithms that don't find what they were looking for return the end iterator
    // we can access it by using the end() member function.
    if (found == arr.end())
    {
        std::cout << "Could not find " << search << '\n';
    }
    else
    {
        // override the found element
        *found = replace;
    }

    for (int i : arr)
    {
        std::cout << i <<  ' ';
    }

    std::cout << '\n';
}

// Our function will return true if the element matches
bool containsNut(std::string_view str)
{
    // std:string_view::find returns std::string_view::npos if it doesn't find
    // the subsctring. Otherwise it returns the index where the substring occurs in
    // in str.
    return (str.find("nut") != std::string_view::npos);
}

TEST_CASE("String contains nut using count_if")
{
    std::array<std::string_view, 4> arr { "apple", "banana", "walnut", "lemon"};

    // scan the array to see if any elements contain the "nut" substring
    auto found { std::find_if(arr.begin(), arr.end(), containsNut) };

    if (found == arr.end())
    {
        std::cout << "No nuts\n";
    }
    else
    {
        std::cout << "Found " << *found << '\n';
    }

    SECTION("How many nuts are in the array of string views")
    {
        std::array<std::string_view, 5> arr { "apple", "banana", "walnut", "lemon", "peanut" };

        auto nuts { std::count_if(arr.begin(), arr.end(), containsNut) };
        std::cout << "Counted " << nuts << " nuts(s)\n";

    }
}

// custom sort
bool greater(int a, int b)
{
    // order @a before @b if a is greater than @b
    return( a > b);
}

TEST_CASE("Custom Sort with function")
{
    std::array arr{ 13, 90, 99, 5, 40, 80 };

    // pass greater to std::sort
    std::sort(arr.begin(), arr.end(), greater);
    for (int i : arr)
    {
        std::cout << i <<  ' ';
    }

    std::cout << '\n';
}

// instead of the above code we can use the std libray's greater comparison
//std::sort(arr.begin(), arr.end90, std::greater{});
// Before C++17 we had to specify the element type when we create std::greater
//std::sort(arr.begin(), arr.end(), std::greater<int>{}); // use the standard library greater comparison

