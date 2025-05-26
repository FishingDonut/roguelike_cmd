#include <iostream>
#include <windows.h>
#include <conio.h>

#include "states/difficulty_state.h"
#include "game_data.h"

extern StateMachine nextState;
extern bool stateChanged;

void difficulty_enter()
{
    HANDLE hConsole = gameData.hConsole;
    system("cls");
    SetConsoleCursorPosition(hConsole, {(SHORT)((width / 2) - 13), (SHORT)((height / 2))});
    cout << "Easy[0] Normal[1] Hard[2]";
    return;
}

void difficulty_update()
{
    if (!_kbhit()) return;

    nextState = STATE_MENU;
    char c = getch();

    switch (c)
    {
    case '0':
        gameData.floorCount = 1;
        gameData.bossFloorCount = 3;
        stateChanged = true;
        break;
    case '1':
        gameData.player.delay += 0.1f;
        gameData.floorCount = 3;
        gameData.bossFloorCount = 7;
        stateChanged = true;
        break;
        case '2':
        gameData.player.delay += 0.15f;
        gameData.floorCount = 5;
        gameData.bossFloorCount = 9;
        stateChanged = true;
        break;
    default:
        gameData.floorCount = 0;
        gameData.bossFloorCount = 0;
        stateChanged = true;
        break;
    }

    stateChanged = false;
    return;
}

void difficulty_exit()
{
    return;
}