//
// Created by tyoun on 10/25/2021.
//

#include <catch2/catch.hpp>
#include <utility>
#include <tuple>

struct Socialite { const char* birthname; };
struct Valet  { const char* surname; };
Socialite bertie {"Wilberforce"};
Valet reginald{ "Jeeves" };

struct Acquaintance { const char* nickname;};
Acquaintance hildebrand {"Tuppy" };

TEST_CASE("std::pair permits access to members") {
    std::pair<Socialite, Valet> imitable_duo { bertie, reginald};
    REQUIRE(imitable_duo.first.birthname == bertie.birthname);
    REQUIRE(imitable_duo.second.surname == reginald.surname);
}

// extract structured binding
TEST_CASE("std::pair works with structured binding") {
    std::pair<Socialite, Valet> inimitable_duo {bertie , reginald};
    auto& [idle_rich, butler] = inimitable_duo;
    REQUIRE(idle_rich.birthname == bertie.birthname);
    REQUIRE(butler.surname == reginald.surname);
}

TEST_CASE("std::tuple permits access to members ") {
    using Trio = std::tuple<Socialite, Valet, Acquaintance>;
    Trio truculent_trio { bertie, reginald, hildebrand};
    auto& bertie_ref = std::get<0>(truculent_trio);
    REQUIRE(bertie_ref.birthname == bertie.birthname);

    auto& tuppy_ref = std::get<Acquaintance>(truculent_trio);
    REQUIRE(tuppy_ref.nickname == hildebrand.nickname);
}