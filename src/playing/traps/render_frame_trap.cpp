
#include <windows.h>
#include "GameData.h"
#include "core/colorChar.h"
#include "playing/traps/render_frame_trap.h"

void render_frame_trap()
{
    const int MAX_TRAPS = gameData.mapData.MAX_TRAPS;
    auto& traps = gameData.mapData.traps;
    auto& hConsole = gameData.hConsole;

    for (int i = 0; i < MAX_TRAPS; i++)
    {
        Trap &trap = traps[i];

        if(!trap.active || !trap.visible){
            continue;
        }

        SetConsoleCursorPosition(hConsole, {trap.position});
        cout << colorChar(trap.color) << trap.currentSkin << colorChar(COLOR_RESET);
    }
    return;
}