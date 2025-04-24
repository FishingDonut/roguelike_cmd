#include "global.h"
#include "entity/room.h"
#include "map_construction/createRoom.h"

void createRoom(Room newRoom, int (&map)[height][width])
{
    for (int i = newRoom.y; i < newRoom.y + newRoom.height; i++)
    {
        for (int j = newRoom.x; j < newRoom.x + newRoom.width; j++)
        {
            map[i][j] = FLOOR;
        }
    }
    return;
}