#include <chrono>
#include <conio.h>

#include "include/playing/player/time_player.h"
#include "include/entity/player.h"

using namespace std::chrono;

void time_player(Player &player)
{
    auto &lastTime = player.lastTime;
    auto &IsUpdate = player.IsUpdate;
    auto delay = player.delay;
    auto now = steady_clock::now();
    float delta = duration<float>(now - lastTime).count();

    if (delta >= delay)
    {
        if(kbhit()){
            IsUpdate = true;
            lastTime = now;
        }
        return;
    }

    IsUpdate = false;
    return;
}