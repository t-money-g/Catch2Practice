//
// Created by tyoun on 10/23/2021.
//

#include <catch2/catch.hpp>
#include <vector>
int sqrt(int number) {

    int lower_bound = 1;
    int upper_bound = number / 2;

    while(upper_bound >= lower_bound) {
        int mid_val = (lower_bound + upper_bound) / 2;
        if(mid_val * mid_val > number)
            upper_bound = mid_val - 1;
        else
            lower_bound = mid_val + 1;
    }
    return (lower_bound + upper_bound) / 2;
}


TEST_CASE("Sqrt of an integer returns the approximate sqrt") {
   REQUIRE(sqrt(9) == 3);
   REQUIRE(sqrt(25) == 5);
   REQUIRE(sqrt(144) == 12);

   REQUIRE(sqrt(0) == 0);
}