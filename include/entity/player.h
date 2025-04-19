#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct Player
{
    COORD position;
    COORD newPosition;
    COORD oldPosition;
    
    int health = 100;
    char skin = '@';
    int valueMap = 2;
    int currentObject = 0;
    int previousObject = 0;

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