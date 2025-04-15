#include <iostream>
#include <windows.h>
#include "../global.h"

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
                std::cout << "-";
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