#include <chrono>

#include "include/playing/boss/time_boss.h"
#include "include/entity/boss.h"

using namespace std::chrono;

void time_boss(Boss &boss)
{
    auto &lastTime = boss.lastTime;
    auto &IsUpdate = boss.IsUpdate;
    auto delay = boss.delay;
    auto now = steady_clock::now();
    float delta = duration<float>(now - lastTime).count();

    if (delta >= delay)
    {
        IsUpdate = true;
        lastTime = now;
        return;
    }

    IsUpdate = false;
    return;
}