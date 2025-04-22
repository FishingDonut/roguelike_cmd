#include <windows.h>

#include "../stateMachine.h"
#include "../GameData.h"
#include "include/playing/update_logic.h"
#include "include/playing/player/update_player.h"
#include "include/playing/enemies/update_enemies.h"
#include "include/playing/explored/update_exploration.h"

namespace Playing
{
    void update_logic()
    {
        update_player();
        update_enemies();
        updateExploration();
        return;
    }
}