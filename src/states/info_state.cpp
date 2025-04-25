#include <iostream>
#include <windows.h>
#include <conio.h>

#include "states/info_state.h"
#include "core/mapValueToChar.h"
#include "core/render.h"
#include "stateMachine.h"
#include "GameData.h"

extern StateMachine nextState;
extern bool stateChanged;

void info_enter()
{
    HANDLE hConsole = gameData.hConsole;
    system("cls");
    drawMargin(hConsole);
    
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)2, (SHORT)(height / 2) - 2});
    std::cout << gameData.player.skin << " - Player";
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)2, (SHORT)(height / 2) - 1});
    std::cout << Enemy().skin << " - Enemy";
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)2, (SHORT)(height / 2)});
    std::cout << mapValueToChar(STAIR) << " - Stair";
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)2, (SHORT)(height / 2) + 1});
    std::cout << "As salas são geradas aleatoriamente, suba os andares até que o chefe aparessa, matando ele vc vence o jogo.";
    return;
}

void info_update()
{
    getch();
    nextState = previousState;
    stateChanged = true;
    return;
}

void info_exit()
{
    return;
}