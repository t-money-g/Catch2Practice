// ==========================================================================
// Originally:
// Software written by Boguslaw Cyganek (C) to be used with the book:
// INTRODUCTION TO PROGRAMMING WITH C++ FOR ENGINEERS
// Published by Wiley, 2020
//
// The software is supplied as is and for educational purposes
// without any guarantees nor responsibility of its use in any application. 
//
// Additions made by @tyoungjr - https://github.com/tyoungjr/CmakeCppTemplate
// ==========================================================================


// Macro to determine whether to run tests or skip the runner
// Unfortunately build times will still build the catch library which isn't ideal
// for releases.
#define TESTS_ENABLED 1


#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp>
#include <iostream>
#include <string>
#include "CreditCard.h"

using std::string, std::cout, std::endl;
using std::cin;

//generic output operator for pairs (limited solution)
template <typename T1, typename T2>
std::ostream& operator << (std::ostream& strm, const std::pair<T1,T2>& p)
{
    return strm <<"[" << p.first << "," << p.second << "]";
}

void testCard();

int main(int argc, char* argv[])
{
#if  TESTS_ENABLED == 1
    int result = Catch::Session().run(argc, argv);
#endif

    cout << "Good day!" << endl;

    //testCard();


#if TESTS_ENABLED == 1
    return result;
#else
    return 0;
#endif

}

