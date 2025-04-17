#include <iostream>
#include <conio.h>
#include <windows.h>

#include "global.h"
#include "states/game_over_state.h"
#include "stateMachine.h"
#include "GameData.h"

extern StateMachine nextState;
extern bool stateChanged;

void game_over_enter()
{
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(width / 2) - 14, (SHORT)(height / 2)});
    std::cout << "[ GAME OVER ]";
    getch();
}

void game_over_update()
{
    system("cls");
    SetConsoleCursorPosition(gameData.hConsole, gameData.player.position);
    cout << "✞" << endl;
    gameData.running = false;
}

void game_over_exit()
{
    return;
}