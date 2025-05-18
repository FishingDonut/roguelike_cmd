#include <iostream>
#include "BearLibTerminal.h"

#include "core/render.h"
#include "core/map_value_to_char.h"
#include "global.h"
#include "game_data.h"
#include "BearLibTerminal.h"

void drawMap(int matriz[height][width])
{
    char c;
    terminal_clear();
    for (short i = 0; i < height; ++i)
    {
        for (short j = 0; j < width; ++j)
        {
            c = mapValueToChar(matriz[i][j]);

            terminal_put(j, i, c);
        }
    }
    return;
}

void drawMargin()
{
    for (short i = 0; i < height; ++i)
    {
        for (short j = 0; j < width; ++j)
        {
            char c = ' ';
            if (j == 0 || j == width - 1)
            {
                c = '|';
                terminal_put(j, i, c);
            }
            else if (i == 0 || i == height - 1)
            {
                c = '-';
                terminal_put(j, i, c);
            }
        }
    }
    return;
}