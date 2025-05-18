#pragma once

#include "BearLibTerminal.h"

struct Config
{
    int UP;
    int DOWN;
    int LEFT;
    int RIGHT;

    void setDefaultKeys()
    {
        UP = TK_W;    // 119
        DOWN = TK_S;  // 115
        LEFT = TK_A;  // 97
        RIGHT = TK_D; // 100
    }

    void setVimKeys()
    {
        UP = TK_K;    // 107
        DOWN = TK_J;  // 106
        LEFT = TK_K;  // 104
        RIGHT = TK_L; // 108
    }

    void setArrow()
    {
        UP = TK_UP;
        DOWN = TK_DOWN;
        LEFT = TK_LEFT;
        RIGHT = TK_RIGHT;
    }
};
