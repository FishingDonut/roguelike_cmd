#pragma once

#include "global.h"
#include "entity/room.h"

struct MapData
{
    static constexpr int maxRooms = 12;
    int world[height][width];
    int explored[height][width];
    Room rooms[maxRooms];
};
