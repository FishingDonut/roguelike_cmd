#include <windows.h>

#include "include/game_data.h"
#include "include/core/map_value_to_char.h"
#include "include/core/color_char.h"
#include "include/playing/boss/render_frame_boss.h"

void render_frame_boss()
{
    if (!gameData.bossFloor)
    {
        return;
    }

    Boss &boss = gameData.boss;
    auto &oldPosition = gameData.boss.oldPosition;
    auto &hConsole = gameData.hConsole;
    auto &world = gameData.mapData.world;

    int oldInitY = oldPosition.Y - (boss.height / 2);
    int oldInitX = oldPosition.X - (boss.width / 2);
    for (int i = 0; i < boss.height; i++)
    {
        for (int j = 0; j < boss.width; j++)
        {
            int y = oldInitY + i;
            int x = oldInitX + j;

            SetConsoleCursorPosition(hConsole, {(SHORT)x, (SHORT)y});
            std::cout << mapValueToChar(world[y][x]);
        }
    }
    
    int initY = boss.position.Y - (boss.height / 2);
    int initX = boss.position.X - (boss.width / 2);

    for (int i = 0; i < boss.height; i++)
    {
        for (int j = 0; j < boss.width; j++)
        {
            int y = initY + i;
            int x = initX + j;

            SetConsoleCursorPosition(hConsole, {(SHORT)x, (SHORT)y});
            std::cout << colorChar(boss.color) << boss.skin << colorChar(COLOR_RESET);
        }
    }

    return;
}