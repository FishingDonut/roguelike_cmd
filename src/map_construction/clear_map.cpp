#include "global.h"
#include "tile_map_value.h"
#include "map_construction/clear_map.h"

void clearMap(int (&map)[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            map[i][j] = WALL;
        }
    }
    return;
}