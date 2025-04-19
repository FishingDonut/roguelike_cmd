#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include "../global.h"
#include "core/init.h"
#include "core/render.h"
#include "GameData.h"

void assembleMap(HANDLE &hConsole, int (&matriz)[height][width])
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

void init(HANDLE &hConsole, int (&matriz)[height][width])
{
    gameData.seed = time(0);
    srand(gameData.seed);
    
    system("cls");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE; // Oculta o cursor
    SetConsoleCursorInfo(hConsole, &cursorInfo);
    
    gameData.player.setPosition(5, 5);
    gameData.player.newPosition = {5, 5};

    gameData.player.currentObject = gameData.mapData.mapAll[gameData.player.position.Y][gameData.player.position.X];
    gameData.player.previousObject = gameData.player.currentObject;
    gameData.mapData.mapAll[gameData.player.position.Y][gameData.player.position.X] = gameData.player.valueMap;


    // getch();
    assembleMap(hConsole, matriz);
    // getch();
    drawMap(hConsole, matriz);
    // getch();
}