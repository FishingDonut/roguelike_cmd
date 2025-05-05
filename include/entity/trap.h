#pragma once

#include <windows.h>
#include "core/colors.h"

struct Trap
{
    COORD position = {0, 0};
    int damage = 0;
    int valueMap = TRAP;
    Colors color = COLOR_BLUE;
    char hidleSkin = ' ';
    char visibleSkin = '#';
    char currentSkin = hidleSkin;
    bool visible = false;
    bool active = false;

    void init(int x, int y){
        position = {(SHORT)x, (SHORT)y};
        damage = 1;
        valueMap = TRAP;
        color = COLOR_BLUE;
        currentSkin = visibleSkin;
        visible = false;
        active = true;
        return;
    }

    void reset(){
        position = {0, 0};
        damage = 0;
        valueMap = FLOOR;
        color = COLOR_WHITE;
        currentSkin = ' ';
        visible = false;
        active = false;
        return;
    }
};
