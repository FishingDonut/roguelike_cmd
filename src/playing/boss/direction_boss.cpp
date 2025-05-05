#include "state_machine.h"
#include "game_data.h"
#include "core/color_char.h"
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

    // Centro do boss é a posição
    COORD center = position;

    if (room.isInRoom(player.position))
    {
        boss.color = COLOR_CYAN;
        directionY = (player.newPosition.Y > center.Y) ? 1 : (player.newPosition.Y < center.Y) ? -1 : 0;
        directionX = (player.newPosition.X > center.X) ? 1 : (player.newPosition.X < center.X) ? -1 : 0;
    }
    else if (!room.isInRoom(center))
    {
        boss.color = COLOR_RED;
        directionY = (room.centerY() > center.Y) ? 1 : (room.centerY() < center.Y) ? -1 : 0;
        directionX = (room.centerX() > center.X) ? 1 : (room.centerX() < center.X) ? -1 : 0;
    }
    else
    {
        boss.color = COLOR_GREEN;
        directionY = (rand() % 3) - 1;  // -1, 0 ou 1
        directionX = (rand() % 3) - 1;
    }

    // Limita movimento a uma direção por vez (X ou Y)
    if (directionY != 0 && directionX != 0)
    {
        if (rand() % 10 > 4)
            directionY = 0;
        else
            directionX = 0;
    }

    oldPosition = position;
    newPosition = {(SHORT)(center.X + directionX), (SHORT)(center.Y + directionY)};
}