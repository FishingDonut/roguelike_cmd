using namespace std;
struct Position{
    int x;
    int y;
};

struct map{
    int map[16][16] = {};
    enum mapSpawnPositions{
        top,
        bottom,
        left,
        right,
    };
    enum entities{
        parede = 1,
        enemy = 2,
        key,
        chest,
        mimic,
        portaSupInf = 91,
        portaLat = 92,
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