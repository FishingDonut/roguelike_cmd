#pragma once

#include "global.h"
#include "entity/room.h"

struct MapData
{
    static constexpr int maxRooms = 7;
    int currentObject;
    int previousObject;
    int mapAll[height][width];
    Room rooms[maxRooms];
};
