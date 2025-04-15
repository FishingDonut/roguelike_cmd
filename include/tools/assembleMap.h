#include <iostream>
#include <windows.h>
#include "../global.h"

void assembleMap(HANDLE &hConsole, int matriz[height][width])
{
    for (short i = 0; i < height; ++i)
    {
        for (short j = 0; j < width; ++j)
        {
            matriz[i][j] = 0;

            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                SetConsoleCursorPosition(hConsole, {j, i});
                std::cout << ".";
                matriz[i][j] = 1;
            }
        }
    }
}