#include "../stateMachine.h"
#include "../GameData.h"
#include "include/playing/enemies/collision_enemy.h"

void collision_enemy(Enemy &enemy)
{
    COORD &oldPosition = enemy.oldPosition;
    COORD &position = enemy.position;
    COORD &newPosition = enemy.newPosition;
    int &previousObject = enemy.previousObject;
    int &currentObject = enemy.currentObject;
    auto &map = gameData.mapData.world;
    int nearbyObject = map[newPosition.Y][newPosition.X];

    switch (nearbyObject)
    {
    case FLOOR:
        previousObject = currentObject;
        currentObject = nearbyObject;

        enemy.setPosition();

        map[oldPosition.Y][oldPosition.X] = previousObject;
        map[position.Y][position.X] = ENEMY;
        break;
    case WALL:
        newPosition = oldPosition;
        return;
        break;
    case PLAYER:
        return;
        break;
    default:
        break;
    }
    return;
}