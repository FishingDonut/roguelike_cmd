#include <conio.h>

#include "game_data.h"
#include "core/set_config_key.h"

void setConfigKey()
{
    auto &config = gameData.config;

    char c = getch();

    switch (c)
    {
    case 'w':
    case 'a':
    case 's':
    case 'd':
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