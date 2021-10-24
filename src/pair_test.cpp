//
// Created by tyoun on 10/24/2021.
//

#include <catch2/catch.hpp>

#include <tuple>



using IntFloatPair = std::pair<int,float>;



TEST_CASE("Pair elements have their own interface") {
    IntFloatPair p(42, 3.14);

    REQUIRE(std::get<0>(p) == 42); // p.first
    REQUIRE(std::get<1>(p) == 3.14f); // p.second

    REQUIRE(std::tuple_size<IntFloatPair>::value == 2);
   // REQUIRE(std::tuple_element<0,IntFloatPair>::type);

    SECTION("Pair construction") {
        std::pair<int,float> pog;
        REQUIRE(std::get<0>(pog) == 0);
    }


}