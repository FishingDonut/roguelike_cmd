#include <algorithm>
#include <windows.h>
#include <iostream>
#include <random>
#include <ctime>

#include "include/global.h"
#include "include/GameData.h"
#include "include/entity/room.h"
#include "include/core/mapValueToChar.h"

const int maxRoom = 7;

void clearMap(int (&map)[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            map[i][j] = 1;
        }
    }
    return;
}

bool isCollind(Room rooms[maxRoom], int roomCount, Room newRoom)
{
    Room otherRoom;

    for (int i = 0; i < roomCount; i++)
    {
        otherRoom = rooms[i];
        if (newRoom.x < otherRoom.x + otherRoom.width &&
            newRoom.x + newRoom.width > otherRoom.x &&
            newRoom.y < otherRoom.y + otherRoom.height &&
            newRoom.y + newRoom.height > otherRoom.y)
        {
            return true;
        }
    }

    return false;
}

void createRoom(Room newRoom, int (&map)[height][width])
{
    for (int i = newRoom.y; i < newRoom.y + newRoom.height; i++)
    {
        for (int j = newRoom.x; j < newRoom.x + newRoom.width; j++)
        {
            map[i][j] = 0;
        }
    }
}

void connectRoom(Room (&rooms)[maxRoom], int (&map)[height][width])
{
    Room room, nearest;

    for (int i = 0; i < maxRoom; i++)
    {
        room = rooms[i];
        nearest = rooms[i];
        for (int j = i + 1; j < maxRoom; j++)
        {
            if (!rooms[j].connect)
            {
                nearest = rooms[j];
            }
        }

        if (room.connect)
        {
            return;
        }

        nearest.connect = true;

        int ax = room.centerX();
        int bx = nearest.centerX();

        int ay = room.centerY();
        int by = nearest.centerY();

        if (rand() % 2)
        {
            for (int x = std::min(ax, bx); x <= std::max(ax, bx); x++)
            {
                map[ay][x] = 0;
            }
            for (int y = std::min(ay, by); y <= std::max(ay, by); y++)
            {
                map[y][bx] = 0;
            }
        }
        else
        {
            for (int x = std::min(ax, bx); x <= std::max(ax, bx); x++)
            {
                map[by][x] = 0;
            }
            for (int y = std::min(ay, by); y <= std::max(ay, by); y++)
            {
                map[y][ax] = 0;
            }
        }
    }
    return;
}

void set_position_player(Room room, int (&map)[height][width]){
    Player &player = gameData.player;
    player.setPosition(room.centerX(), room.centerY());
    player.newPosition = player.position;
    map[room.centerY()][room.centerX()] = player.valueMap;
    
    return;
}

int generate_rooms()
{
    srand(time(0));

    int (&map)[height][width] = gameData.mapData.mapAll;

    Room listRoom[maxRoom];
    int coutRoom = 0;
    int min = 5;
    int max = 20;

    clearMap(map);

    for (int i = 0; i < maxRoom; i++)
    {
        Room room;

        room.height = min + (rand() % (max - min + 1));
        room.width = min + (rand() % (max - min + 1));

        room.y = (rand() % (height - room.height - 1));
        room.x = (rand() % (width - room.width - 1));

        if (isCollind(listRoom, coutRoom, room))
        {
            i--;
            continue;
        }

        createRoom(room, map);
        listRoom[coutRoom++] = room;
    }
    connectRoom(listRoom, map);
    set_position_player(listRoom[0], map);

    return 0;
}
