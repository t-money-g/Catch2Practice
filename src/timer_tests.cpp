//
// Created by tyoun on 11/8/2021.
//

#include <catch2/catch.hpp>
#include <iostream>
#include "../include/Timer.h"

#include <array>
#include <cstddef>  // for std::size_t
#include <numeric> // for std::iota
#include <algorithm>
#include <numeric>

TEST_CASE("time, is changing")
{
    Timer t;

    // code to time goes here

    std::cout << "Time elapsed: " << t.elapsed() << " seconds\n";
}

const int g_arrayElements = 10000;

void sortArray(std::array<int, g_arrayElements>& array)
{
    // step through each element of the array
    // (except the last one, which will already be sorted by the time we get there)

    for(std::size_t startIndex{ 0 }; startIndex < (g_arrayElements - 1); ++startIndex)
    {
        std::size_t smallestIndex { startIndex };

        // then look for a smaller element in the rest of the array;
        for ( std::size_t currentIndex{ startIndex + 1}; currentIndex < g_arrayElements; ++currentIndex)
        {
            // if we found an element thats smaller than our previous found smallest
            if(array[currentIndex] < array[smallestIndex])
            {
                //
                smallestIndex = currentIndex;
            }
        }
        std::swap(array[startIndex], array[smallestIndex]);
    }
}

TEST_CASE("test selection sorting perf")
{
    std::array<int, g_arrayElements> array;
    std::iota(array.rbegin(), array.rend(), 1); // fill the array with values 10000 to 1

    Timer t;
    sortArray(array);
    std::cout << "Time taken: "<< t.elapsed() << " seconds\n";

}

TEST_CASE("testing sort from the std library")
{
    std::array<int, g_arrayElements> array;
    std::iota(array.rbegin(), array.rend(), 1); // fil the array with values 10000 to 1

    Timer t;

    std::sort(array.begin(), array.end());
    std::cout << "Time taken: "<< t.elapsed() << " seconds\n";


}