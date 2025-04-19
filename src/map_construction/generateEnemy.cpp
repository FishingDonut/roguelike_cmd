#include "global.h"
#include "entity/room.h"
#include "map_construction/generateEnemy.h"

void generateEnemy(Room &newRoom, int (&map)[height][width])
{
    int &countEnemy = newRoom.enemyCount;

    int newPX;
    int newPY;

    for (int i = 0; i < newRoom.maxEnemy; i++)
    {
        if ((rand() % 10) > 5 && countEnemy < newRoom.maxEnemy)
        {
            do
            {
                newPX = newRoom.x + (rand() % newRoom.width);
                newPY = newRoom.y + (rand() % newRoom.height);
            } while (map[newPY][newPX] != 0);

            Enemy enemy = Enemy();

            enemy.health = 10;
            enemy.damage = 10;
            enemy.newPosition = {(SHORT)newPX, (SHORT)newPY};
            enemy.oldPosition = enemy.newPosition;
            enemy.currentObject = 0;
            enemy.previousObject = 0;
            enemy.setPosition();

            map[newPY][newPX] = enemy.valueMap;
            newRoom.enemies[countEnemy] = enemy;
            countEnemy++;
        }
    }
}