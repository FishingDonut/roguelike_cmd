#include "BearLibTerminal.h"

#include "states/credits_state.h"
#include "core/render.h"
#include "game_data.h"
#include "BearLibTerminal.h"

extern StateMachine nextState;
extern bool stateChanged;

void credits_enter()
{
    terminal_clear();
    drawMargin();

    terminal_printf((width / 2) - 11, (height / 2) - 2, "Parabens voce ganhou!");
    terminal_printf((width / 2) - 5, (height / 2) - 1, "score: %d", gameData.score);
    terminal_printf((width / 2) - 5, (height / 2), "kills: %d", gameData.status.kills);

    terminal_read();
    gameData.running = false;
    return;
}

void credits_update()
{
    return;
}

void credits_exit()
{
    return;
}