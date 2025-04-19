#pragma once

#include <windows.h>
#include "global.h"
#include "entity/player.h"
#include "mapData.h"

struct GameData
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    Player player = Player();
    MapData mapData = MapData();
    bool running = true;
    int seed;
};

extern GameData gameData;