#pragma once

struct Room
{
    int y, x;
    int height, width;

    bool connect = false;

    int centerX() { return x + width / 2; }
    int centerY() { return y + height / 2; }
};