//
// Created by tyoun on 10/24/2021.
//

#include <catch2/catch.hpp>
#include <string>
#include <iostream>

using std::string;

TEST_CASE("String operations  ") {
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

    SECTION("Don't forget about string.append")
    {
        string sentence{"She"};
        sentence.append(" Is playing");
        sentence += " the piano";
        std::cout << sentence << "\n";
    }

    SECTION("More concatenation")
    {
        string subject{ "She"};
        string verb {"is playing"};
        string object {"the piano"};

        string sentence = subject + " " + verb + " " + object + ".";
        std::cout << sentence << "\n";
    }
}

