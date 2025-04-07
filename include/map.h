#include "./primitiveTypes.h"

using namespace std;

struct map
{
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
};