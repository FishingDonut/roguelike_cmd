#include "BearLibTerminal.h"

#include "include/game_data.h"
#include "include/core/map_value_to_char.h"
#include "include/core/color_char.h"
#include "include/playing/enemies/render_frame_enemy.h"

void render_frame_enemy()
{
    const int MAX_ROOMS = gameData.mapData.MAX_ROOMS;
    Room(&rooms)[MAX_ROOMS] = gameData.mapData.rooms;

    for (int j = 0; j < MAX_ROOMS; j++)
    {
        Room &room = rooms[j];
        for (int i = 0; i < room.enemyCount; i++)
        {
            Enemy &enemy = room.enemies[i];

            if (!enemy.alive || !enemy.IsUpdate)
            {
                continue;
            }

            terminal_put(enemy.oldPosition.X ,enemy.oldPosition.Y, mapValueToChar(enemy.previousObject));
            terminal_put(enemy.position.X ,enemy.position.Y, enemy.skin);
        }
    }
}