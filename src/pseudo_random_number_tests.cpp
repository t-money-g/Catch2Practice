//
// Created by tyoun on 11/4/2021.
//

#include <catch2/catch.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include <random> // for std::mt19937

unsigned int PRNG()
{
    // our initial starting seed is 5323
    static unsigned int seed { 5313 };

    // Take the current seed and generate a new value from it
    // Due to our use of large constants and overflow , it would  be
    // ard for someone to casuallly predict what the next number is
    // going to be from the previous one.
    seed = 8253729 * seed + 2396403;

    // take the seed and return a value betwen 0 and 32767
    return seed % 32768;

}

TEST_CASE("Print 100 random numbers ")
{
    //Print 100 random numbers
    for (int count { 1 }; count <= 100; ++count)
    {
        std::cout << PRNG() << '\t';
        // if we printed 5 numbers, start a new row
        if (count % 5 == 0)
            std::cout << '\n';
    }
}


TEST_CASE("Printing 100 srand from cstdlib ")
{
    // call
    std::srand(5323); // set initial seed value to 5323

    // Due to a flaw in some compiler, we need to call std::rand() once here to get "better" random numbers.
    std::rand();

    // print 100 random numbers
    for ( int count { 1 }; count <= 100; ++count)
    {
        std::cout << std::rand() << '\t';
        // if we printed 5 numbers, start a new row
        if (count % 5 == 0)
            std::cout << '\n';
    }
}


TEST_CASE("Using time as a seed")
{
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock

    // Due to a flaw in a some compilers, we need to call std::rand() once here to get "better" random numbers.
    std::rand();

    for ( int count { 1 }; count <= 100; ++count)
    {
        std::cout << std::rand() << '\t';
        // if we printed 5 numbers, start a new row
        if (count % 5 == 0)
            std::cout << '\n';
    }

}

// Generate a random number between min and max (inclusive)
// Assumes std::srand() has already been called
// Assumes max - min <= RAND_MAX

int getRandomNumber(int min, int max)
{
    static constexpr double fraction { 1.0 / (RAND_MAX + 1.0) }; // static use for efficency, so we only calculate this value once
    // evenly distribute the random number across our range
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

TEST_CASE("Generating random numbers between two arbitrary values")
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for ( int count { 1 }; count <= 100; ++count)
    {
        std::cout << getRandomNumber(1,6) << '\t';
        // if we printed 5 numbers, start a new row
        if (count % 5 == 0)
            std::cout << '\n';
    }

}

std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr))};

TEST_CASE("Create random numbes with meserenne twister")
{
    // Create a reusable random number generator that generates uniform numbers between 1 and 6
    std::uniform_int_distribution die{ 1, 6 };

    // Print a bunch of random numbers
    for( int count { 1 }; count <= 48; ++count)
    {
        std::cout << die(mersenne) << '\t'; // generate a roll of the die here

        // if we've printed 6 numbers, start a new row
        if (count % 6 == 0)
            std::cout << '\n';
    }
}

int getRandomNumberTwister(int min, int max)
{
    std::uniform_int_distribution die{ min, max}; // we can create a distribution in any function that needs it
    return die(mersenne);
}
