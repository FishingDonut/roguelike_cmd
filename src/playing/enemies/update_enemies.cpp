#include "../stateMachine.h"
#include "../GameData.h"
#include "include/playing/enemies/update_enemies.h"

void update_enemies()
{
    const int maxRooms = gameData.mapData.maxRooms;
    Room(&rooms)[maxRooms] = gameData.mapData.rooms;
    Player &player = gameData.player;
    auto &map = gameData.mapData.mapAll;

    for (int j = 0; j < maxRooms; j++)
    {
        Room &room = rooms[j];
        bool isPlayerInRoom = room.isInRoom(player.position);

        for (int i = 0; i < room.enemyCount; i++)
        {
            Enemy &enemy = room.enemies[i];
            COORD &oldPosition = enemy.oldPosition;
            COORD &position = enemy.position;
            COORD &newPosition = enemy.newPosition;
            int &previousObject = enemy.previousObject;
            int &currentObject = enemy.currentObject;
            int directionY = 0;
            int directionX = 0;

            if (isPlayerInRoom)
            {
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

            int nearbyObject = map[newPosition.Y][newPosition.X];

            switch (nearbyObject)
            {
            case 0:
                previousObject = currentObject;
                currentObject = nearbyObject;

                enemy.setPosition();

                map[oldPosition.Y][oldPosition.X] = previousObject;
                map[position.Y][position.X] = enemy.valueMap;
                break;
            case 1:
                newPosition = oldPosition;
                continue;
                break;
            case 2:
                continue;
                break;
            default:
                break;
            }
        }
    }
    return;
}