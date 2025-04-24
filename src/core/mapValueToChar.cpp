#include "random"
#include "ctime"

#include "core/mapValueToChar.h"
#include "include/GameData.h"
#include "include/entity/enemy.h"

char mapValueToChar(int i){    
    switch (i)
    {
        case FLOOR: return ' ';                     // floor
        case WALL:                                 // wall
            if((rand() % 10) + 1 > 1){
                return '/';
            } else{
                return '\\';
            }
        case PLAYER: return gameData.player.skin;    // player
        case ENEMY: return Enemy().skin;            // enemy
        default: return '?';
    }
}