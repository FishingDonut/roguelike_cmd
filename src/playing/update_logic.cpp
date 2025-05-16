#include <iostream>
#include <thread>
#include <chrono>       

#include "../state_machine.h"
#include "../game_data.h"
#include "include/playing/update_logic.h"
#include "include/playing/player/update_player.h"
#include "include/playing/enemies/update_enemies.h"
#include "include/playing/boss/update_boss.h"

using namespace std::chrono;

namespace Playing
{
    void update_logic()
    {
        update_player();
        update_enemies();
        update_boss();
        
        std::this_thread::sleep_for(milliseconds(32));
        return;
    }
}
