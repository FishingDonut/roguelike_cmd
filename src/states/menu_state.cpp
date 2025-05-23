#include <iostream>
#include <windows.h>
#include <conio.h>

#include "core/set_config_key.h"
#include "states/menu_state.h"
#include "state_machine.h"
#include "core/render.h"
#include "menu/render.h"
#include "menu/input.h"
#include "global.h"
#include "game_data.h"

extern StateMachine nextState;
extern bool stateChanged;

void menu_enter()
{
    system("cls");
    drawMargin(gameData.hConsole);

    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(width / 2) - 22, (SHORT)(height / 2) - 2});
    std::cout << "[ APERTE WASD, Setas ou HJKL PARA COMEÇAR ]";
    setConfigKey();

    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(width / 2) - 3, (SHORT)(height / 2)});
    std::cout << "START";
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(width / 2) - 3, (SHORT)(height / 2) + 1});
    std::cout << "INFO";
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(width / 2) - 6, (SHORT)(height / 2) + 2});
    std::cout << "DIFFICULTY";
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(width / 2) - 3, (SHORT)(height / 2) + 3});
    std::cout << "SCORE";
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(width / 2) - 3, (SHORT)(height / 2) + 4});
    std::cout << "EXIT";
}

void menu_update()
{
    Menu::handle_input();
    Menu::render_frame();
}

void menu_exit()
{
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(width / 2) - 22, (SHORT)(height / 2) - 2});
    std::cout << "                                            ";

    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(width / 2) - 5, (SHORT)(height / 2)});
    std::cout << "         ";
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(width / 2) - 5, (SHORT)(height / 2) + 1});
    std::cout << "         ";
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(width / 2) - 6, (SHORT)(height / 2) + 2});
    std::cout << "          ";
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(width / 2) - 5, (SHORT)(height / 2) + 3});
    std::cout << "         ";
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(width / 2) - 5, (SHORT)(height / 2) + 4});
    std::cout << "         ";

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