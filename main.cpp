// libs
#include <conio.h>
#include <locale.h>
#include <iostream>
#include <windows.h>
// person libs
#include "global.h"
#include "stateMachine.h"
#include "./include/core/init.h"
#include "./include/core/update.h"
#include "./include/entity/player.h"
#include "GameData.h"
// states
#include "./include/states/menu_state.h"
#include "./include/states/playing_state.h"

using namespace std;

StateMachine currentState = STATE_MENU;
StateMachine nextState = currentState;
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
    case STATE_PLAYING:
        playing_exit();
        break;
    }

    currentState = nextState;

    // enter state
    switch (currentState)
    {
    case STATE_MENU:
        menu_enter();
        break;
    case STATE_PLAYING:
        playing_enter();
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
        case STATE_PLAYING:
            playing_update();
            break;
        case STATE_GAME_OVER:
            return;
            break;
        default:
            break;
        }
    }
    return;
}

int main()
{
    init(gameData.hConsole, gameData.mapData.mapAll);
    loopGame();

    return 0;
}