//
// Created by tyoun on 10/25/2021.
//

#include <catch2/catch.hpp>
#include <chrono>
#include <thread>

TEST_CASE("std::chrono supports serveral units of measurement") {
    using namespace std::literals::chrono_literals;
    auto one_s = std::chrono::seconds(1);
    auto thousand_ms = 1000ms;
    REQUIRE(one_s == thousand_ms);
}

TEST_CASE("std::chrono supports duration_cast") {
    using namespace  std::chrono;
    auto billion_ns_as = duration_cast<seconds>(1'000'000'000ns);
    REQUIRE(billion_ns_as.count() == 1);
}

TEST_CASE("std::chrono used to sleep") {
    using namespace std::literals::chrono_literals;
    auto start = std::chrono::system_clock::now();
    std::this_thread::sleep_for(100ms);
    auto end = std::chrono::system_clock::now();
    REQUIRE(end - start >= 100ms);
}

