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
    bool running = true;

    while (running)
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
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD newPosition = {10, 10};
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    Player player = Player();

    int nearbyObject;
    int previousObject;

    system("cls");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    // matriz fixa
    int map[height][width];

    player.position = newPosition;

    init(hConsole, map);

    nearbyObject = map[player.position.X][player.position.Y];
    previousObject = nearbyObject;
    map[player.position.X][player.position.Y] = player.valueMap;

    loopGame();
    return 0;
}