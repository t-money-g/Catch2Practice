//
// Created by tyoun on 10/28/2021.
//

#include <catch2/catch.hpp>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <bitset>

TEST_CASE("std deque supports front insertion") {
    std::deque<char> deckard;
    deckard.push_front('a'); // a
    deckard.push_back('i'); // ai
    deckard.push_front('c'); // cai
    deckard.push_back('n'); // cain
    REQUIRE(deckard[0] == 'c');
    REQUIRE(deckard[1] == 'a');
    REQUIRE(deckard[2] == 'i');
    REQUIRE(deckard[3] == 'n');
}

TEST_CASE("std::list supports front insertion") {
    std::list<int> odds { 11, 22, 33, 44, 55};
    odds.remove_if([](int x) { return x % 2 == 0; });
    auto odds_iter = odds.begin();
    REQUIRE(*odds_iter == 11);
    ++odds_iter;
    REQUIRE(*odds_iter == 33);
    ++odds_iter;
    REQUIRE(*odds_iter == 55);
    ++odds_iter;
    REQUIRE(odds_iter == odds.end());
}

TEST_CASE("std::stack supports push/pop/top operations") {
    std::vector<int> vec { 1, 3};       // 1 3
    std::stack<int, decltype(vec)> easy_as(vec); // why not using alias here?
    REQUIRE(easy_as.top() == 3);
    easy_as.pop();              // 1
    easy_as.push(2);             // 1 2
    REQUIRE(easy_as.top() == 2);
    easy_as.pop();
    REQUIRE(easy_as.top() == 1); //1
    easy_as.pop();
    REQUIRE(easy_as.empty());
}

TEST_CASE("std::queue supports push/pop/front/back") {
    std::deque<int> deq{1, 2};
    std::queue<int> easy_as(deq); // 1 2

    REQUIRE(easy_as.front() == 1);
    REQUIRE(easy_as.back() == 2);
    easy_as.pop();                  //2
    easy_as.push(3);                //2 3
    REQUIRE(easy_as.front() == 2);
    REQUIRE(easy_as.back() == 3);
    easy_as.pop();
    REQUIRE(easy_as.front() == 3);
    easy_as.pop();
    REQUIRE(easy_as.empty());
}

// wraps a vector unless specified
// sorts by a comparator usually less
TEST_CASE("std::priority_queue supports push/pop") {
    std::priority_queue<double> prique;
    prique.push(1.0);       // 1.0
    prique.push(2.0);       // 2.0 1.0
    prique.push(1.5);          // 2.0 1.5 1.0
    REQUIRE(prique.top() == Approx(2.0));
    prique.pop();               // 1.5 1.0
    prique.push(1.0);           // 1.5 1.0 1.0
    REQUIRE(prique.top() == Approx(1.5));
    prique.pop();               // 1.0 1.0
    REQUIRE(prique.top() == Approx(1.0));
    prique.pop();               // 1.0
    REQUIRE(prique.top() == Approx(1.0));
    prique.pop();
    REQUIRE(prique.empty());
}

TEST_CASE("std::bitset supports integer initialization") {
    std::bitset<4> bs(0b1010);
    REQUIRE_FALSE(bs[0]);
    REQUIRE(bs[1]);
    REQUIRE_FALSE(bs[2]);
    REQUIRE(bs[3]);
}

TEST_CASE("std::bitset supports string initialization") {
    std::bitset<4> bs1(0b0110);
    std::bitset<4> bs2("0110");
    REQUIRE(bs1 == bs2);
}