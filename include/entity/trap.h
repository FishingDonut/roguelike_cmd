#pragma once

#include <windows.h>
#include "core/Colors.h"

struct Trap
{
    COORD position;
    int damage = 0;
    int valueMap = TRAP;
    Colors color = COLOR_BLUE;
    char skin = '#';
    bool visible = false;

    void init(int x, int y){
        COORD position = {(SHORT)x, (SHORT)y};
        int damage = 1;
        int valueMap = TRAP;
        Colors color = COLOR_BLUE;
        char skin = '#';
        bool visible = true;
        return;
    }

    void reset(){
        position;
        damage = 0;
        valueMap = FLOOR;
        color = COLOR_WHITE;
        skin = ' ';
        visible = false;
        return;
    }
};
