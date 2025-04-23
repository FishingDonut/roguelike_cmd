#include <windows.h>

#include "include/stateMachine.h"
#include "include/GameData.h"
#include "include/core/mapValueToChar.h"
#include "include/core/colorChar.h"
#include "include/playing/render.h"
#include "include/playing/enemies/render_frame_enemy.h"
#include "include/playing/explored/render_frame_explored.h"
#include "include/tools/getCharAtPosition.h"

namespace Playing
{
    void render_frame()
    {
        HANDLE hConsole = gameData.hConsole;
        Player &player = gameData.player;

        // SetConsoleCursorPosition(hConsole, {0, 0});
        // cout << getCharAtPosition(hConsole, newPos);

        SetConsoleCursorPosition(hConsole, {player.oldPosition});
        cout << mapValueToChar(player.previousObject);

        render_frame_explored();
        render_frame_enemy();

        SetConsoleCursorPosition(hConsole, {player.position});
        cout << colorChar(player.color) << player.skin << colorChar(COLOR_RESET);
    }
}