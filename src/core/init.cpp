#include <string.h>

#include "core/init.h"
#include "game_data.h"
#include "states/menu_state.h"
#include "BearLibTerminal.h"

void init()
{
    terminal_open();
    std::string config = "window: title='Castle Rogue', size= " + std::to_string(gameData.width) +"x" + std::to_string(gameData.height) + ", fullscreen=true";
    terminal_set(config.c_str());
    terminal_set("font: Media/HackNerdFontMono-Regular.ttf, size = 11");
    terminal_clear();
    gameData.seed = time(0);
    srand(gameData.seed);
    menu_enter();
    return;
}