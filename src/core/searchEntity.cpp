#include <windows.h>

#include "GameData.h"
#include "entity/trap.h"
#include "core/searchEntity.h"

Trap searchTrap(COORD position)
{
    int countTraps = gameData.mapData.countTraps;
    auto &traps = gameData.mapData.traps;

    for (int i = 0; i < countTraps; i++)
    {
        Trap &trap = traps[i];
        if (position.Y == trap.position.Y && position.X == trap.position.X)
        {
            trap.visible = true;
            trap.active = true;
            trap.currentSkin = trap.visibleSkin;
            return trap;
        }
    }

    Trap trap = Trap();
    trap.reset();
    return trap;
}