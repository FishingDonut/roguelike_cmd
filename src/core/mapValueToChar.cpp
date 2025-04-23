#include "random"
#include "ctime"

#include "core/mapValueToChar.h"
#include "include/GameData.h"
#include "include/entity/enemy.h"

char mapValueToChar(int i)
{
    switch (i)
    {
    case 0:
        return ' '; // floor
        break;
    case 1:
        return '#'; // wall
                    // if((rand() % 10) + 1 > 1){
                    //     return '#';
                    // } else{
        //     return '#';
        // }
        break;
    case 2:
        return gameData.player.skin; // player
        break;
    case 3:
        return Enemy().skin; // enemy
        break;
    default:
        return '?';
        break;
    }
}