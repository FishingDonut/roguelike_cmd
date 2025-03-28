using namespace std;
struct Position{
    int x;
    int y;
};

struct map{
    int map[10][10] = {};
    enum mapSpawnPositions{
        top,
        bottom,
        left,
        right,
    };
    enum entities{
        enemy = 2,
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