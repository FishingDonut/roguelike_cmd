#include "../stateMachine.h"
#include "../GameData.h"
#include "include/playing/enemies/direction_enemy.h"
#include "core/colorChar.h"

void direction_enemy(bool isPlayerInRoom, Enemy &enemy, Room room)
{
    Player &player = gameData.player;
    COORD &oldPosition = enemy.oldPosition;
    COORD &position = enemy.position;
    COORD &newPosition = enemy.newPosition;
    int directionY = 0;
    int directionX = 0;

    if (isPlayerInRoom || room.exploredRoom)
    {
        enemy.color = COLOR_RED;
        position.Y < player.newPosition.Y ? directionY = 1 : directionY = -1;
        position.X < player.newPosition.X ? directionX = 1 : directionX = -1;

        position.Y == player.newPosition.Y ? directionY = 0 : 0;
        position.X == player.newPosition.X ? directionX = 0 : 0;
    }
    else
    {
        directionY = (rand() % 3) - 1;
        directionX = (rand() % 3) - 1;
    }

    if (directionY != 0 && directionX != 0)
    {
        if (rand() % 10 > 5)
        {
            directionY = 0;
        }
        else
        {
            directionX = 0;
        }
    }

    oldPosition = position;
    newPosition = {(SHORT)(position.X + directionX), (SHORT)(position.Y + directionY)};
    return;
}