#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "core/Colors.h"
#include "TileMapValue.h"

using namespace std;

struct Player
{
    COORD position;
    COORD newPosition;
    COORD oldPosition;

    int health = 100;
    int damage = 1;
    Colors color = COLOR_WHITE;
    char skin = '@';
    int currentObject = FLOOR;
    int previousObject = FLOOR;
    bool isAttackUpdate = false;
    bool isAttackFrame = false;
    const int maxAttackDistance = 20;
    int attackDistance = 3;
    int dirY = -1;
    int dirX = 0;

    void setPosition(int x, int y)
    {
        position.X = x;
        position.Y = y;
    }

    int updateHealth(int health)
    {
        health += health;
        return health;
    }

    void setDirection()
    {
        if (position.Y - oldPosition.Y == 0 && position.X - oldPosition.X == 0)
        {
            return;
        }

        dirY = position.Y - oldPosition.Y;
        dirX = position.X - oldPosition.X;
        return;
    }
};