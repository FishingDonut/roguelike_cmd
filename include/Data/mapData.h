#pragma once

#include "global.h"
#include "entity/room.h"

struct MapData
{
    static constexpr int maxRooms = 12;
    int world[height][width];
    Room rooms[maxRooms];
};
