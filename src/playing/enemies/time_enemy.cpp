#include <chrono>

#include "include/playing/enemies/time_enemy.h"
#include "include/entity/enemy.h"

using namespace std::chrono;

void time_enemy(Enemy &enemy)
{
    auto &lastTime = enemy.lastTime;
    auto &IsUpdate = enemy.IsUpdate;
    auto delay = enemy.delay;
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