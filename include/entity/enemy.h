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
    
    Colors color = COLOR_GREEN;
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
        if(!alive){
            return;
        }
        position.X = newPosition.X;
        position.Y = newPosition.Y;
        return;
    }

    void updateHealth(int newhealth)
    {
        if(!alive){
            return;
        }
        if(health <= 0){
            clearEnemy(*this);
            return;
        }
        health += newhealth;
        return;
    }
};