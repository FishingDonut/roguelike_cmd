#pragma once

#include <chrono>

using namespace std::chrono;

struct ClockData
{
    int hour;
    int minute;
    int second;
    float delay = 1.0f;
    steady_clock::time_point lastTime = steady_clock::now();
};