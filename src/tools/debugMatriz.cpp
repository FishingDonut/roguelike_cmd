#include "iostream"
#include "windows.h"
#include "global.h"
#include "TileMapValue.h"
#include "tools/debugMatriz.h"

void printMatriz(HANDLE hConsole, int matriz[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            SetConsoleCursorPosition(hConsole, {(SHORT)j, (SHORT)i});
            if (matriz[i][j] != FLOOR)
            {
                std::cout << matriz[i][j];
            }
            // } else {
            //     std::cout << " ";
            // }
        }
    }
    return;
}