#include <windows.h>

#include "include/GameData.h"
#include "include/core/mapValueToChar.h"
#include "include/core/colorChar.h"
#include "include/playing/boss/render_frame_boss.h"

void render_frame_boss()
{
    if(!gameData.bossFloor){
        return;
    }

    Boss &boss = gameData.boss;
    auto& hConsole = gameData.hConsole;
    auto& world = gameData.mapData.world;
    
    int initY = boss.position.Y - (boss.height / 2);
    int initX = boss.position.X - (boss.width / 2);

    for (int i = 0; i < boss.height; i++)
    {
        for (int j = 0; j < boss.width; j++){
            int y = initY + i;
            int x = initX + j;
            
            SetConsoleCursorPosition(hConsole, {(SHORT)x, (SHORT)y});
            std::cout << colorChar(boss.color) << mapValueToChar(world[y][x]) << colorChar(COLOR_RESET);
        }
    }

    return;
}