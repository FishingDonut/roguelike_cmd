#include <iostream>
#include <windows.h>
#include <conio.h>

#include "states/credits_state.h"
#include "core/mapValueToChar.h"
#include "core/render.h"
#include "stateMachine.h"
#include "GameData.h"

extern StateMachine nextState;
extern bool stateChanged;

void credits_enter()
{
    HANDLE hConsole = gameData.hConsole;
    system("cls");
    drawMargin(hConsole);

    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)((width / 2) - 11), (SHORT)(height / 2) - 2});
    std::cout << "Parabens voce ganhou!";
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)((width / 2) - 5), (SHORT)(height / 2) - 1});
    std::cout << "score: " << gameData.score;
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)((width / 2) - 5), (SHORT)(height / 2)});
    std::cout << "kills: " << gameData.status.kills;
    getch();
    gameData.running = false;
    return;
}

void credits_update()
{
    return;
}

void credits_exit()
{
    return;
}