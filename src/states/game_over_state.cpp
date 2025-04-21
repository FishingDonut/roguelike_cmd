#include <iostream>
#include <conio.h>
#include <windows.h>

#include "global.h"
#include "states/game_over_state.h"
#include "stateMachine.h"
#include "GameData.h"
#include "core/colorChar.h"

extern StateMachine nextState;
extern bool stateChanged;

void game_over_enter()
{
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(width / 2) - 7, (SHORT)(height / 2)});
    std::cout << "[ GAME OVER ]";
    getch();
    return;
}

void game_over_update()
{
    system("cls");
    SetConsoleCursorPosition(gameData.hConsole, gameData.player.position);
    cout << "✞" << colorChar(COLOR_GREEN) << gameData.seed << colorChar(COLOR_RESET) << endl;
    gameData.running = false;
    return;
}

void game_over_exit()
{
    return;
}