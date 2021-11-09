//
// Created by tyoun on 11/8/2021.
//

#ifndef CATCH2PRACTICE_TIMER_H
#define CATCH2PRACTICE_TIMER_H

#include <chrono>

class Timer
{
private:
    // type aliases to make accessing nested type easier
    using clock_type = std::chrono::steady_clock;
    using second_type = std::chrono::duration<double, std::ratio<1>>;

    std::chrono::time_point<clock_type> m_beg;
public:
    Timer() : m_beg{ clock_type::now() }{}

    void reset()
    {
        m_beg = clock_type::now();
    }

    double elapsed() const
    {
        return std::chrono::duration_cast<second_type>(clock_type::now() - m_beg).count();
    }
};
#endif //CATCH2PRACTICE_TIMER_H
