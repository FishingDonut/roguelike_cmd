#include "random"
#include "ctime"

#include "core/map_value_to_char.h"
#include "include/game_data.h"
#include "include/entity/enemy.h"
#include "include/entity/boss.h"
#include "include/entity/trap.h"

char mapValueToChar(int i)
{
    switch (i)
    {
    case FLOOR: // floor
        return ' ';
    case WALL: // wall
        if ((rand() % 10) + 1 > 1)
        {
            return '/';
        }
        else
        {
            return '\\';
        }
    case PLAYER: // player
        return gameData.player.skin;
    case ENEMY: // enemy
        return Enemy().skin;
    case STAIR: // escadas
        if ((rand() % 10) + 1 > 1)
        {
            return '>';
        }
        else
        {
            return '<';
        }
    case BOSS:
        return Boss().skin;
    case TRAP:
        return Trap().currentSkin;
    default:
        return '?';
    }
}