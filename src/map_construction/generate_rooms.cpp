// libs
#include <algorithm>
#include <windows.h>
#include <iostream>
#include <random>
#include <ctime>
// my libs
#include "game_data.h"
#include "entity/room.h"
// map_construction
#include "map_construction/generate_rooms.h"
#include "map_construction/map_construction.h"

int generate_rooms()
{
    int (&map)[gameData.height][gameData.width] = gameData.mapData.world;

    const int MAX_ROOMS = gameData.mapData.MAX_ROOMS;
    Room(&listRoom)[MAX_ROOMS] = gameData.mapData.rooms;

    int countRoom = 0;
    int min = 5;
    int max = 20;
    int border = 3;
    Room room;

    clearMap(map);

    while (countRoom < MAX_ROOMS)
    {

        if (!gameData.bossFloor && gameData.floorCount >= 1 && countRoom >= MAX_ROOMS - 1)
        {
            room = generateRandomBossRoom(gameData.height, gameData.width, border);
        }
        else
        {
            room = generateRandomRoom(gameData.height, gameData.width, min, max, border);
        }

        if (!isColliding(listRoom, countRoom, room, 1))
        {
            createRoom(room, map);

            if (0 >= countRoom)
            {
                listRoom[countRoom++] = room;
                continue;
            }

            if (!gameData.bossFloor && gameData.floorCount >= 2 && countRoom >= MAX_ROOMS - 1)
            {
                gameData.bossFloor = true;
                listRoom[countRoom++] = room;
                generateBoss(listRoom[MAX_ROOMS - 1], map);                
                continue;
            }

            listRoom[countRoom++] = room;
            generateEnemy(listRoom[countRoom - 1], map);
        }
    }
    
    generateTrap(map);
    connectRoom(listRoom, map);
    set_position_player(listRoom[0], map);
    set_position_stair(listRoom[MAX_ROOMS - 1], map);
    gameData.floorCount++;
    return 0;
}
