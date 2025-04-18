#include "random"
#include "ctime"

#include "core/mapValueToChar.h"
#include "include/GameData.h"

char mapValueToChar(int i){    
    switch (i)
    {
        case 0: return ' ';                     // floor
        case 1:                                 // wall
            if((rand() % 10) + 1 > 1){
                return '[';
            } else{
                return ']';
            }
        case 2: return gameData.player.skin;    // player
        case 3: return '*';                     // item
        default: return ' ';
    }
}