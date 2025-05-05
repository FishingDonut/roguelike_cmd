#include "windows.h"

#include "game_data.h"
#include "core/color_char.h"
#include "core/map_value_to_char.h"
#include "playing/player/render_attack_frame.h"

void render_attack_frame()
{
    if(!gameData.player.isAttackFrame){
        return;
    }
    
    auto &hConsole = game_data.hConsole;
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
        Sleep(30);
        SetConsoleCursorPosition(hConsole, {(SHORT)x, (SHORT)y});
        std::cout << colorChar(COLOR_RESET) << mapValueToChar(world[y][x]) << colorChar(COLOR_RESET);
    }
    
    gameData.player.isAttackFrame = false;
    return;
}