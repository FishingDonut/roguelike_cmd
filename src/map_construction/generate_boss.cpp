
#include "game_data.h"
#include "entity/room.h"
#include "map_construction/generate_boss.h"

void generateBoss(Room &room, int (&world)[gameData.height][gameData.width])
{
    gameData.boss = Boss();
    Boss &boss = gameData.boss;
    boss.room = room;
    boss.alive = true;
    boss.health = 40;
    boss.damage = 4;
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