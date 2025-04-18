#include <algorithm>
#include <windows.h>
#include <iostream>
#include <random>
#include <ctime>

#include "include/global.h"
#include "include/GameData.h"
#include "include/entity/room.h"
#include "include/entity/enemy.h"
#include "include/core/mapValueToChar.h"

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

bool isColliding(Room rooms[], int roomCount, Room newRoom, int padding = 1)
{
    for (int i = 0; i < roomCount; i++)
    {
        Room other = rooms[i];

        bool overlapX = newRoom.x - padding < other.x + other.width + padding &&
                        newRoom.x + newRoom.width + padding > other.x - padding;

        bool overlapY = newRoom.y - padding < other.y + other.height + padding &&
                        newRoom.y + newRoom.height + padding > other.y - padding;

        if (overlapX && overlapY)
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
    return;
}

void generateEnemy(Room &newRoom, int (&map)[height][width])
{
    int countEnemy = 0;

    int newPX;
    int newPY;

    for (int i = 0; i < newRoom.maxEnemy; i++)
    {
        if ((rand() % 10) > 2)
        {
            Enemy enemy = Enemy();
            enemy.health = 10;
            enemy.damage = 10;

            newPX = newRoom.x + (rand() % newRoom.width);
            newPY = newRoom.y + (rand() % newRoom.height);

            enemy.newPosition = {(SHORT)newPX, (SHORT)newPY};

            map[newPY][newPX] = enemy.valueMap;
            newRoom.enemies[countEnemy] = enemy;
            countEnemy++;
        }
    }
}

void connectRoom(Room (&rooms)[gameData.mapData.maxRooms], int (&map)[height][width])
{
    Room room, nearest;

    for (int i = 0; i < gameData.mapData.maxRooms; i++)
    {
        room = rooms[i];
        nearest = rooms[i];
        for (int j = i + 1; j < gameData.mapData.maxRooms; j++)
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

void set_position_player(Room room, int (&map)[height][width])
{
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

    const int maxRooms = gameData.mapData.maxRooms;
    Room(&listRoom)[maxRooms] = gameData.mapData.rooms;

    int coutRoom = 0;
    int min = 5;
    int max = 20;
    int border = 3;

    clearMap(map);

    for (int i = 0; i < maxRooms; i++)
    {
        Room room;

        room.height = min + (rand() % (max - min + 1));
        room.width = min + (rand() % (max * 2 - min + 1));

        room.y = border + (rand() % (height - room.height - border * 2));
        room.x = border + (rand() % (width - room.width - border * 2));

        if (isColliding(listRoom, coutRoom, room, 1))
        {
            i--;
            continue;
        }

        createRoom(room, map);
        generateEnemy(room, map);
        listRoom[coutRoom++] = room;
    }
    connectRoom(listRoom, map);
    set_position_player(listRoom[0], map);

    return 0;
}
