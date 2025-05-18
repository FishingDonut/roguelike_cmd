#include "BearLibTerminal.h"

#include "game_data.h"
#include "core/set_config_key.h"

void setConfigKey()
{
    auto &config = gameData.config;

    int c = terminal_read();

    switch (c)
    {
    case TK_W:
    case TK_A:
    case TK_S:
    case TK_D:
        config.setDefaultKeys();
        break;
    case 'h':
    case 'j':
    case 'k':
    case 'l':
        config.setVimKeys();
        break;
    case 72:
    case 80:
    case 75:
    case 77:
        config.setArrow();
        break;
    default:
        config.setDefaultKeys();
        break;
    }
};