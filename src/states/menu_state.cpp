#include <iostream>

#include "core/set_config_key.h"
#include "states/menu_state.h"
#include "state_machine.h"
#include "core/render.h"
#include "menu/render.h"
#include "menu/input.h"

#include "game_data.h"
#include "BearLibTerminal.h"

extern StateMachine nextState;
extern bool stateChanged;

void menu_enter()
{
    terminal_clear();
    drawMargin();
    terminal_print(gameData.width / 2 - 22, gameData.height / 2 - 2, "[ APERTE WASD, Setas ou HJKL PARA COMEÇAR ]");
    setConfigKey();
    terminal_print(gameData.width / 2 - 3, gameData.height / 2, "START");
    terminal_print(gameData.width / 2 - 3, gameData.height / 2 + 1, "INFO");
    terminal_print(gameData.width / 2 - 3, gameData.height / 2 + 2, "EXIT");
    terminal_refresh();
}

void menu_update()
{
    Menu::handle_input();
    Menu::render_frame();
}

void menu_exit()
{
    terminal_print(gameData.width / 2 - 22, gameData.height / 2 - 2, "                                            ");
    terminal_print(gameData.width / 2 - 5, gameData.height / 2, "         "); 
    terminal_print(gameData.width / 2 - 5, gameData.height / 2 + 1, "         ");
    terminal_print(gameData.width / 2 - 5, gameData.height / 2 + 2, "         ");
    terminal_print(gameData.width / 2 - 1, gameData.height / 2, "[3]");
    terminal_refresh();
    terminal_delay(100);
    terminal_print(gameData.width / 2 - 1, gameData.height / 2, "[2]");
    terminal_refresh();
    terminal_delay(100);
    terminal_print(gameData.width / 2 - 1, gameData.height / 2, "[1]");
    terminal_refresh();
    terminal_delay(100);
}