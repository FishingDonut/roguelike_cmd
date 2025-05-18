
#include "entity/room.h"
#include "game_data.h"
#include "map_construction/generate_enemy.h"

void generateEnemy(Room &newRoom, int (&map)[gameData.height][gameData.width])
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
            } while (map[newPY][newPX] != FLOOR);

            Enemy enemy = Enemy();

            enemy.health = 2;
            enemy.damage = 1;
            enemy.newPosition = {(SHORT)newPX, (SHORT)newPY};
            enemy.oldPosition = enemy.newPosition;
            enemy.currentObject = FLOOR;
            enemy.previousObject = FLOOR;
            enemy.setPosition();

            map[newPY][newPX] = ENEMY;
            newRoom.enemies[countEnemy] = enemy;
            countEnemy++;
        }
    }
}