#include "../stateMachine.h"
#include "../GameData.h"
#include "entity/boss.h"
#include "include/playing/boss/collision_boss.h"

void collision_boss()
{
    if (!gameData.bossFloor)
        return;

    Player &player = gameData.player;
    Boss &boss = gameData.boss;
    auto &oldPosition = boss.oldPosition;
    auto &position = boss.position;
    auto &newPosition = boss.newPosition;
    auto &map = gameData.mapData.world;

    int &previousObject = boss.previousObject;
    int &currentObject = boss.currentObject;

    int initY = newPosition.Y - (boss.height / 2);
    int initX = newPosition.X - (boss.width / 2);

    // Verificar se TODA a área 3x3 do boss está livre
    for (int i = 0; i < boss.height; i++)
    {
        for (int j = 0; j < boss.width; j++)
        {
            int y = initY + i;
            int x = initX + j;

            int tile = map[y][x];

            if (tile == WALL)
            {
                newPosition = oldPosition; // Cancela o movimento
                return;
            }
            else if (tile == PLAYER)
            {
                newPosition = oldPosition; // Cancela o movimento
                player.updateHealth(-boss.damage);
                return;
            }
        }
    }

    // Se passou pelo loop, é seguro mover
    previousObject = currentObject;
    currentObject = map[newPosition.Y][newPosition.X];

    boss.setPosition();

    // Limpa área anterior
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

    // Preenche nova posição com valor do boss
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
