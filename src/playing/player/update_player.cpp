#include <windows.h>

#include "../stateMachine.h"
#include "../GameData.h"
#include "include/playing/player/update_player.h"

void update_player()
{
    Player &player = gameData.player;
    COORD &newPosition = gameData.player.newPosition;
    COORD &oldPosition = gameData.player.oldPosition;
    int (&map)[height][width] = gameData.mapData.world;
    int &currentObject = gameData.player.currentObject;
    int &previousObject = gameData.player.previousObject;
    int nearbyObject;

    oldPosition = player.position;

    nearbyObject = map[newPosition.Y][newPosition.X];

    switch (nearbyObject)
    {
    case FLOOR:
        break;
    case WALL:
        newPosition = oldPosition;
        return;
        break;
    case PLAYER:
        newPosition = oldPosition;
        return;
        break;
    case ENEMY:
    //     newPosition = oldPosition;
    //     return;
        break;
    default:
        newPosition = oldPosition;
        return;
        break;
    }

    previousObject = currentObject;
    currentObject = nearbyObject;

    player.setPosition(newPosition.X, newPosition.Y);

    map[oldPosition.Y][oldPosition.X] = previousObject;
    map[player.position.Y][player.position.X] = PLAYER;
    return;
}