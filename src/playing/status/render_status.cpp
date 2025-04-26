#include <windows.h>

#include "include/GameData.h"
#include "include/status/render_status.h"
#include "include/core/mapValueToChar.h"
#include "include/core/colorChar.h"

void render_status()
{
    HANDLE hConsole = gameData.hConsole;
    Player &player = gameData.player;
    Status &status = gameData.status;

    if(player.kills != status.kills){
        status.kills = player.kills;
        SetConsoleCursorPosition(hConsole, {25, (SHORT)height - 1});
        cout << "--------------";
        SetConsoleCursorPosition(hConsole, {25, (SHORT)height - 1});
        cout << "[ kills: " << colorChar(COLOR_GREEN) << player.kills << colorChar(COLOR_RESET) << " ]";
    }

    if (status.hp != player.health)
    {
        status.hp = player.health;
        SetConsoleCursorPosition(hConsole, {12, (SHORT)height - 1});
        cout << "--------------";
        SetConsoleCursorPosition(hConsole, {12, (SHORT)height - 1});
        cout << "[ hp: " << colorChar(COLOR_GREEN) << player.health << colorChar(COLOR_RESET) << " ]";
    }
}
