#include "entity/room.h"
#include "map_construction/is_colliding.h"

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