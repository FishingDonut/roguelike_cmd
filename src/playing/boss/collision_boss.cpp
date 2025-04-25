#include "../stateMachine.h"
#include "../GameData.h"
#include "entity/boss.h"
#include "include/playing/boss/collision_boss.h"

void collision_boss()
{
    if (!gameData.bossFloor)
    {
        return;
    }

    Boss &boss = gameData.boss;
    COORD &oldPosition = boss.oldPosition;
    COORD &position = boss.position;
    COORD &newPosition = boss.newPosition;
    int &previousObject = boss.previousObject;
    int &currentObject = boss.currentObject;
    auto &map = gameData.mapData.world;
    int nearbyObject = map[newPosition.Y][newPosition.X];

    switch (nearbyObject)
    {
    case FLOOR:
    case BOSS:
        previousObject = currentObject;
        currentObject = nearbyObject;

        boss.setPosition();

        map[oldPosition.Y][oldPosition.X] = previousObject;
        map[position.Y][position.X] = boss.valueMap;
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