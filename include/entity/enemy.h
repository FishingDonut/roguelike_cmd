#pragma once
#include <iostream>
#include <conio.h>
#include <chrono>
#include <windows.h>

#include "core/colors.h"
#include "tile_map_value.h"
#include "core/map_value_to_char.h"
#include "core/clear_entity.h"
#include "entity/enemy.h"

using namespace std::chrono;

struct Enemy
{
    COORD position;
    COORD newPosition;
    COORD oldPosition;

    Colors hideColor = COLOR_GREEN;
    Colors color = hideColor;
    Colors seenColor = hideColor;
    char skin = 'S';
    int health = 2;
    int damage = 2;
    int currentObject = FLOOR;
    int previousObject = FLOOR;
    int valueMap = ENEMY;
    float delay = 0.5f;
    bool alive = true;
    bool IsUpdate = true;
    steady_clock::time_point lastTime = steady_clock::now();

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

        health += newhealth;
        if (health <= 0)
        {
            clearEnemy(*this);
            return;
        }
        return;
    }

    void enemyBlue()
    {
        seenColor = COLOR_CYAN;
        skin = 'S';
        health = 2;
        damage = 1;
        delay = 0.3f;
    }

    void enemyRed()
    {
        seenColor = COLOR_RED;
        skin = 'R';
        health = 4;
        damage = 4;
        delay = 0.8f;
    }

    void enemyYellow()
    {
        seenColor = COLOR_YELLOW;
        skin = 'P';
        health = 2;
        damage = 2;
        delay = 0.5f;
    }

    void levelUp(int floor)
    {
        health += (floor / 2);
        damage += (floor / 2);
        (delay -= 0.03f) > 0.01f ? delay -= 0.02f : 0;
    }
};