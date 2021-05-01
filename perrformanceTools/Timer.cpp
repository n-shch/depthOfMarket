//
// Created by nikita on 01.05.2021.
//

#include "Timer.h"

void Timer::Stop() {
    auto endTimepoint = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::nanoseconds>(startTimepoint).time_since_epoch().count();
    auto end = std::chrono::time_point_cast<std::chrono::nanoseconds>(endTimepoint).time_since_epoch().count();
    auto duration = end - start;
    std::cout << duration << " наносекунд ";

}
