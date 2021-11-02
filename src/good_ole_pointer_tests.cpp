//
// Created by tyoun on 11/1/2021.
// from the trusty https://cppbyexample.com/pointer.html

#include <catch2/catch.hpp>
#include <iostream>

using std::cout;

TEST_CASE("Pointer operators")
{

    int answer = 42;
    int* theAddressOfAnswer = &answer;

    SECTION("the value")
    {
        cout <<"The answer is :" << answer << "\n";
    }
    SECTION("the address")
    {
        cout <<"The address of answer is :" << theAddressOfAnswer << "\n";
    }

    SECTION("the dereference operator ")
    {
        cout <<"The answer (through a pointer) is : " << *theAddressOfAnswer << "\n";
    }
}


TEST_CASE("pointers are variables")
{
    int mariasAge = 25;
    int answer = 42;

    int* pointer = &answer;
    int* const constPointer = &answer; // cannot be reassigned cannot change what they point to

    SECTION("reassigning ")
    {
        cout << "The value at pointer is: " << *pointer << "\n";
        cout << "The value at constPointer is: "
            << *constPointer << "\n";

        pointer = &mariasAge;
        // constPointer =&mariasAge; // we can't do this

        cout << "The value at pointer is: " << *pointer << "\n";
        cout << "The value at constPointer is: "
             << *constPointer << "\n";

    }

    SECTION("pointers can change the values of other variables")
    {
        mariasAge = 25;
        pointer = &mariasAge;

        cout << "Maria's age is: " << mariasAge << "\n";
        *pointer = 27;
        cout << "Maria's age is " << mariasAge << "\n";
    }
}

TEST_CASE("nullptr fun")
{
    int answer = 42;
    int* pointer = nullptr;

    SECTION("null check")
    {
        if (pointer)
        {
            cout << "Pointer points to value: " << *pointer << "\n";
        } else
        {
            cout << "Pointer points to nothing \n";
        }
    }

    SECTION("initialized pointer")
    {
        pointer = &answer;
        if (pointer)
        {
            cout << "Pointer points to value: " << *pointer << "\n";
        } else
        {
            cout << "Pointer points to nothing \n";
        }

    }

    SECTION("Crashing the program" )
    {
        cout << "we are going to crash " << std::endl;
        pointer = nullptr;
        //cout << *pointer << "\n";
    }
}
