#include "./primitiveTypes.h"
#include "./enemy.h"

using namespace std;

struct map
{
    static const short int maxEnemy = 4;
    enemy enemyList[maxEnemy];

    int map[16][16] = {};
    enum mapSpawnPositions
    {
        top,
        bottom,
        left,
        right,
    };
    enum entities
    {
        floor = 0,
        parede = 1,
        enemy = 2,
        item,
        chest,
        mimic,
        fakewall = 11,
        portaSupInf = 91,
        portaLat = 92,
        vazio = 9,
    };
    enum difficulty
    {
        // need logic to add difficulty when pass level
        easy,
        medium,
        hard,
    };
    entities entity;
    Position spawnPos[4];
    difficulty enemyLevel;

    void clearEnemyRoom(){
        for(int i = 0; i < maxEnemy; i++){
            enemyList[i] = {};
        }
    }
};