#include <windows.h>

#include "include/stateMachine.h"
#include "include/GameData.h"
#include "include/core/mapValueToChar.h"
#include "include/core/colorChar.h"
#include "include/tools/getCharAtPosition.h"
#include "include/playing/explored/render_frame_explored.h"

// SetConsoleCursorPosition(hConsole, {});

void render_frame_explored()
{
    auto &explored = gameData.mapData.explored;
    auto &world = gameData.mapData.world;
    auto &screenBuffer = gameData.screenBuffer;
    HANDLE hConsole = gameData.hConsole;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int tile = world[i][j];

            // faz nada
            if (explored[i][j] == 1)
            {
                continue;
            }

            // desenha
            if (explored[i][j] == 0)
            {
                if (screenBuffer[i][j] == tile)
                {
                    continue;
                }
                else
                {
                    SetConsoleCursorPosition(hConsole, {(SHORT)j, (SHORT)i});
                    std::cout << mapValueToChar(tile);
                    continue;
                }
            }

            // limpa
            if (explored[i][j] == 2)
            {
                SetConsoleCursorPosition(hConsole, {(SHORT)j, (SHORT)i});
                if(tile == 3){
                    std::cout << " ";
                }
                continue;
            }
        }
    }
}
