#include <iostream>
#include <conio.h>
#include <windows.h>

#include "global.h"
#include "states/paused_state.h"
#include "state_machine.h"
#include "game_data.h"
#include "BearLibTerminal.h"

extern StateMachine nextState;
extern bool stateChanged;

void paused_enter(){
    terminal_clear();
};

void paused_update(){
    terminal_printf((width / 2) - 6, (height / 2), "===PAUSED===");
    terminal_read();

    nextState = previousState;
    stateChanged = true;
};

void paused_exit(){
    terminal_printf((width / 2) - 6, (height / 2), "===SAIDA===");
};