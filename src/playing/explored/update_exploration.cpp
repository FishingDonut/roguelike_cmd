#include <windows.h>

#include "playing/explored/update_exploration.h"
#include "include/stateMachine.h"
#include "include/GameData.h"

void updateExploration()
{
    COORD &positionP = gameData.player.position;
    int &radius = gameData.player.VISION_RADIUS;
    auto &explored = gameData.mapData.explored;

    for (int dy = (radius + 2) * -1; dy <= (radius + 2); dy++)
    {
        for (int dx = (radius + 2) * -1; dx <= (radius + 2); dx++)
        {
            int y = positionP.Y + dy;
            int x = positionP.X + dx;
            int dist = dx * dx + dy * dy;

            if (x >= 0 && x < width &&
                y >= 0 && y < height)
            {
                if (dist >= (radius) * (radius)) //hide flov
                {
                    explored[y][x] = 1;
                }
                if (dist <= (radius + 1) * (radius + 1)) //clear flov
                {
                    explored[y][x] = 2;
                }
                if (dist <= radius * radius) //view flov
                {
                    explored[y][x] = 0;
                }
            }
        }
    }

    return;
}
