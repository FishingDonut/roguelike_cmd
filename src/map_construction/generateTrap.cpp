#include "ctime"

#include "global.h"
#include "GameData.h"
#include "entity/room.h"
#include "entity/trap.h"
#include "Data/MapData.h"
#include "map_construction/generateTrap.h"

void generateTrap(Room &room, int (&world)[height][width])
{
    const int MAX_TRAPS = gameData.mapData.MAX_TRAPS;
    int countTraps = 0;
    auto &traps = gameData.mapData.traps;
    Trap trap;

    for (int i = room.y; i < room.y + room.height; i++)
    {
        for (int j = room.x; j < room.x + room.width; j++)
        {
            if ((rand() % 10 > 8) && world[i][j] == FLOOR && countTraps < MAX_TRAPS)
            {
                world[i][j] = TRAP;

                Trap trap = Trap();
                trap.init(i, j);

                traps[countTraps++] = trap;
            }
        }
    }
}