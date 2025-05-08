#include <windows.h>

#include "global.h"
#include "include/state_machine.h"
#include "include/game_data.h"
#include "include/core/map_value_to_char.h"
#include "include/playing/render.h"

namespace Menu
{
    void render_frame()
    {
        HANDLE hConsole = gameData.hConsole;
        int cursorOldPosition = gameData.menuData.cursorOldPosition;
        int cursorPosition = gameData.menuData.cursorPosition;

        if(cursorPosition != cursorOldPosition){
            SetConsoleCursorPosition(hConsole, {(SHORT)((width / 2) - 5), (SHORT)((height / 2) + cursorOldPosition)});
            cout << " ";
            SetConsoleCursorPosition(hConsole, {(SHORT)((width / 2) + 3), (SHORT)((height / 2) + cursorOldPosition)});
            cout << " ";
        }

        SetConsoleCursorPosition(hConsole, {(SHORT)((width / 2) - 5), (SHORT)((height / 2) + cursorPosition)});
        cout << ">";
        SetConsoleCursorPosition(hConsole, {(SHORT)((width / 2) + 3), (SHORT)((height / 2) + cursorPosition)});
        cout << "<";
    }
}