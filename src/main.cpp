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
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#include "empty.h"


int main(int argc, char* argv[])
{
#if  TESTS_ENABLED == 1
    int result = Catch::Session().run(argc, argv);
#endif

    std::cout << "Good day!" << std::endl;

#if TESTS_ENABLED == 1
    return result;
#else
    return 0;
#endif

}

