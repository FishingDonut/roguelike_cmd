#pragma once

#include "global.h"
#include "entity/room.h"
#include "entity/trap.h"
#include "entity/item.h"

struct MapData
{
    static constexpr int MAX_ROOMS = 12;
    static constexpr int MAX_TRAPS = 32;
    static constexpr int MAX_ITENS = 12;
    int world[height][width];
    Room rooms[MAX_ROOMS];
    Trap traps[MAX_TRAPS];
    Item itens[MAX_ITENS];
    int countTraps = 0;
    int countItens = 0;
};
