//
// Created by nikita on 01.05.2021.
//

#ifndef TESTY_TIMER_H
#define TESTY_TIMER_H

#include "chrono"
#include <iostream>

class Timer {
public:
    Timer() {
        startTimepoint = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
    }

    void Stop();

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTimepoint;
};


#endif //TESTY_TIMER_H
