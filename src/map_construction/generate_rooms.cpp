// libs
#include <algorithm>
#include <windows.h>
#include <iostream>
#include <random>
#include <ctime>
// my libs
#include "include/global.h"
#include "include/GameData.h"
#include "include/entity/room.h"
// map_construction
#include "map_construction/generate_rooms.h"
#include "map_construction/map_construction.h"

int generate_rooms()
{
    int (&map)[height][width] = gameData.mapData.world;

    const int maxRooms = gameData.mapData.maxRooms;
    Room(&listRoom)[maxRooms] = gameData.mapData.rooms;

    int countRoom = 0;
    int min = 5;
    int max = 20;
    int border = 3;
    Room room;

    clearMap(map);

    while (countRoom < maxRooms)
    {

        if (!gameData.bossFloor && gameData.floorCount >= 2 && countRoom > 0)
        {
            room = generateRandomBossRoom(height, width, border);
        }
        else
        {
            room = generateRandomRoom(height, width, min, max, border);
        }

        if (!isColliding(listRoom, countRoom, room, 1))
        {
            createRoom(room, map);

            if (0 >= countRoom)
            {
                listRoom[countRoom++] = room;
                continue;
            }

            if (!gameData.bossFloor && gameData.floorCount >= 2 && countRoom > 0)
            {
                gameData.bossFloor = true;
                listRoom[countRoom++] = room;
                continue;
            }

            listRoom[countRoom++] = room;
            generateEnemy(listRoom[countRoom - 1], map);
        }
    }

    connectRoom(listRoom, map);
    set_position_player(listRoom[0], map);
    set_position_stair(listRoom[maxRooms - 1], map);
    gameData.floorCount++;
    return 0;
}
