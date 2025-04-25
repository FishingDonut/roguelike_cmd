#include "global.h"
#include "GameData.h"
#include "entity/room.h"
#include "map_construction/set_position_stair.h"

void set_position_stair(Room room, int (&map)[height][width])
{
    map[room.centerY()][room.centerX()] = STAIR;
    return;
}