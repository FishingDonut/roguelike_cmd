// C++
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <locale.h>

// Internos do projeto
#include "global.h"
#include "game_data.h"
#include "entity/player.h"
#include "tools/get_char_at_position.h"
#include "tools/debug_matriz.h"
#include "core/render.h"
#include "state_machine.h"
#include "states/playing_state.h"
#include "playing/input.h"
#include "playing/render.h"
#include "playing/update_logic.h"

void playing_enter()
{
    drawMap(gameData.mapData.world);
    drawMargin();
    return;
}

void playing_update()
{
    // controle de key
    Playing::handle_input();
    // atualiza matriz
    Playing::update_logic();
    // renderiza
    Playing::render_frame();
    return;
}

void playing_exit()
{
    return;
}