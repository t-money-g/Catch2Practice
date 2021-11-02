//
// Created by tyoun on 11/1/2021.
//
#include <catch2/catch.hpp>
#include <iostream>


TEST_CASE("simple anon functions")
{
    auto square = [](int n) {return n * n; };
    int x = square(7);
    std::cout << x << "\n";

    SECTION("just some squares")
    {
        int offset = 0;
        auto square =   [offset](int n) { return (n * n) + offset;};
        auto square2 = [&offset](int n) { return (n * n) + offset;};

        int x = square(7);
        int y = square(7);

        std::cout << x << ", " << y << "\n";

        offset = -5;

        y = square(7);
        y = square2(7);
        std::cout << x << ", " << y << "\n";
    }
}

class NumberSquarer {
public:
    int square(int n)
    {
        auto square = [this](int n) { return (n * n) + offset; };
        return square(n);
    }

    void set_offset(int offset) { this->offset = offset;}

private:
    int offset = 0;
};

TEST_CASE("Testing lamba")
{
    NumberSquarer ns;

    int x = ns.square(7);
    std::cout << x << "\n";

    ns.set_offset(-5);

    x = ns.square(7);
    std::cout << x << "\n";
}

