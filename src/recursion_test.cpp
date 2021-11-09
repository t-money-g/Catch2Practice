//
// Created by tyoun on 11/8/2021.
//

#include <catch2/catch.hpp>
#include <iostream>
#include <vector>

void countDown(int count)
{
    std::cout << "push " << count << '\n';

    if(count > 1)  // termination condition
        countDown(count -1 );

    // this only excecutes once each functions returns execution to its caller (itself)
    std::cout << "pop " << count << '\n';
}

/* return the sum of all the integers between 1 (inclusive) and
 * sumto (inclusive)
 * returns 0 for negative numbers
 */

int sumTo(int sumto)
{
    if(sumto <= 0)
        return 0;       // base case (termination condition) when user passed in an unexpected parameter (0 or negative)
    else if ( sumto == 1)
        return 1;
    else
        return sumTo(sumto - 1) + sumto;   // recursive function
}

int fibonacci(int count)
{
    if (count == 0)
        return 0;
    if (count == 1)
        return 1;
    return fibonacci(count-1) + fibonacci(count-2);
}
TEST_CASE("some basic recursive functions")
{
    SECTION("Demo a recursive function pushing and popping off the stack")
    {
        countDown(5);
    }

    SECTION("a more useful recursive")
    {
        sumTo(5);
    }
}

TEST_CASE("testing fibonacci")
{
    for (int count { 0 }; count < 13; ++count)
        std::cout << fibonacci(count) << " ";
}

int fibonacci_memoization(int count)
{
    // we'll use a staic std::vector to cache calculated results
    static std::vector<int> results { 0, 1 };

    // if we've already seen this count, then use the cache'd result
    if (count < static_cast<int>(std::size(results)))
        return results[count];
    else
    {
        // otherwise calculate the new result and add it
        results.push_back(fibonacci_memoization(count - 1) + fibonacci_memoization(count - 2));
        return results[count];
    }
}