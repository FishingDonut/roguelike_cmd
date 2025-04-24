// C++
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <locale.h>

// Internos do projeto
#include "global.h"
#include "GameData.h"
#include "entity/player.h"
#include "tools/getCharAtPosition.h"
#include "tools/debugMatriz.h"
#include "core/render.h"
#include "stateMachine.h"
#include "states/playing_state.h"
#include "playing/input.h"
#include "playing/render.h"
#include "playing/update_logic.h"

void playing_enter()
{
    drawMap(gameData.hConsole, gameData.mapData.world);
    drawMargin(gameData.hConsole);
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