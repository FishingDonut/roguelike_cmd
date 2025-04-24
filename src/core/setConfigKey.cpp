#pragma once

#include <conio.h>

#include "GameData.h"
#include "core/setConfigKey.h"

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
    default:
        config.setDefaultKeys();
        break;
    }
};