#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include "global.h"
#include "tile_map_value.h"
#include "core/init.h"
#include "core/render.h"
#include "game_data.h"
#include "state_machine.h"
#include "states/menu_state.h"
#include "BearLibTerminal.h"

void assembleMap(HANDLE &hConsole, int (&matriz)[height][width])
{
    for (short i = 0; i < height; ++i)
    {
        for (short j = 0; j < width; ++j)
        {
            matriz[i][j] = FLOOR;

            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                matriz[i][j] = WALL;
            }
        }
    }
}

void init(HANDLE &hConsole, int (&matriz)[height][width])
{
    gameData.seed = time(0);
    srand(gameData.seed);

    terminal_clear();
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE; // Oculta o cursor
    SetConsoleCursorInfo(hConsole, &cursorInfo);

    menu_enter();
    // assembleMap(hConsole, matriz);
    return;
}