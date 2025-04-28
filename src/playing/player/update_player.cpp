#include <windows.h>

#include "../stateMachine.h"
#include "../GameData.h"
#include "include/playing/player/update_player.h"
#include "include/playing/player/attack.h"
#include "core/searchEntity.h"

void handle_collision(int tile){
    switch (tile)
    {
    case STAIR:
        nextState = STATE_MAP_CONSTRUCTION;
        stateChanged = true;
        break;
    default:
        break;
    }
    return;
}

bool is_collision(int tile)
{
    Trap trap;
    switch (tile)
    {
    case FLOOR:
        return false;
        break;
    case WALL:
        return true;
        break;
    case PLAYER:
        return true;
        break;
    case ENEMY:
        return false;
        break;
    case STAIR:
        return true;
        break;
    case BOSS:
        return false;
        break;
    case TRAP:
        trap = searchTrap(gameData.player.newPosition);
        gameData.player.updateHealth(-trap.damage);
        return false;
        break;
    default:
        return true;
        break;
    }
}

void update_map()
{
    Player &player = gameData.player;
    COORD &oldPosition = gameData.player.oldPosition;
    int (&map)[height][width] = gameData.mapData.world;
    int &previousObject = gameData.player.previousObject;

    map[oldPosition.Y][oldPosition.X] = previousObject;
    map[player.position.Y][player.position.X] = PLAYER;
    return;
}

void update_player()
{
    Player &player = gameData.player;
    COORD &newPosition = gameData.player.newPosition;
    COORD &oldPosition = gameData.player.oldPosition;
    int (&map)[height][width] = gameData.mapData.world;
    int &currentObject = gameData.player.currentObject;
    int &previousObject = gameData.player.previousObject;
    int nearbyObject;

    if(player.isAttackUpdate){
        attack();
        player.isAttackUpdate = false;
    }

    if(newPosition.Y == player.position.Y && newPosition.X == player.position.X){
        update_map();
        return;
    }

    oldPosition = player.position;
    nearbyObject = map[newPosition.Y][newPosition.X];

    if (is_collision(nearbyObject))
    {
        handle_collision(nearbyObject);
        newPosition = oldPosition;
        return;
    }

    player.setPosition(newPosition.X, newPosition.Y);
    player.setDirection();
    previousObject = currentObject;
    currentObject = nearbyObject;

    update_map();
    return;
}