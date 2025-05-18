#pragma once

#include <windows.h>
#include "entity/player.h"
#include "entity/boss.h"
#include "Data/Status.h"
#include "Data/mapData.h"
#include "Data/MenuData.h"
#include "Data/ConfigData.h"

struct GameData
{
    static constexpr int width = 156;
    static constexpr int height = 44;
    Player player = Player();
    Boss boss;
    Enemy currentEnemy;
    MapData<height, width> mapData;
    MenuData menuData = MenuData();
    Config config = Config();
    bool running = true;
    int floorCount = 0;
    bool bossFloor = false;
    int seed;
    int score = 0;
    Status status = Status(); 
};

extern GameData gameData;