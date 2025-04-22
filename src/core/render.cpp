#include <iostream>
#include <windows.h>
#include "core/render.h"
#include "core/mapValueToChar.h"
#include "global.h"
#include "GameData.h"

void drawMap(HANDLE &hConsole, int matriz[height][width])
{
    auto& explored = gameData.mapData.explored; 
    char c;
    system("cls");
    for (short i = 0; i < height; ++i)
    {
        for (short j = 0; j < width; ++j)
        {
            if(explored[i][j] == 1){
                continue;
            }

            SetConsoleCursorPosition(hConsole, {j, i});

            c = mapValueToChar(matriz[i][j]);

            std::cout << c;
        }
    }
    return;
}

void drawMargin(HANDLE &hConsole)
{
    for (short i = 0; i < height; ++i)
    {
        for (short j = 0; j < width; ++j)
        {
            SetConsoleCursorPosition(hConsole, {j, i});

            char c = ' ';
            if (j == 0 || j == width - 1)
            {
                c = '|';
                cout << c;
            }
            else if (i == 0 || i == height - 1)
            {
                c = '-';
                cout << c;
            }
        }
    }
    return;
}