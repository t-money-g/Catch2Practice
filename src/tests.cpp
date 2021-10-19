//
// Created by tyoun on 10/18/2021.
// Simple example on running tests with catch


#include <catch2/catch.hpp>
#include <vector>


unsigned int Factorial(unsigned int number) {
    return number > 1 ? Factorial(number -1 ) * number : 1;
}

// Simple tests
TEST_CASE("Facts are facts and are not cap", "[factorial]") {
    REQUIRE(Factorial(0) == 1);
    REQUIRE(Factorial(1) == 1);
    REQUIRE(Factorial(2) == 2);
    REQUIRE(Factorial(3) == 6);
    REQUIRE(Factorial(10) == 3'628'800);
}

/**
* Test cases and sections - gives a philosophy on catch2
* use this pattern as setup and teardown feature
*/
TEST_CASE( "vectors can be sized and resized", "[vector]" ) {
    std::vector<int> v(5);

    REQUIRE(v.size() == 5);
    REQUIRE(v.capacity() >= 5);

    SECTION( "resizing bigger changes size and capacity" ) {
        v.resize( 10 );
        REQUIRE( v.size() == 10 );
        REQUIRE( v.capacity() >= 10);
    }

    SECTION( "resizing smaller changes size but not capacity " ) {
        v.resize( 0 );
        REQUIRE( v.size() == 0);
        REQUIRE( v.capacity() >= 5);
    }

    SECTION( "reserving bigger changes capacity but not size" ) {
        v.reserve( 10 );
        REQUIRE( v.size() == 5);
        REQUIRE( v.capacity() >= 10 );

        // the power of sections really shows , when we need to execute a sequence of checked operations.
        SECTION("reserving smaller again does not change capacity" ) {
            v.reserve( 7 );
            REQUIRE( v.capacity() >= 10 );
        }
    }

    SECTION( "reserving smaller does not change size or capacity" ) {
        v.reserve( 0 );
        REQUIRE( v.size() == 5 );
        REQUIRE( v.capacity() >= 5);
    }


}


TEST_CASE( "Natural expressions ") {

    CHECK( )
}