#include <windows.h>

#include "include/GameData.h"
#include "include/core/mapValueToChar.h"
#include "include/core/colorChar.h"
#include "include/playing/enemies/render_frame_enemy.h"

void render_frame_enemy()
{
    const int maxRooms = gameData.mapData.maxRooms;
    HANDLE hConsole = gameData.hConsole;
    Room(&rooms)[maxRooms] = gameData.mapData.rooms;

    for (int j = 0; j < maxRooms; j++)
    {
        Room &room = rooms[j];
        for (int i = 0; i < room.enemyCount; i++)
        {
            Enemy &enemy = room.enemies[i];
            SetConsoleCursorPosition(hConsole, {enemy.oldPosition});
            cout << mapValueToChar(enemy.previousObject);
            SetConsoleCursorPosition(hConsole, {enemy.position});
            cout << colorChar(enemy.color) << enemy.skin << colorChar(COLOR_RESET);
        }
    }
}