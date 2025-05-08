#include "../state_machine.h"
#include "../game_data.h"
#include "entity/boss.h"
#include "include/playing/boss/collision_boss.h"

void collision_boss()
{
    if (!gameData.bossFloor)
        return;

    Player &player = gameData.player;
    Boss &boss = gameData.boss;
    auto &oldPosition = boss.oldPosition;
    auto &newPosition = boss.newPosition;
    auto &map = gameData.mapData.world;

    int &previousObject = boss.previousObject;
    int &currentObject = boss.currentObject;

    int initY = newPosition.Y - (boss.height / 2);
    int initX = newPosition.X - (boss.width / 2);

    for (int i = 0; i < boss.height; i++)
    {
        for (int j = 0; j < boss.width; j++)
        {
            int y = initY + i;
            int x = initX + j;

            int tile = map[y][x];

            if (tile == WALL)
            {
                newPosition = oldPosition; 
                return;
            }
            else if (tile == PLAYER)
            {
                newPosition = oldPosition; 
                player.updateHealth(-boss.damage);
                return;
            }
        }
    }

    previousObject = currentObject;
    currentObject = map[newPosition.Y][newPosition.X];

    boss.setPosition();

    int oldInitY = oldPosition.Y - (boss.height / 2);
    int oldInitX = oldPosition.X - (boss.width / 2);
    for (int i = 0; i < boss.height; i++)
    {
        for (int j = 0; j < boss.width; j++)
        {
            int y = oldInitY + i;
            int x = oldInitX + j;
            map[y][x] = FLOOR;
        }
    }

    for (int i = 0; i < boss.height; i++)
    {
        for (int j = 0; j < boss.width; j++)
        {
            int y = initY + i;
            int x = initX + j;
            map[y][x] = boss.valueMap;
        }
    }
}
