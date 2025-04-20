#include <windows.h>

#include "global.h"
#include "include/stateMachine.h"
#include "include/GameData.h"
#include "include/core/mapValueToChar.h"
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