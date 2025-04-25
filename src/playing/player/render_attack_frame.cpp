#include "windows.h"

#include "GameData.h"
#include "core/colorChar.h"
#include "core/mapValueToChar.h"
#include "playing/player/render_attack_frame.h"

void render_attack_frame()
{
    auto &hConsole = gameData.hConsole;
    auto &player = gameData.player;
    auto &position = player.position;
    auto &world = gameData.mapData.world;
    auto &attackDistance = player.attackDistance;
    auto &dirY = player.dirY;
    auto &dirX = player.dirX;

    for (int i = 1; i <= attackDistance; i++)
    {
        int y = position.Y + dirY * i;
        int x = position.X + dirX * i;

        SetConsoleCursorPosition(hConsole, {(SHORT)x, (SHORT)y});
        std::cout << colorChar(COLOR_REVERSE) << mapValueToChar(world[y][x]) << colorChar(COLOR_RESET);
    }

    return;
}