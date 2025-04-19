#include <iostream>
#include <windows.h>
#include <conio.h>

#include "global.h"
#include "states/menu_state.h"
#include "stateMachine.h"
#include "GameData.h"

extern StateMachine nextState;
extern bool stateChanged;

void menu_enter() {
    system("cls");
}

void menu_update() {
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(width / 2) - 11,(SHORT)(height / 2)});
    std::cout << "~~APERTE PARA COMEÇAR~~";
    getch();

    nextState = STATE_MAP_CONSTRUCTION;
    stateChanged = true;
}

void menu_exit() {
    std::cout << "Saindo do MENU\n";
}