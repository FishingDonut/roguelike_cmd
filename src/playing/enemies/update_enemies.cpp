#include "../stateMachine.h"
#include "../GameData.h"
#include "include/playing/enemies/update_enemies.h"
#include "include/playing/enemies/direction_enemy.h"
#include "include/playing/enemies/collision_enemy.h"

void update_enemies()
{
    const int maxRooms = gameData.mapData.maxRooms;
    Room(&rooms)[maxRooms] = gameData.mapData.rooms;
    Player &player = gameData.player;

    for (int j = 0; j < maxRooms; j++)
    {
        Room &room = rooms[j];
        bool isPlayerInRoom = room.isInRoom(player.position);

        for (int i = 0; i < room.enemyCount; i++)
        {
            Enemy &enemy = room.enemies[i];
            direction_enemy(isPlayerInRoom, enemy, room);
            collision_enemy(enemy);
        }
    }
    return;
}