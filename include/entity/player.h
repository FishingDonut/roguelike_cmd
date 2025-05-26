#pragma once
#include <iostream>
#include <conio.h>
#include <chrono> 
#include <windows.h>
#include "state_machine.h"
#include "core/colors.h"
#include "tile_map_value.h"
#include "entity/item.h"

using namespace std;
using namespace std::chrono;

struct Player
{
    COORD position;
    COORD newPosition;
    COORD oldPosition;

    Item inventory = Item();
    std::string name = "";
    Colors color = COLOR_YELLOW;
    char skin = '@';
    bool isAttackUpdate = false;
    bool isAttackFrame = false;
    bool IsUpdate = true;
    bool moveOn = false;
    const int maxAttackDistance = 20;
    int healthMax = 25;
    int health = healthMax;
    int damage = 1;
    int kills = 0;
    int gold = 1;
    int xp = 0;
    int nextXpLevel = 12;
    int level = 1;
    int currentObject = FLOOR;
    int previousObject = FLOOR;
    int attackDistance = 3;
    int dirY = -1;
    int dirX = 0;
    float delay = 0.12f;
    steady_clock::time_point lastTime = steady_clock::now();

    void setPosition(int x, int y)
    {
        position.X = x;
        position.Y = y;
    }

    void updateHealth(int newHealth)
    {
        if (health + newHealth < healthMax){
            health += newHealth;
        }

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