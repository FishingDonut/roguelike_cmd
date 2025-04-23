#include <iostream>
#include <windows.h>

#include "../stateMachine.h"
#include "../GameData.h"
#include "core/colorChar.h"
#include "core/mapValueToChar.h"
#include "include/playing/enemies/render_frame_enemy.h"

void render_frame_enemy()
{
    const int maxRooms = gameData.mapData.maxRooms;
    auto &explored = gameData.mapData.explored;
    HANDLE hConsole = gameData.hConsole;
    Room(&rooms)[maxRooms] = gameData.mapData.rooms;

    for (int i = 0; i < maxRooms; i++)
    {
        Room &room = rooms[i];
        int &enemyCount = room.enemyCount;

        // if(!room.isInRoom(gameData.player.position)){
        //     continue;
        // }

        for (int j = 0; j < enemyCount; j++)
        {
            Enemy &enemy = room.enemies[j];
            Colors color = enemy.color;
            COORD &position = enemy.position;

            if (explored[position.Y][position.X] == 0)
            {
                SetConsoleCursorPosition(hConsole, {position});
                std::cout << colorChar(color) << enemy.skin << colorChar(COLOR_RESET);
            }
            else
            {
                SetConsoleCursorPosition(hConsole, {position});
                std::cout << mapValueToChar(0);
            }
        }
    }

    return;
}