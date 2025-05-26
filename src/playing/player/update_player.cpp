#include <windows.h>
#include <vector>

#include "../state_machine.h"
#include "../game_data.h"
#include "include/playing/player/update_player.h"
#include "include/playing/player/time_player.h"
#include "include/playing/player/attack.h"
#include "core/search_entity.h"

void removeItemAt(COORD position)
{
    Item *items = gameData.mapData.itens;
    int &count = gameData.mapData.countItens;

    for (int i = 0; i < count; ++i)
    {
        if (items[i].x == position.X && items[i].y == position.Y)
        {
            items[i] = items[count - 1];
            count--;
            return;
        }
    }
}

void handle_collision(int tile)
{
    if (tile == STAIR)
    {
        nextState = STATE_MAP_CONSTRUCTION;
        stateChanged = true;
    }
}

bool is_collision(int tile)
{
    Trap trap;
    Item item;
    switch (tile)
    {
    case FLOOR:
        return false;
    case WALL:
    case PLAYER:
        return true;
    case ENEMY:
    case BOSS:
        return false;
    case STAIR:
        return true;
    case TRAP:
        trap = searchTrap(gameData.player.newPosition);
        gameData.player.updateHealth(-trap.damage);
        return false;
    case ITEM:
    {
        int (&map)[height][width] = gameData.mapData.world;
        item = searchItem(gameData.player.newPosition);
        gameData.player.inventory = item;

        map[gameData.player.newPosition.Y][gameData.player.newPosition.X] = FLOOR;
        removeItemAt(gameData.player.newPosition);

        return false;
    }
    default:
        return true;
    }
}

void update_map()
{
    Player &player = gameData.player;
    COORD &oldPosition = player.oldPosition;
    int (&map)[height][width] = gameData.mapData.world;
    int &previousObject = player.previousObject;

    map[oldPosition.Y][oldPosition.X] = previousObject;
    map[player.position.Y][player.position.X] = PLAYER;
}

void update_player()
{
    Player &player = gameData.player;
    COORD &newPosition = player.newPosition;
    COORD &oldPosition = player.oldPosition;
    int (&map)[height][width] = gameData.mapData.world;
    int nearbyObject;

    if (!player.IsUpdate)
        return;

    if (player.isAttackUpdate)
    {
        attack();
        player.isAttackUpdate = false;
    }

    if (newPosition.Y == player.position.Y && newPosition.X == player.position.X)
    {
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

    // player.previousObject = nearbyObject;
    player.setPosition(newPosition.X, newPosition.Y);
    player.setDirection();
    update_map();
}
