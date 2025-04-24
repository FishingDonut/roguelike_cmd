#pragma once

struct Config
{
    int UP;
    int DOWN;
    int LEFT;
    int RIGHT;

    void setDefaultKeys()
    {
        UP = 'w';    // 119
        DOWN = 's';  // 115
        LEFT = 'a';  // 97
        RIGHT = 'd'; // 100
    }

    void setVimKeys()
    {
        UP = 'k';    // 107
        DOWN = 'j';  // 106
        LEFT = 'h';  // 104
        RIGHT = 'l'; // 108
    }
};
