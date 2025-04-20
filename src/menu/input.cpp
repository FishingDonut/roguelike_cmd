#include <conio.h>

#include "../stateMachine.h"
#include "../GameData.h"
#include "include/menu/input.h"

namespace Menu
{
    void handle_input()
    {
        const int maxOptions = gameData.menuData.maxOptions;
        StateMachine selectState[maxOptions + 1] = {STATE_MAP_CONSTRUCTION, STATE_MENU, STATE_GAME_OVER};
        int &cursorOldPosition = gameData.menuData.cursorOldPosition;
        int &cursorPosition = gameData.menuData.cursorPosition;
        int keyBoard = getch();
        cursorOldPosition = cursorPosition;

        switch (keyBoard)
        {
        case 113:
        case 81:
        case 27:
            nextState = STATE_GAME_OVER;
            break;
        case 119:
            cursorPosition > 0 ? cursorPosition-- : cursorPosition = maxOptions;
            break;
        case 115:
            cursorPosition < maxOptions ? cursorPosition++ : cursorPosition = 0;
            break;
        case 100:
        case 32:
        case 13:
            nextState = selectState[cursorPosition];
            stateChanged = true;
            break;
        default:
            break;
        }
        return;
    }
}