//
// Created by tyoun on 10/24/2021.
//

#include <catch2/catch.hpp>
#include <string>
using std::string;

TEST_CASE("String concat ") {
    string s{"a dog"};
    s += " is a dog";

    SECTION("Test concatenation") {
        REQUIRE(s == "a dog is a dog");
    }

    SECTION("String find method") {         //Return the index of first occurance of string p in s
        REQUIRE(s.find("dog")== 2);
        REQUIRE(s.find("dog", 3) == 11);
    }

    SECTION("npos? what even is this") {
        REQUIRE(s.find("doug") == string::npos);
    }

    SECTION("substring function") {
        REQUIRE(s.substr(7, 5) == "s a d");
    }

    SECTION("replace function") {
        REQUIRE(s.replace(2, 3,"frog") == "a frog is a dog");
    }

    SECTION("erase and insert function ") {
        s.replace(2, 3,"frog");
        REQUIRE(s.erase(6, 3) == "a frog a dog");

        s.insert(0, "is ");
        REQUIRE(s == "is a frog a dog");
        REQUIRE(s < "is a frog a toad");
        REQUIRE((s < "is a frog a cat") == false);
    }


}

