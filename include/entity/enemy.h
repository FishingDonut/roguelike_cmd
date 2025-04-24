#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>

#include "core/Colors.h"
#include "TileMapvalue.h"

using namespace std;

struct Enemy
{
    COORD position;
    COORD newPosition;
    COORD oldPosition;
    
    Colors color = COLOR_GREEN;
    char skin = 'S';
    int health = 0;
    int damage = 0;
    int valueMap = 3;
    int currentObject = FLOOR;
    int previousObject = FLOOR;

    void setPosition()
    {
        position.X = newPosition.X;
        position.Y = newPosition.Y;
    }

    int updateHealth(int health)
    {
        health += health;
        return health;
    }
};