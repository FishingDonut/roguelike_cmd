#pragma once
#include <iostream>
#include <conio.h>
#include <chrono>
#include <windows.h>

#include "core/colors.h"
#include "tile_map_value.h"
#include "core/map_value_to_char.h"
#include "core/clear_entity.h"
#include "entity/room.h"

using namespace std::chrono;

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
    int valueMap = BOSS;
    int width = 3;
    int height = 3;
    bool alive = true;
    Room room;

    float delay = 0.4f;
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