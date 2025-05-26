#include <chrono>
#include <conio.h>

#include "core/clock.h"
#include "game_data.h"

using namespace std::chrono;

void time_clock()
{
    auto &lastTime = gameData.clockData.lastTime;
    auto &second = gameData.clockData.second;
    auto &minute = gameData.clockData.minute;
    auto &hour = gameData.clockData.hour;
    auto now = steady_clock::now();
    long long time_total = std::chrono::duration_cast<std::chrono::seconds>(now - lastTime).count();

    hour = time_total / 36000;
    minute = (time_total % 36000) / 60;
    second = time_total % 60;
    return;
}