#include "global.h"
#include "GameData.h"
#include "entity/room.h"
#include "entity/player.h"
#include "map_construction/set_position_player.h"

void set_position_player(Room room, int (&map)[height][width])
{
    Player &player = gameData.player;
    player.setPosition(room.centerX(), room.centerY());
    player.newPosition = player.position;
    map[room.centerY()][room.centerX()] = PLAYER;

    return;
}