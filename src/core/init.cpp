#include <iostream>
#include <windows.h>
#include "../global.h"
#include "core/init.h"
#include "core/render.h"
#include "GameData.h"

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

void init(HANDLE &hConsole, int matriz[height][width]){
    system("cls");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    gameData.mapData.nearbyObject = gameData.mapData.mapAll[gameData.player.position.X][gameData.player.position.Y];
    gameData.mapData.previousObject = gameData.mapData.nearbyObject;
    gameData.mapData.mapAll[gameData.player.position.X][gameData.player.position.Y] = gameData.player.valueMap;

    assembleMap(hConsole, matriz);
    drawMap(hConsole, matriz);
}