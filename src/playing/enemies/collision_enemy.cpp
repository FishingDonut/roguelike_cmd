#include "state_machine.h"
#include "game_data.h"
#include "core/search_entity.h"
#include "include/playing/enemies/collision_enemy.h"

void collision_enemy(Enemy &enemy)
{
    Player &player = gameData.player;
    COORD &oldPosition = enemy.oldPosition;
    COORD &position = enemy.position;
    COORD &newPosition = enemy.newPosition;
    int &previousObject = enemy.previousObject;
    int &currentObject = enemy.currentObject;
    auto &map = gameData.mapData.world;
    int nearbyObject = map[newPosition.Y][newPosition.X];
    Trap trap = searchTrap(newPosition);

    switch (nearbyObject)
    {
    case FLOOR:
        previousObject = currentObject;
        currentObject = nearbyObject;

        enemy.setPosition();

        map[oldPosition.Y][oldPosition.X] = previousObject;
        map[position.Y][position.X] = enemy.valueMap;
        break;
    case WALL:
        newPosition = oldPosition;
        return;
        break;
    case PLAYER:
        player.updateHealth(-enemy.damage);
        return;
        break;
    case TRAP:
        previousObject = currentObject;
        currentObject = nearbyObject;

        enemy.setPosition();

        map[oldPosition.Y][oldPosition.X] = previousObject;
        map[position.Y][position.X] = enemy.valueMap;
        
        if(trap.active){
            enemy.updateHealth(-trap.damage);
        }

        return;
        break;
    default:
        break;
    }
    return;
}