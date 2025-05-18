#include "ctime"


#include "game_data.h"
#include "entity/room.h"
#include "entity/trap.h"
#include "Data/MapData.h"
#include "map_construction/generate_trap.h"

void generateTrap(int (&world)[gameData.height][gameData.width])
{
    const int MAX_TRAPS = gameData.mapData.MAX_TRAPS;
    auto &traps = gameData.mapData.traps;
    auto &countTraps = gameData.mapData.countTraps;
    countTraps = 0;
    Trap trap;

    while (countTraps < MAX_TRAPS)
    {
        int y = rand() % gameData.height;
        int x = rand() % gameData.width;

        if(world[y][x] != FLOOR)
            continue;

        world[y][x] = TRAP;

        Trap trap = Trap();
        trap.init(x, y);
        traps[countTraps++] = trap;
    }
}