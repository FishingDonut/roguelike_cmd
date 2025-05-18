
#include "entity/room.h"
#include "game_data.h"
#include "map_construction/create_room.h"

void createRoom(Room newRoom, int (&map)[gameData.height][gameData.width])
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