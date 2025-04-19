#include <windows.h>

#include "../stateMachine.h"
#include "../GameData.h"
#include "include/playing/update_logic.h"
#include "include/playing/player/update_player.h"
#include "include/playing/enemies/update_enemies.h"

void update_logic()
{
    update_player();
    update_enemies();
    return;
}