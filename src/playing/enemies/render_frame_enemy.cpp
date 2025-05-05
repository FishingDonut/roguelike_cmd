#include <windows.h>

#include "include/game_data.h"
#include "include/core/map_value_to_char.h"
#include "include/core/color_char.h"
#include "include/playing/enemies/render_frame_enemy.h"

void render_frame_enemy()
{
    const int MAX_ROOMS = gameData.mapData.MAX_ROOMS;
    HANDLE hConsole = game_data.hConsole;
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