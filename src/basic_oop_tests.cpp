//
// Created by tyoun on 11/4/2021.
//
// good ole learncpp.com


#include <catch2/catch.hpp>

#include <iostream>
#include <string>
#include <vector>

// just like any other tool, oop is there for exploitation and profit.


struct DateStruct
{
    int year {};
    int month {};
    int day {};
};

void print(const DateStruct & date)
{
    std::cout << date.year << '/' << date.month << '/' << date.day;
}


TEST_CASE("Date struct contains date data")
{
    DateStruct today { 2021, 11, 04 };

    SECTION("BTW do you know what today is?")
    {
        today.day = 4;
        print(today);
    }
}

// initialize date class the same way as the st
class DateClass
{
public:
    int m_year {};
    int m_month {};
    int m_day {};

    void print() // defines a member function named print()
    {
        std::cout << m_year << '/' << m_month << '/' << m_day;
    }
};

TEST_CASE("Date class contains date data and has member functions ")
{
    DateClass today { 2021, 11, 04 };

    SECTION("BTW do you know what today is?")
    {
        today.m_day = 4;
        today.print();
    }
}

// Example of a class with more data types

class Employee
{
public:
    std::string m_name {};
    int m_id{};
    double m_wage {};

    void print()
    {
        std::cout << "Name: " << m_name <<
                " Id: " << m_id <<
                " Wage: $" << m_wage << '\n';
    }
};

TEST_CASE("Test two employees")
{
    Employee alex { "Alex", 34, 45.00 };
    Employee joe  { "Joe", 2, 22.25 };

    // Print out the employee information
    alex.print();
    joe.print();

}

// classes don't require fwd declartations

/*
 * void x()
 * {
 * // you can't call y() from here unless the complier has already see na foward declaration for y()
 * }
 * void y()
 * {
 * }
 *
 * With member functions this limitation doesnt' apply
 * class Foo
 * {
 * public:
 *      void x() { y(); }   // okay to call y() hear, even though y() isn't defined until later in this class
 *
 *      void y() { };
 * };
 */

// classes can have member types or nested types including type aliases

class Calculator
{
public:
    using number_type = int;    // this is a nested type alias

    std::vector<number_type> m_resultHistory{};

    number_type add(number_type a, number_type b)
    {
        auto result{ a + b };
        m_resultHistory.push_back(result);
        return result;
    }
};

TEST_CASE("Test member types and nested alias")
{
    Calculator calculator;

    std::cout << calculator.add(3, 4) << '\n'; // 7
    std::cout << calculator.add(99, 24) << '\n'; // 123

    // cool type reference
    for (Calculator::number_type result : calculator.m_resultHistory)
    {
        std::cout << result << '\n';
    }
}


// public and private members an oveture
struct DateStructPublic
{
    int month {}; // public by default
    int day {};   /// public by default
    int year {};  // public by default
};

TEST_CASE("Public methods")
{
    DateStructPublic date;
    date.month = 10;
    date.day = 14;
    date.year = 2020;
}

class DateClassPrivate // members are private by default
{
public:
    int m_month {}; //private
    int m_day {};   // private by default
    int m_year {};  // private by default
};

TEST_CASE("Access violation wont compile")
{
    DateClassPrivate date;
    date.m_month = 10;
    date.m_day = 14;
    date.m_year = 2020;
}


class DateClassMixingAccessSpecifiers
{
    int m_month {};     // private by default
    int m_day {};       // private by default ,
    int m_year {};
public:
    void setDate(int month, int day, int year) // public can be accessed by anyone
    {
        // set date can access the private members of the class because it is a member of the class itself
        m_month = month;
        m_day = day;
        m_year = year;
    }

    void print()    // public, can be accessed by anyone
    {
        std::cout << m_month << '/' << m_day << '/' << m_year;
    }

    // I didn't know this!
    void copyFrom(const DateClassMixingAccessSpecifiers& d)
    {
        // Note that we can access the private members of d directly
        m_month = d.m_month;
        m_day = d.m_day;
        m_year = d.m_year;
    }
};

TEST_CASE("mixed access specifiers")
{
    DateClassMixingAccessSpecifiers date;
    date.setDate(10, 13, 2010);         // ok because setDate() is public

    DateClassMixingAccessSpecifiers copy {};
    copy.copyFrom(date);                                // okay bc copyFrom() is public
    date.print();                                       // okay , because print() is public
    std::cout << '\n';
}




