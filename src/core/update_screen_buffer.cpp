#include "core/update_screen_buffer.h"
#include "global.h"
#include "GameData.h"

void update_screen_buffer()
{
    auto &screenBuffer = gameData.screenBuffer;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            screenBuffer[i][j] = 9;
        }
    }
    return;
};