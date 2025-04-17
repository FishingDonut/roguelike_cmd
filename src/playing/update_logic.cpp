#include <windows.h>

#include "../stateMachine.h"
#include "../GameData.h"
#include "include/playing/update_logic.h"

void update_logic()
{
    Player &player = gameData.player;
    COORD &newPosition = gameData.player.newPosition;
    COORD &oldPosition = gameData.player.oldPosition;
    int (&map)[height][width] = gameData.mapData.mapAll;
    int &currentObject = gameData.mapData.currentObject;
    int &previousObject = gameData.mapData.previousObject;
    int nearbyObject;

    oldPosition = player.position;
    
    nearbyObject = map[newPosition.Y][newPosition.X];
    if(nearbyObject == 2){
        return;
    }

    previousObject = currentObject;
    currentObject = nearbyObject;
    
    player.setPosition(newPosition.X, newPosition.Y);
    
    map[oldPosition.Y][oldPosition.X] = previousObject;
    map[player.position.Y][player.position.X] = player.valueMap;
    return;
}