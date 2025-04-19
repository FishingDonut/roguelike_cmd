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
    
    char skin = 'S';
    int health = 0;
    int damage = 0;
    int valueMap = 3;
    int currentObject = 0;
    int previousObject = 0;

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