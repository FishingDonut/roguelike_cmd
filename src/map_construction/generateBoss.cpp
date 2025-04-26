#include "global.h"
#include "GameData.h"
#include "entity/room.h"
#include "map_construction/generateBoss.h"

void generateBoss(Room &room, int (&world)[height][width])
{
    gameData.boss = Boss();
    Boss &boss = gameData.boss;
    boss.room = room;
    boss.alive = true;
    boss.health = 20;
    boss.damage = 2;
    boss.newPosition.Y = room.centerY();
    boss.newPosition.X = room.centerX();
    boss.setPosition();
    room.exploredRoom = false;
    
    int initY = boss.position.Y - (boss.height / 2);
    int initX = boss.position.X - (boss.width / 2);

    for (int i = 0; i < boss.height; i++)
    {
        for (int j = 0; j < boss.width; j++){
            int y = initY + i;
            int x = initX + j;
            
            world[y][x] = BOSS;
        }
    }
    
    return;
}