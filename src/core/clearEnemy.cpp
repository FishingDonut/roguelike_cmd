#include "core/clearEnemy.h"
#include "entity/enemy.h"
#include "GameData.h"

void clearEnemy(Enemy &enemy){
    auto& world = gameData.mapData.world;
    enemy.skin = mapValueToChar(FLOOR);
    enemy.valueMap = FLOOR;
    enemy.alive = false;
    world[enemy.position.Y][enemy.position.X] = enemy.currentObject;
}