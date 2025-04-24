#pragma once

#include <windows.h>
#include "global.h"
#include "entity/player.h"
#include "Data/mapData.h"
#include "Data/MenuData.h"

struct GameData
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    Player player = Player();
    MapData mapData = MapData();
    MenuData menuData = MenuData();
    int screenBuffer[height][width];
    bool running = true;
    int seed;
};

extern GameData gameData;