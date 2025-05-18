#include "BearLibTerminal.h"


#include "include/state_machine.h"
#include "include/game_data.h"
#include "include/core/map_value_to_char.h"
#include "include/playing/render.h"

namespace Menu
{
    void render_frame()
    {
        int cursorOldPosition = gameData.menuData.cursorOldPosition;
        int cursorPosition = gameData.menuData.cursorPosition;

        // Limpeza do cursor antigo
        if (cursorPosition != cursorOldPosition)
        {
            terminal_put(((gameData.width / 2) - 5), (gameData.height / 2) + cursorOldPosition, ' ');
            terminal_put((gameData.width / 2) + 3, (gameData.height / 2) + cursorOldPosition, ' ');
        }

        // Desenho do novo cursor
        terminal_put(((gameData.width / 2) - 5), (gameData.height / 2) + cursorPosition, '>');
        terminal_put((gameData.width / 2) + 3, (gameData.height / 2) + cursorPosition, '<');

        // Um único refresh após todas as operações
        terminal_refresh();
    }
}