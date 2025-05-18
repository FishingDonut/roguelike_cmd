
#include "core/init.h"
#include "game_data.h"
#include "states/menu_state.h"
#include "BearLibTerminal.h"

void init()
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