
#include "BearLibTerminal.h"

#include "game_data.h"
#include "core/color_char.h"
#include "playing/traps/render_frame_trap.h"

void render_frame_trap()
{
    const int MAX_TRAPS = gameData.mapData.MAX_TRAPS;
    auto& traps = gameData.mapData.traps;

    for (int i = 0; i < MAX_TRAPS; i++)
    {
        Trap &trap = traps[i];

        if(!trap.active || !trap.visible){
            continue;
        }

        terminal_put(trap.position.X, trap.position.Y,trap.currentSkin);
    }
    return;
}