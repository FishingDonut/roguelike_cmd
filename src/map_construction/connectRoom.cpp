#include "GameData.h"
#include "global.h"
#include "map_construction/connectRoom.h"

void connectRoom(Room (&rooms)[gameData.mapData.MAX_ROOMS], int (&map)[height][width])
{
    Room room, nearest;

    for (int i = 0; i < gameData.mapData.MAX_ROOMS; i++)
    {
        room = rooms[i];
        nearest = rooms[i];
        for (int j = i + 1; j < gameData.mapData.MAX_ROOMS; j++)
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
                if (map[ay][x] == WALL)
                {
                    map[ay][x] = FLOOR;
                }
            }
            for (int y = std::min(ay, by); y <= std::max(ay, by); y++)
            {
                if (map[y][bx] == WALL)
                {
                    map[y][bx] = FLOOR;
                }
            }
        }
        else
        {
            for (int x = std::min(ax, bx); x <= std::max(ax, bx); x++)
            {
                if (map[by][x] == WALL)
                {
                    map[by][x] = FLOOR;
                }
            }
            for (int y = std::min(ay, by); y <= std::max(ay, by); y++)
            {
                if (map[y][ax] == WALL)
                {
                    map[y][ax] = FLOOR;
                }
            }
        }
    }
    return;
}