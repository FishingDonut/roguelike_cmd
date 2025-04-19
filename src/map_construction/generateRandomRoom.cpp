#include "random"
#include "entity/room.h"
#include "map_construction/generateRandomRoom.h"

Room generateRandomRoom(int mapHeight, int mapWidth, int min, int max, int border)
{
    Room room;
    room.height = min + (rand() % (max - min + 1));
    room.width = min + (rand() % (max * 2 - min + 1));
    room.y = border + (rand() % (mapHeight - room.height - border * 2));
    room.x = border + (rand() % (mapWidth - room.width - border * 2));

    return room;
}