#include "core/clearEntity.h"
#include "entity/boss.h"
#include "entity/enemy.h"
#include "GameData.h"

void clearEnemy(Enemy &enemy){
    auto& world = gameData.mapData.world;
    enemy.skin = mapValueToChar(FLOOR);
    enemy.valueMap = FLOOR;
    enemy.alive = false;
    world[enemy.position.Y][enemy.position.X] = enemy.currentObject;
}

void clearBoss(Boss &boss){
    auto& world = gameData.mapData.world;
    boss.skin = mapValueToChar(FLOOR);
    boss.valueMap = FLOOR;
    boss.alive = false;
    world[boss.position.Y][boss.position.X] = boss.currentObject;
}