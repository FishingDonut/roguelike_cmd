#include <random>
#include "core/clearEntity.h"
#include "entity/boss.h"
#include "entity/enemy.h"
#include "GameData.h"

void clearEnemy(Enemy &enemy){
    gameData.score += 1 + (rand() % (20 - 1 + 1));
    auto& player = gameData.player;
    player.gold += 1 + (rand() % (7 - 1 + 1));
    player.xp += 2 + (rand() % (8 - 2 + 1));
    player.kills++;
    auto& world = gameData.mapData.world;
    enemy.skin = mapValueToChar(FLOOR);
    enemy.valueMap = FLOOR;
    enemy.alive = false;
    world[enemy.position.Y][enemy.position.X] = enemy.currentObject;
}

void clearBoss(Boss &boss){
    gameData.score += 10;
    auto& world = gameData.mapData.world;
    boss.skin = mapValueToChar(FLOOR);
    boss.valueMap = FLOOR;
    boss.alive = false;
    int initY = boss.position.Y - (boss.height / 2);
    int initX = boss.position.X - (boss.width / 2);

    for (int i = 0; i < boss.height; i++)
    {
        for (int j = 0; j < boss.width; j++)
        {
            int y = initY + i;
            int x = initX + j;

            world[y][x] = FLOOR;
        }
    }
    nextState = STATE_CREDITS;
    stateChanged = true;
}