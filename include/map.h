#include<player.h>

struct map{
    int map[10][10];
    enum mapSpawnPositions{
        top,
        bottom,
        left,
        right,
    };
    enum entities{
        enemy = 1,
        key,
        chest,
        mimic,
    };
    enum difficulty{
        //need logic to add difficulty when pass level
        easy,
        medium,
        hard,
    };
    entities entity;
    Position spawnPos[4];
    difficulty enemyLevel;
};