//
// Created by tyoun on 10/25/2021.
//

#include <catch2/catch.hpp>
#include <array>
#include <vector>
#include <utility>
#include <cstdint>

std::array<int, 10> static_array{}; // braced initialization will initialize array with zeroes

TEST_CASE("std::array") {
    REQUIRE(static_array[0] == 0);

    SECTION("unitialized without braced initializers") {
        std::array<int, 10> local_array;
        REQUIRE(local_array[0] != 0);
    }

    SECTION("initialized with braced initializers") {
        std::array<int, 10> local_array { 1, 1,2, 3};
        REQUIRE(local_array[0] == 1);
        REQUIRE(local_array[1] == 1);
        REQUIRE(local_array[2] == 2);
        REQUIRE(local_array[3] == 3);
        REQUIRE(local_array[4] == 0);
    }


}

// size_t object guarantees that its maximum value is sufficient to represent
// the maximum size in bytes of all objects

TEST_CASE("std::array access") {
    std::array<int, 4> fib { 1, 1, 0, 3};

    SECTION("operator[] can get and set elemetns") {
        fib[2] = 2;
        REQUIRE(fib[2] == 2);
        // fib[4] = 5;
    }

    SECTION("at() can get and set elements") {
        fib.at(2) = 2;
        REQUIRE(fib.at(2) == 2);
        REQUIRE_THROWS_AS(fib.at(4), std::out_of_range);
    }

    SECTION("get can get and set elements") {
        std::get<2>(fib) = 2;
        REQUIRE(std::get<2>(fib) == 2);
    }
}

TEST_CASE("std::array has convienence methods" ) {
    std::array<int, 4> fib { 0, 1, 2, 0};

    SECTION("front") {
        fib.front() = 1;
        REQUIRE(fib.front() == 1);
        REQUIRE(fib.front() == fib[0]);
    }

    SECTION("back") {
        fib.front() = 1;
        REQUIRE(fib.front() == 1);
        REQUIRE(fib.front() == fib[0]);
    }
}

TEST_CASE("We can obtain a pointer to the first element using") {
    std::array<char, 9> color { 'o', 'c', 't', 'a', 'r','i','n','e'};
    const auto* color_ptr = color.data();

    SECTION("data") {
        REQUIRE(*color_ptr == 'o');
    }

    SECTION("address-of front") {
        REQUIRE(&color.front() == color_ptr);
    }

    SECTION("address-of at(0)") {
        REQUIRE(&color.at(0) == color_ptr);
    }

    SECTION("address-of [0]") {
        REQUIRE(&color[0] == color_ptr);
    }

}

//ITERATORS

TEST_CASE("std::array begin/end form a half open range") {
    std::array<int, 0> e{};
    REQUIRE(e.begin() == e.end());
}

TEST_CASE("std::array iterators are pointer-like") {
    std::array<int, 3> easy_as { 1, 2, 3};
    auto iter = easy_as.begin();
    REQUIRE(*iter == 1);
    ++iter;
    REQUIRE(*iter == 2);
    ++iter;
    REQUIRE(*iter == 3);
    REQUIRE(iter == easy_as.end());
}

TEST_CASE("std::array iterator can be used as a range expression ") {
    std::array<int, 5> fib{1,1,2,3,5};
    int sum{};
    for (const auto element: fib)
        sum += element;
    REQUIRE(sum == 12);
}

/****************************************************/
/*                  the big std vector              */


TEST_CASE("std vector supports default construction") {
    std::vector<const char *> vec;
    REQUIRE(vec.empty());
}

TEST_CASE("std::vector supports braced initialization") {
    std::vector<int> fib { 1,1,2,3, 5};
    REQUIRE(fib[4] == 5);
}

TEST_CASE("std::vector supports") {
    SECTION("braced initialization") {
        std::vector<int> five_nine{ 5, 9};
        REQUIRE(five_nine[0] == 5);
        REQUIRE(five_nine[1] == 9);
    }
    SECTION("fill constructor" ) {
        std::vector<int> five_nines(5, 9);
        REQUIRE(five_nines[0] == 9);
        REQUIRE(five_nines[4] == 9);
    }
}

TEST_CASE("std::vector supports construction from iterators") {
    std::array<int, 5> fib_arr{1, 1, 2,3 , 5};
    std::vector<int> fib_vec(fib_arr.begin(), fib_arr.end());
    REQUIRE(fib_vec[4] == 5);
    REQUIRE(fib_vec.size() == fib_arr.size());
}

TEST_CASE("std::vector assign replaces existing elements") {
    std::vector<int> message { 13, 80, 110 , 114, 102,110, 101 };
    REQUIRE(message.size() == 7);
    message.assign({67, 97, 101, 115, 97, 114});
    REQUIRE(message[5] == 114);
    REQUIRE(message.size() == 6);
}

TEST_CASE("std::vector insert places new elements") {
    std::vector<int> zeros(3, 0);
    auto third_element = zeros.begin() + 2;
    zeros.insert(third_element, 10);
    REQUIRE(zeros[2] == 10);
    REQUIRE(zeros.size() == 4);
}

TEST_CASE("std::vector push_back places new element") {
    std::vector<int> zeros(3, 0);
    zeros.push_back(10);
    REQUIRE(zeros[3] == 10);
}

TEST_CASE("std::vector emplace methods forwards arguments") {
    std::vector<std::pair<int, int>> factors;
    factors.emplace_back(2, 30);
    factors.emplace_back(3, 20);
    factors.emplace_back(4, 15);
    factors.emplace(factors.begin(), 1, 60);
    REQUIRE(factors[0].first == 1);
    REQUIRE(factors[0].second == 60);

}

TEST_CASE("std::vector exposes size management methods") {
    std::vector<std::array<uint8_t, 1024>> kb_store;
    REQUIRE(kb_store.max_size() > 0);
    REQUIRE(kb_store.empty());

    size_t elements{ 1024};
    kb_store.reserve(elements);
    REQUIRE(kb_store.empty());
    REQUIRE(kb_store.empty() == elements);

    kb_store.emplace_back();
    kb_store.emplace_back();
    kb_store.emplace_back();
    REQUIRE(kb_store.size() == 3);

    kb_store.shrink_to_fit();
    REQUIRE(kb_store.capacity() >= 3);

    kb_store.clear();
    REQUIRE(kb_store.empty());
    REQUIRE(kb_store.capacity() >= 3);
}


