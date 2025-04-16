#include <iostream>
#include <windows.h>
#include "../global.h"
#include "core/init.h"

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

void drawnMap(HANDLE &hConsole, int matriz[height][width])
{
    system("cls");
    for (short i = 0; i < height; ++i)
    {
        for (short j = 0; j < width; ++j)
        {
            SetConsoleCursorPosition(hConsole, {j, i});
            switch (matriz[i][j])
            {
            case 0:
                // cout << " ";
                break;
            case 1:
                if (i == 0 || i == height -1){
                    std::cout << "-";
                } else {
                    std::cout << "|";
                }
                break;
            case 2:
                std::cout << "@";
                break;
            default:
                std::cout << "?";
                break;
            }
        }
    }
}

void init(HANDLE &hConsole, int matriz[height][width]){
    assembleMap(hConsole, matriz);
    drawnMap(hConsole, matriz);
}