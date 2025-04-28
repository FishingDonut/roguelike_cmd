#include <windows.h>

#include "include/GameData.h"
#include "include/core/mapValueToChar.h"
#include "include/core/colorChar.h"
#include "include/playing/enemies/render_frame_enemy.h"

void render_frame_enemy()
{
    const int MAX_ROOMS = gameData.mapData.MAX_ROOMS;
    HANDLE hConsole = gameData.hConsole;
    Room(&rooms)[MAX_ROOMS] = gameData.mapData.rooms;

    for (int j = 0; j < MAX_ROOMS; j++)
    {
        Room &room = rooms[j];
        for (int i = 0; i < room.enemyCount; i++)
        {
            Enemy &enemy = room.enemies[i];
            if(!enemy.alive){
                continue;
            }
            SetConsoleCursorPosition(hConsole, {enemy.oldPosition});
            cout << mapValueToChar(enemy.previousObject);
            SetConsoleCursorPosition(hConsole, {enemy.position});
            cout << colorChar(enemy.color) << enemy.skin << colorChar(COLOR_RESET);
        }
    }
}