#include "stateMachine.h"
#include "GameData.h"
#include "core/colorChar.h"
#include "entity/boss.h"
#include "playing/boss/direction_boss.h"

void direction_boss()
{
    Boss &boss = gameData.boss;
    Room &room = boss.room;
    Player &player = gameData.player;
    COORD &oldPosition = boss.oldPosition;
    COORD &position = boss.position;
    COORD &newPosition = boss.newPosition;
    int directionY = 0;
    int directionX = 0;

    if (room.isInRoom(player.position))
    {
        boss.color = COLOR_CYAN;
        position.Y < player.newPosition.Y ? directionY = 1 : directionY = -1;
        position.X < player.newPosition.X ? directionX = 1 : directionX = -1;

        position.Y == player.newPosition.Y ? directionY = 0 : 0;
        position.X == player.newPosition.X ? directionX = 0 : 0;
    }
    else if (!room.isInRoom(position))
    {
        boss.color = COLOR_RED;
        position.Y < room.centerY() ? directionY = 1 : directionY = -1;
        position.X < room.centerX() ? directionX = 1 : directionX = -1;
    }
    else
    {
        boss.color = COLOR_GREEN;
        directionY = (rand() % 3) - 1;
        directionX = (rand() % 3) - 1;
    }

    if (directionY != 0 && directionX != 0)
    {
        if (rand() % 10 > 4)
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