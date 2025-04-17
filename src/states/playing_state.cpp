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
#include "core/update.h"
#include "core/render.h"
#include "stateMachine.h"
#include "states/playing_state.h"
#include "playing/input.h"
#include "playing/render.h"
#include "playing/update_logic.h"

void playing_enter()
{
    drawMap(gameData.hConsole, gameData.mapData.mapAll);
}

void playing_update()
{
    // controle de key
    handle_input();
    // atualiza matriz
    update_logic();
    // renderiza
    render_frame();
    return;
}

void playing_exit()
{
    return;
}