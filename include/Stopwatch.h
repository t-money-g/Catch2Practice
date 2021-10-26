//
// Created by tyoun on 10/25/2021.
//

#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <chrono>

class Stopwatch {

public:
    Stopwatch(std::chrono::nanoseconds& result)
        :result { result },
        start{ std::chrono::high_resolution_clock::now()} {}

    ~Stopwatch() {
        result = std::chrono::high_resolution_clock::now() - start;
    }
private:
    std::chrono::nanoseconds& result;
    const std::chrono::time_point<std::chrono::high_resolution_clock> start;
};

#endif //CATCH2PRACTICE_STOPWATCH_H
