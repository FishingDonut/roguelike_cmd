#include "iostream"
#include "windows.h"
#include "global.h"
#include "tile_map_value.h"
#include "tools/debug_matriz.h"
#include "BearLibTerminal.h"

void printMatriz(int matriz[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (matriz[i][j] != FLOOR)
            {
                terminal_put(j, i, matriz[i][j]);
            }
        }
    }
    return;
}