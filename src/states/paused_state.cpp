#include <iostream>
#include <conio.h>
#include <windows.h>

#include "global.h"
#include "states/paused_state.h"
#include "state_machine.h"
#include "game_data.h"

extern StateMachine nextState;
extern bool stateChanged;

void paused_enter(){
    system("cls");
};

void paused_update(){
    SetConsoleCursorPosition(game_data.hConsole, {(SHORT)(width / 2) - 6,(SHORT)(height / 2)});
    std::cout << "===PAUSED===";
    getch();

    nextState = previousState;
    stateChanged = true;
};

void paused_exit(){
    SetConsoleCursorPosition(game_data.hConsole, {(SHORT)(width / 2) - 6,(SHORT)(height / 2)});
    std::cout << "===SAIDA===";
};