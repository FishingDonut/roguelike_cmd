#include "BearLibTerminal.h"

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
            STATE_GAME_OVER};

        int &cursorOldPosition = gameData.menuData.cursorOldPosition;
        int &cursorPosition = gameData.menuData.cursorPosition;
        Config config = gameData.config;

        int keyBoard = terminal_read();
        cursorOldPosition = cursorPosition;

        if (keyBoard == TK_Q || keyBoard == TK_ESCAPE || keyBoard == TK_CLOSE) // ESC
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
        else if (keyBoard == config.RIGHT || keyBoard == TK_SPACE || keyBoard == TK_ENTER) // espaço ou enter
        {
            nextState = selectState[cursorPosition];
            stateChanged = true;
        }
    }
}
