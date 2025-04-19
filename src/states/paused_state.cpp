#include <iostream>
#include <conio.h>
#include <windows.h>

#include "global.h"
#include "states/paused_state.h"
#include "stateMachine.h"
#include "GameData.h"

extern StateMachine nextState;
extern bool stateChanged;

void paused_enter(){
    system("cls");
};

void paused_update(){
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(width / 2) - 6,(SHORT)(height / 2)});
    std::cout << "===PAUSED===";
    getch();

    nextState = previousState;
    stateChanged = true;
};

void paused_exit(){
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(width / 2) - 6,(SHORT)(height / 2)});
    std::cout << "===SAIDA===";
};