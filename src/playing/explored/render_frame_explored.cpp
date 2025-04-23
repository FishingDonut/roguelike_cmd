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
    HANDLE hConsole = gameData.hConsole;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int tile = world[i][j];

            // desenha
            if (explored[i][j] == 0)
            {
                SetConsoleCursorPosition(hConsole, {(SHORT)j, (SHORT)i});
                switch (tile)
                {
                case 0:
                    if (getCharAtPosition(hConsole, {(SHORT)j, (SHORT)i}) == '.')
                    {
                        break;
                    }
                    cout << '.';
                    break;
                case 1:
                    if (getCharAtPosition(hConsole, {(SHORT)j, (SHORT)i}) == mapValueToChar(1))
                    {
                        break;
                    }
                    cout << mapValueToChar(1);
                    break;
                case 2:
                    break;
                case 3:
                    break;
                default:
                    cout << mapValueToChar(tile);
                    break;
                }
            }

            // limpa
            if (explored[i][j] == 2)
            {
                SetConsoleCursorPosition(hConsole, {(SHORT)j, (SHORT)i});
                switch (tile)
                {
                case 0:
                    cout << " ";
                    break;
                case 1:
                    cout << mapValueToChar(1);
                    break;
                case 2:
                    cout << " ";
                    break;
                case 3:
                    cout << " ";
                    break;
                default:
                    cout << mapValueToChar(tile);
                    break;
                }
            }

            // faz nada
            if (explored[i][j] == 1)
            {
                continue;
            }
        }
    }
}
