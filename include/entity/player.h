#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "stateMachine.h"
#include "core/Colors.h"
#include "TileMapValue.h"

using namespace std;

struct Player
{
    COORD position;
    COORD newPosition;
    COORD oldPosition;

    int health = 25;
    int damage = 1;
    int kills = 0;
    int gold = 1;
    int xp = 0;
    Colors color = COLOR_YELLOW;
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

    void updateHealth(int newHealth)
    {
        health += newHealth;
        if (health <= 0)
        {
            nextState = STATE_GAME_OVER;
            stateChanged = true;
        }
        return;
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