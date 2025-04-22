#include <windows.h>

#include "include/stateMachine.h"
#include "include/GameData.h"
#include "include/core/mapValueToChar.h"
#include "include/core/colorChar.h"
#include "include/playing/render.h"
#include "include/tools/getCharAtPosition.h"

namespace Playing
{
    void render_frame()
    {
        auto &explored = gameData.mapData.explored;
        auto &world = gameData.mapData.world;
        HANDLE hConsole = gameData.hConsole;
        Player &player = gameData.player;

        // SetConsoleCursorPosition(hConsole, {0, 0});
        // cout << getCharAtPosition(hConsole, newPos);

        SetConsoleCursorPosition(hConsole, {player.oldPosition});
        cout << mapValueToChar(player.previousObject);

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (explored[i][j] == 2)
                {
                    SetConsoleCursorPosition(hConsole, {(SHORT)j, (SHORT)i});
                    cout << ' ';
                }

                if (explored[i][j] != 0)
                {
                    continue;
                }

                if (getCharAtPosition(hConsole, {(SHORT)j, (SHORT)i}) == mapValueToChar(world[i][j]))
                {
                    continue;
                }
                SetConsoleCursorPosition(hConsole, {(SHORT)j, (SHORT)i});
                cout << mapValueToChar(world[i][j]);
            }
        }

        SetConsoleCursorPosition(hConsole, {player.position});
        cout << colorChar(player.color) << player.skin << colorChar(COLOR_RESET);
    }
}