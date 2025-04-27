#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>

#include "core/Colors.h"
#include "TileMapvalue.h"
#include "core/mapValueToChar.h"
#include "core/clearEntity.h"
#include "entity/enemy.h"

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
    bool alive = true;

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