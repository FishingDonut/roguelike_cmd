#include "../stateMachine.h"
#include "../GameData.h"
#include "include/playing/boss/update_boss.h"
#include "playing/boss/direction_boss.h"

void update_boss()
{
    if(!gameData.floorCount){
        return;
    }

    if(!gameData.boss.alive){
        return;
    }

    direction_boss();
    return;
}