//
// Created by tyoun on 10/28/2021.
//
#include <catch2/catch.hpp>
#include <set>
#include <functional>
#include <unordered_set>
#include <map>
#include <iostream>


TEST_CASE("std::set supports") {
    std::set<int> emp;
    std::set<int> fib { 1, 1, 2, 3, 5 };

    SECTION("default construction") {
        REQUIRE(emp.empty());
    }

    SECTION("braced initialization") {
        REQUIRE(fib.size() == 4);
    }

    SECTION("copy construction") {
        auto fib_copy(fib);
        REQUIRE(fib.size() == 4);
        REQUIRE(fib_copy.size() == 4);
    }

    SECTION("move construction") {
        auto fib_moved(std::move(fib));
        REQUIRE(fib.empty());
        REQUIRE(fib_moved.size() == 4);
    }

    SECTION("range construction") {
        std::array<int, 5> fib_array{1,1,2,3,5};
        std::set<int> fib_set(fib_array.cbegin(), fib_array.cend());
        REQUIRE(fib_set.size() == 4);

    }

}

TEST_CASE("std::set allows access") {
    std::set<int> fib { 1, 1, 2, 3, 5};

    SECTION("with find") {
        REQUIRE(*fib.find(3) == 3);
        REQUIRE(fib.find(100) == fib.end());
    }

    SECTION("with count") {
        REQUIRE(fib.count(3) == 1);
        REQUIRE(fib.count(100) == 0);
    }

    SECTION("with lower_bound") {
        auto itr = fib.lower_bound(3);    // returns an iterator to the first element not less than the key??!
        REQUIRE(*itr == 3);                 //wtf
    }

    SECTION("with upper bound") {
        auto itr = fib.upper_bound(3);
        REQUIRE(*itr == 5);
    }
    SECTION("with equal range") {
        auto pair_itr = fib.equal_range(3);
        REQUIRE(*pair_itr.first == 3);
        REQUIRE(*pair_itr.second == 5);
    }
}

TEST_CASE("std::set allows insertion") {
    std::set<int> fib { 1, 1, 2, 3, 5};

    SECTION("with insert") {
        fib.insert(8);
        REQUIRE(fib.find(8) != fib.end());
    }

    SECTION("with emplace") {
        fib.emplace(8);
        REQUIRE(fib.find(8) != fib.end());
    }

    SECTION("with emplace_hint") {
        fib.emplace_hint(fib.end(), 8);
        REQUIRE(fib.find(8) != fib.end());
    }
}

TEST_CASE("std::set allows removal") {
    std::set<int> fib { 1, 1, 2, 3,5 };
    SECTION("with erase") {
        fib.erase(3);
        REQUIRE(fib.find(3) == fib.end());
    }
    SECTION("with clear") {
        fib.clear();
        REQUIRE(fib.empty());
    }
}

TEST_CASE("std::multiset handles handles non unique elements") {
    std::multiset<int> fib{ 1, 1, 2, 3, 5};
    SECTION("as reflected by size") {
        REQUIRE(fib.size() == 5);
    }

    SECTION("and count returns values greater than 1") {
        REQUIRE(fib.count(1) == 2);
    }

    SECTION("and equal_range returns non-trivial ranges") {
        auto[begin, end] = fib.equal_range(1);
        REQUIRE(*begin == 1);
        ++begin;
        REQUIRE(*begin == 1);

        REQUIRE(begin == end);
    }
}

TEST_CASE("std::hash<long> returns") {
    std::hash<long> hasher;
    auto hash_code_42 = hasher(42);
    SECTION("equal hash codes for equal keys") {
        REQUIRE(hash_code_42 == hasher(42));
    }

    SECTION("unequal hash codes for unequal keys") {
        REQUIRE(hash_code_42 != hasher(43));
    }

    SECTION("std::equal_to<long> returns") {
        std::equal_to<long> long_equal_to;

        SECTION("true when arguments equal") {
            REQUIRE(long_equal_to(42, 42));
        }

        SECTION("false when arguments unequal") {
            REQUIRE_FALSE(long_equal_to(42, 43));
        }
    }
}

TEST_CASE("std::unordered_set") {
    std::unordered_set<unsigned long> sheep(100);

    SECTION("allows bucket count specification on construction") {
        REQUIRE(sheep.bucket_count() >= 100);
        REQUIRE(sheep.bucket_count() <= sheep.max_bucket_count());
        REQUIRE(sheep.max_load_factor() == Approx(1.0));
    }

    SECTION("allows us to reserve space for elements") {
        sheep.reserve(100'000);
        sheep.insert(0);
        REQUIRE(sheep.load_factor() <= 0.00001);
    }
}

// maps used as an associative array
auto colour_of_magic = "Colour of Magic";
auto the_light_fantastic = "The Light Fantastic";
auto equal_rites = "Equal Rites";
auto mort = "Mort";

TEST_CASE("std::map supports") {
    SECTION("default construction") {
        std::map<const char*, int> emp;
        REQUIRE(emp.empty());
    }

    SECTION("braced initialization") {
        std::map<const char*, int> pub_year {
            { colour_of_magic, 1983 },
            { the_light_fantastic, 1986 },
            { equal_rites, 1987 },
            { mort, 1987 },
        };
        REQUIRE(pub_year.size() == 4);
    }
}

TEST_CASE("std::map is an associative array with") {
    std::map<const char*, int> pub_year {
        { colour_of_magic, 1983},
        { the_light_fantastic, 1986},
    };

    SECTION("operator[]") {
        REQUIRE(pub_year[colour_of_magic] == 1983);

        pub_year[equal_rites] = 1987;
        REQUIRE(pub_year[equal_rites] == 1987);

        REQUIRE(pub_year[mort] == 0);
    }

    SECTION("an at method") {
        REQUIRE(pub_year.at(colour_of_magic) == 1983);
        REQUIRE_THROWS_AS(pub_year.at(equal_rites), std::out_of_range);
    }
}

TEST_CASE("std::map supports insert") {
    std::map<const char*, int> pub_year;
    pub_year.insert(std::pair<const char*, int>("1983", 2));
    REQUIRE(pub_year.at("1983") == 2);
}

TEST_CASE("loop through a map?")
{
    std::map<std::string, float> fruitPrices {
            { "Apple", 0.69f },
            { "Banana", 0.98f },
            { "Orange", 1.1f },
    };

    for(auto [fruit, price] : fruitPrices) {
        std::cout << fruit << " s cost $" << price << ".\n";
    }
}

// using std::strin 
struct ShortestString {
    bool operator()(const std::string& a, const std::string& b) const {
        return a.size() <= b.size();
    }
};

TEST_CASE("std::map supports sorting") {
    std::map<std::string, int, ShortestString> shortest_strings {
        { "The", 3 },
        { "Quick", 5 },
        { "Brown", 6 },
        { "Fox", 3 },
        { "Jumps", 5 }}; 

    for(auto [word, length] : shortest_strings) {
        std::cout << word << " is " << length << " characters long.\n";
    }
}