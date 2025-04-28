#pragma once

#include "global.h"
#include "entity/room.h"
#include "entity/trap.h"

struct MapData
{
    static constexpr int MAX_ROOMS = 12;
    static constexpr int MAX_TRAPS = 32;
    int world[height][width];
    Room rooms[MAX_ROOMS];
    Trap traps[MAX_TRAPS];
    int countTraps = 0;
};
