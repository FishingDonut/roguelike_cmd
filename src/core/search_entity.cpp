#include <windows.h>
#include "game_data.h"
#include "entity/trap.h"
#include "core/search_entity.h"

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

    Trap trap;
    trap.reset();
    return trap;
}

Item searchItem(COORD position)
{
    int count = gameData.mapData.countItens;
    Item* items = gameData.mapData.itens;

    for (int i = 0; i < count; i++)
    {
        if (position.Y == items[i].y && position.X == items[i].x)
        {
            return items[i];
        }
    }

    return Item(); // retorno vazio
}
