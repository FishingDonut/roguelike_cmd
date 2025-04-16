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
};

extern GameData gameData;