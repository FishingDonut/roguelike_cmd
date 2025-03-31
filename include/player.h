#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct Items
{
    enum TypeofItems
    {
        potion = 2,
        armor,
        weapon,
        key,
    };
    TypeofItems type;
    short int quantity;
    float durability;
    enum effects
    {
        strengh,
        luck,
    };
};

struct Inventory
{
    Items items[10];
    short int size;
};

struct Player
{
    COORD position;
    Inventory inventory;

    int health = 100;

    COORD getPosition()
    {
        return position;
    }

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

char getCharAtPosition(HANDLE hConsole, COORD position){
    char c;
    DWORD read;
    ReadConsoleOutputCharacterA(hConsole, &c, 1, position, &read);
    return c;
}