#include <random>
#include "map_construction/random_enemy_type.h"
#include "entity/typeEnemy.h"
#include "entity/enemy.h"

const typeEnemy type_enemy[] = {RED, YELLOW, BLUE};

void randomEnemyType(Enemy &enemy)
{
    typeEnemy type;
    int index = type_enemy[(rand() % (sizeof(type_enemy) / sizeof(type_enemy[0])))];
    type = type_enemy[index];

    switch (type)
    {
    case RED:
        enemy.enemyRed();
        break;
    case BLUE:
        enemy.enemyBlue();
        break;
    case YELLOW:
        enemy.enemyYellow();
        break;
    default:
        break;
    }

    return;
}