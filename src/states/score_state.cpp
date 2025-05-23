#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "states/score_state.h"

#include "global.h"
#include "core/render.h"
#include "state_machine.h"
#include "game_data.h"
#include "file_manager/score/score_in.h"

extern StateMachine nextState;
extern bool stateChanged;

void score_enter()
{
    system("cls");
    show_scoreboard();
    getch();
    nextState = STATE_MENU;
    stateChanged = true;
}

void score_update()
{
    return;
}

void score_exit()
{
    return;
}
