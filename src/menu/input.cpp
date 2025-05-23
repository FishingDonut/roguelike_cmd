#include <conio.h>

#include "../state_machine.h"
#include "../game_data.h"
#include "include/menu/input.h"

namespace Menu
{
    void handle_input()
    {
        const int maxOptions = gameData.menuData.maxOptions;
        StateMachine selectState[maxOptions + 1] = {
            STATE_MAP_CONSTRUCTION,
            STATE_INFO,
            STATE_DIFFICULTY,
            STATE_SCORE,
            STATE_GAME_OVER};

        int &cursorOldPosition = gameData.menuData.cursorOldPosition;
        int &cursorPosition = gameData.menuData.cursorPosition;
        Config config = gameData.config;

        int keyBoard = getch();
        cursorOldPosition = cursorPosition;

        if (keyBoard == 'q' || keyBoard == 'Q' || keyBoard == 27) // ESC
        {
            nextState = STATE_GAME_OVER;
        }
        else if (keyBoard == config.UP)
        {
            cursorPosition > 0 ? cursorPosition-- : cursorPosition = maxOptions;
        }
        else if (keyBoard == config.DOWN)
        {
            cursorPosition < maxOptions ? cursorPosition++ : cursorPosition = 0;
        }
        else if (keyBoard == config.RIGHT || keyBoard == ' ' || keyBoard == 13) // espaço ou enter
        {
            nextState = selectState[cursorPosition];
            stateChanged = true;
        }
    }
}
