#include "BearLibTerminal.h"

#include "game_data.h"
#include "core/color_char.h"
#include "core/map_value_to_char.h"
#include "playing/player/render_attack_frame.h"

void render_attack_frame()
{
    if(!gameData.player.isAttackFrame){
        return;
    }
    
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
        
        terminal_color(color_from_name("black"));
        terminal_bkcolor(color_from_name("white"));
        terminal_put(x, y , mapValueToChar(world[y][x]));
        Sleep(30);
        terminal_color(color_from_name("white"));
        terminal_bkcolor(color_from_name("black"));
        terminal_put(x, y , mapValueToChar(world[y][x]));
    }
    
    gameData.player.isAttackFrame = false;
    return;
}