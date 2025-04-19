#pragma once

#include "entity/enemy.h"

struct Room
{
    static constexpr int maxEnemy = 4;

    int y, x;
    int height, width;
    bool connect = false;
    int enemyCount = 0;

    Enemy enemies[maxEnemy];

    int centerX() { return x + width / 2; }
    int centerY() { return y + height / 2; }
};