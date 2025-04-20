#include <iostream>
#include <windows.h>
#include <conio.h>

#include "global.h"
#include "states/menu_state.h"
#include "stateMachine.h"
#include "GameData.h"
#include "menu/input.h"
#include "menu/render.h"
#include "core/render.h"

extern StateMachine nextState;
extern bool stateChanged;

void menu_enter()
{
    system("cls");

    drawMargin(gameData.hConsole);
    
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(width / 2) - 11, (SHORT)(height / 2) - 2});
    std::cout << "[ APERTE PARA COMEÇAR ]";

    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(width / 2) - 3, (SHORT)(height / 2)});
    std::cout << "START";
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(width / 2) - 3, (SHORT)(height / 2) + 1});
    std::cout << "INFO";
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(width / 2) - 3, (SHORT)(height / 2) + 2});
    std::cout << "EXIT";
}

void menu_update()
{
    Menu::handle_input();
    Menu::render_frame();
}

void menu_exit()
{
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(width / 2) - 11, (SHORT)(height / 2) - 2});
    std::cout << "                       ";

    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(width / 2) - 3, (SHORT)(height / 2)});
    std::cout << "     ";
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(width / 2) - 3, (SHORT)(height / 2) + 1});
    std::cout << "    ";
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(width / 2) - 3, (SHORT)(height / 2) + 2});
    std::cout << "    ";

    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(width / 2) - 1, (SHORT)(height / 2)});
    std::cout << "[3]";
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(width / 2) - 1, (SHORT)(height / 2)});
    Sleep(100);
    std::cout << "[2]";
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(width / 2) - 1, (SHORT)(height / 2)});
    Sleep(100);
    std::cout << "[1]";
    Sleep(100);
}