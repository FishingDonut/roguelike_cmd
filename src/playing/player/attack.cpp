#include <windows.h>

#include "../stateMachine.h"
#include "../GameData.h"
#include "include/playing/player/attack.h"

void attack()
{
    const int maxRooms = gameData.mapData.maxRooms;
    auto &player = gameData.player;
    auto &attackDistance = gameData.player.attackDistance;
    auto &rooms = gameData.mapData.rooms;
    auto &world = gameData.mapData.world;

    if (gameData.bossFloor)
    {
        auto &boss = gameData.boss;
        for (int i = 0; i < boss.height; i++)
        {
            for (int j = 0; j < boss.width; j++)
            {
                for (int k = 1; k <= attackDistance; k++)
                {
                    int y = player.position.Y + player.dirY * k;
                    int x = player.position.X + player.dirX * k;
                    if (world[y][x] == BOSS)
                    {
                        boss.updateHealth(-player.damage);
                    }
                }
            }
        }
    }

    for (int i = 0; i < maxRooms; i++)
    {
        auto &enemyCount = rooms[i].enemyCount;
        auto &enemies = rooms[i].enemies;

        if (enemyCount <= 0)
        {
            continue;
        }

        for (int j = 0; j < enemyCount; j++)
        {
            auto &enemy = enemies[j];

            for (int k = 1; k <= attackDistance; k++)
            {
                int y = player.position.Y + player.dirY * k;
                int x = player.position.X + player.dirX * k;
                if (enemy.position.Y == y && enemy.position.X == x)
                {
                    enemy.updateHealth(-player.damage);
                }
            }
        }
    }
}
