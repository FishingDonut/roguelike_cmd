#include "iostream"
#include "windows.h"

#include "tile_map_value.h"
#include "tools/debug_matriz.h"
#include "BearLibTerminal.h"

void printMatriz(int matriz[gameData.height][gameData.width])
{
    for (int i = 0; i < gameData.height; i++)
    {
        for (int j = 0; j < gameData.width; j++)
        {
            if (matriz[i][j] != FLOOR)
            {
                terminal_put(j, i, matriz[i][j]);
            }
        }
    }
    return;
}