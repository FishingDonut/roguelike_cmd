#include "BearLibTerminal.h"

#include "global.h"
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
            terminal_put(((width / 2) - 5), (height / 2) + cursorOldPosition, ' ');
            terminal_put((width / 2) + 3, (height / 2) + cursorOldPosition, ' ');
        }

        // Desenho do novo cursor
        terminal_put(((width / 2) - 5), (height / 2) + cursorPosition, '>');
        terminal_put((width / 2) + 3, (height / 2) + cursorPosition, '<');
        
        terminal_put((width / 2) + 3, (height / 2) + cursorPosition + 5, width);
        terminal_put((width / 2) + 3, (height / 2) + cursorPosition + 6, height);

        // Um único refresh após todas as operações
        terminal_refresh();
    }
}