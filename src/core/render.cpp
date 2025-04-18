#include <iostream>
#include <windows.h>
#include "core/render.h"
#include "core/mapValueToChar.h"
#include "global.h"
#include "GameData.h"

void drawMap(HANDLE &hConsole, int matriz[height][width])
{
    char c;
    system("cls");
    for (short i = 0; i < height; ++i)
    {
        for (short j = 0; j < width; ++j)
        {
            SetConsoleCursorPosition(hConsole, {j, i});

            c = mapValueToChar(matriz[i][j]);

            if (matriz[i][j] == 1)
            {
                if (i == 0 || i == height - 1)
                {
                    c = '-';
                }
                if (j == 0 || j == width - 1)
                {
                    c = '|';
                }
            }
            std::cout << c;
        }
    }
    return;
}