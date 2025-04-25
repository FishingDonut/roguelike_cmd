#pragma once

#include <windows.h>
#include "global.h"
#include "entity/player.h"
#include "Data/mapData.h"
#include "Data/MenuData.h"
#include "Data/ConfigData.h"

struct GameData
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    Player player = Player();
    MapData mapData = MapData();
    MenuData menuData = MenuData();
    Config config = Config();
    bool running = true;
    int floorCount = 0;
    bool bossFloor = false;
    int seed;
};

extern GameData gameData;