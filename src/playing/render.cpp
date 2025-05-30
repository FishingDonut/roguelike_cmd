#include <windows.h>

#include "include/game_data.h"
#include "include/core/map_value_to_char.h"
#include "include/core/color_char.h"
#include "include/playing/boss/render_frame_boss.h"
#include "include/playing/enemies/render_frame_enemy.h"
#include "include/playing/player/render_attack_frame.h"
#include "include/tools/get_char_at_position.h"
#include "include/playing/render.h"
#include "include/status/render_status.h"
#include "playing/traps/render_frame_trap.h"

namespace Playing
{
    void render_frame()
    {
        HANDLE hConsole = gameData.hConsole;
        Player &player = gameData.player;

        //clock
        SetConsoleCursorPosition(hConsole, {(SHORT)(width / 2) - 3, 0});

        if (9 >= gameData.clockData.minute)
        {
            std::cout << "0";
        }

        std::cout << gameData.clockData.minute << ":";

        if (9 >= gameData.clockData.second)
        {
            std::cout << "0";
        }

        std::cout << gameData.clockData.second;
        //clock

        if (player.moveOn)
        {
            SetConsoleCursorPosition(hConsole, {player.oldPosition});
            cout << mapValueToChar(player.previousObject);
        }

        render_frame_trap();
        render_frame_enemy();
        render_frame_boss();
        render_attack_frame();
        render_status();

        if (player.moveOn)
        {
            SetConsoleCursorPosition(hConsole, {player.position});
            cout << colorChar(player.color) << player.skin << colorChar(COLOR_RESET);
        }
    }
}