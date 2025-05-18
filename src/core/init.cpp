#include "global.h"
#include "core/init.h"
#include "game_data.h"
#include "states/menu_state.h"
#include "BearLibTerminal.h"

void assembleMap(int (&matriz)[height][width])
{
    for (short i = 0; i < height; ++i)
    {
        for (short j = 0; j < width; ++j)
        {
            matriz[i][j] = FLOOR;

            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                matriz[i][j] = WALL;
            }
        }
    }
}

void init(int (&matriz)[height][width])
{
    terminal_open();
    terminal_set("window: title='Castle Rogue', size= 156x44, fullscreen=true");
    terminal_set("font: Media/HackNerdFontMono-Regular.ttf, size = 10");
    terminal_clear();
    gameData.seed = time(0);
    srand(gameData.seed);
    menu_enter();
    return;
}