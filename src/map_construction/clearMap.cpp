#include "global.h"
#include "map_construction/clearMap.h"

void clearMap(int (&map)[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            map[i][j] = 1;
        }
    }
    return;
}