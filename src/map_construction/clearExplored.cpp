#include "global.h"
#include "map_construction/clearExplored.h"

void clearExplored(int (&explored)[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            explored[i][j] = 1;
        }
    }
    return;
}