#pragma once

#include "entity/room.h"
#include "entity/trap.h"

template <int h, int w>
struct MapData
{
    static constexpr int MAX_ROOMS = 12;
    static constexpr int MAX_TRAPS = 32;
    int world[h][w];
    Room rooms[MAX_ROOMS];
    Trap traps[MAX_TRAPS];
    int countTraps = 0;
};