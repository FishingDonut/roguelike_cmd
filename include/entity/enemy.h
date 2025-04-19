#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct Enemy
{
    COORD position;
    COORD newPosition;
    COORD oldPosition;
    
    int health = 0;
    int damage = 0;
    char skin = 'S';
    int valueMap = 3;

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
};