#pragma once

#include "entity/enemy.h"

struct Room
{
    static constexpr int maxEnemy = 7;

    int y, x;
    int height, width;
    bool connect = false;
    bool exploredRoom = false;
    int enemyCount = 0;

    Enemy enemies[maxEnemy];

    int centerX() { return x + width / 2; }
    int centerY() { return y + height / 2; }

    bool isInRoom(COORD position)
    {
        if (x - 1 < position.X &&
            x + width > position.X &&
            y - 1 < position.Y &&
            y + height > position.Y)
        {
            exploredRoom = true; 
            return true;
        }
        return false;
    }
};