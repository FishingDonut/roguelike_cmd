// libs
#include <conio.h>
#include <locale.h>
#include <iostream>
#include <windows.h>
// person libs
#include "global.h"
#include "state_machine.h"
#include "./include/core/init.h"
#include "./include/entity/player.h"
#include "game_data.h"
// states
#include "./include/states/menu_state.h"
#include "./include/states/info_state.h"
#include "./include/states/map_construction_state.h"
#include "./include/states/playing_state.h"
#include "./include/states/paused_state.h"
#include "./include/states/game_over_state.h"
#include "./include/states/credits_state.h"
#include "./include/states/difficulty_state.h"
#include "./include/states/score_state.h"
#include "./include/states/level_up_state.h"

using namespace std;

GameData gameData;

StateMachine currentState = STATE_MENU;
StateMachine nextState = currentState;
StateMachine previousState = currentState;

bool stateChanged = false;

void switchState()
{
    if (!stateChanged && currentState == nextState)
    {
        return;
    }

    // exit state
    switch (currentState)
    {
    case STATE_MENU:
        menu_exit();
        break;
    case STATE_INFO:
        info_exit();
        break;
    case STATE_DIFFICULTY:
        difficulty_exit();
        break;
    case STATE_SCORE:
        score_exit();
        break;
    case STATE_MAP_CONSTRUCTION:
        map_construction_exit();
        break;
    case STATE_LEVEL_UP:
        level_up_exit();
        break;
    case STATE_PLAYING:
        playing_exit();
        break;
    case STATE_PAUSED:
        paused_exit();
        break;
    case STATE_GAME_OVER:
        game_over_exit();
        break;
    case STATE_CREDITS:
        credits_exit();
        break;
    }

    previousState = currentState;
    currentState = nextState;

    // enter state
    switch (currentState)
    {
    case STATE_MENU:
        menu_enter();
        break;
    case STATE_INFO:
        info_enter();
        break;
    case STATE_DIFFICULTY:
        difficulty_enter();
        break;
    case STATE_SCORE:
        score_enter();
        break;
    case STATE_MAP_CONSTRUCTION:
        map_construction_enter();
        break;
    case STATE_LEVEL_UP:
        level_up_enter();
        break;
    case STATE_PLAYING:
        playing_enter();
        break;
    case STATE_PAUSED:
        paused_enter();
        break;
    case STATE_GAME_OVER:
        game_over_enter();
        break;
    case STATE_CREDITS:
        credits_enter();
        break;
    }

    stateChanged = false;

    return;
}

void loopGame()
{
    while (gameData.running)
    {
        switchState();

        switch (currentState)
        {
        case STATE_MENU:
            menu_update();
            break;
        case STATE_INFO:
            info_update();
            break;
        case STATE_DIFFICULTY:
            difficulty_update();
            break;
        case STATE_SCORE:
            score_update();
            break;
        case STATE_MAP_CONSTRUCTION:
            map_construction_update();
            break;
        case STATE_LEVEL_UP:
            level_up_update();
            break;
        case STATE_PLAYING:
            playing_update();
            break;
        case STATE_PAUSED:
            paused_update();
            break;
        case STATE_GAME_OVER:
            game_over_update();
            break;
        case STATE_CREDITS:
            credits_update();
            break;
        default:
            break;
        }
    }
    return;
}

int main()
{
    init(gameData.hConsole, gameData.mapData.world);
    loopGame();

    return 0;
}