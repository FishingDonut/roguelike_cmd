#include "../state_machine.h"
#include "../game_data.h"
#include "include/playing/enemies/update_enemies.h"
#include "include/playing/enemies/direction_enemy.h"
#include "include/playing/enemies/collision_enemy.h"

void update_enemies()
{
    const int MAX_ROOMS = gameData.mapData.MAX_ROOMS;
    Room(&rooms)[MAX_ROOMS] = gameData.mapData.rooms;
    Player &player = gameData.player;

    for (int j = 0; j < MAX_ROOMS; j++)
    {
        Room &room = rooms[j];
        bool isPlayerInRoom = room.isInRoom(player.position);

        for (int i = 0; i < room.enemyCount; i++)
        {
            Enemy &enemy = room.enemies[i];

            if(!enemy.alive){
                continue;
            }
            
            direction_enemy(isPlayerInRoom, enemy, room);
            collision_enemy(enemy);
        }
    }
    return;
}