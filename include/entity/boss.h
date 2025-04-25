#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>

#include "core/Colors.h"
#include "TileMapvalue.h"
#include "core/mapValueToChar.h"
#include "core/clearEntity.h"
#include "entity/room.h"

struct Boss
{
    COORD position;
    COORD newPosition;
    COORD oldPosition;

    Colors color = COLOR_GREEN;
    char skin = 'O';
    int health = 0;
    int damage = 0;
    int currentObject = FLOOR;
    int previousObject = FLOOR;
    int valueMap = ENEMY;
    int width = 3;
    int height = 3;
    bool alive = true;
    Room room;

    void setPosition()
    {
        if (!alive)
        {
            return;
        }
        position.X = newPosition.X;
        position.Y = newPosition.Y;
        return;
    }

    void updateHealth(int newhealth)
    {
        if (!alive)
        {
            return;
        }
        if (health <= 0)
        {
            clearBoss(*this);
            return;
        }
        health += newhealth;
        return;
    }
    int centerY() { return (height / 2) + position.Y; }
    int centerX() { return (width / 2) + position.X; }
};