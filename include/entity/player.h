#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct Player
{
    COORD position;

    int health = 100;

    void setPosition(int x, int y)
    {
        position.X = x;
        position.Y = y;
    }

    void setRelativePosition(int x, int y)
    {
        position.X += x;
        position.Y += y;
    }

    int updateHealth(int health)
    {
        health += health;
        return health;
    }
};