#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct Player
{
    COORD position;
    int health = 100;
    char skin = '@';
    int valueMap = 2;

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