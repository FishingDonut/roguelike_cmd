#include <windows.h>

#include "include/GameData.h"
#include "include/core/mapValueToChar.h"
#include "include/core/colorChar.h"
#include "include/playing/boss/render_frame_boss.h"
#include "include/playing/enemies/render_frame_enemy.h"
#include "include/playing/player/render_attack_frame.h"
#include "include/tools/getCharAtPosition.h"
#include "include/playing/render.h"

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

        render_frame_enemy();
        render_frame_boss();
        render_attack_frame();

        SetConsoleCursorPosition(hConsole, {player.position});
        cout << colorChar(player.color) << player.skin << colorChar(COLOR_RESET);
    }
}