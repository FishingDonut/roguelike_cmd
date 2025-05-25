#include "global.h"
#include "game_data.h"

#include "entity/item.h"
#include "entity/room.h"
#include "map_construction/generate_item.h"

void generateItem(Room &newRoom, int (&map)[height][width])
{
    int MAX_ITENS = gameData.mapData.MAX_ITENS;
    int &countItens = gameData.mapData.countItens;

    int newPX;
    int newPY;

    for (int i = 0; i < MAX_ITENS; i++)
    {
        if ((rand() % 10) > 8 && countItens < MAX_ITENS)
        {
            do
            {
                newPX = newRoom.x + (rand() % newRoom.width);
                newPY = newRoom.y + (rand() % newRoom.height);
            } while (map[newPY][newPX] != FLOOR);

            Item item = ITEM_DATABASE[rand() % ITEM_DATABASE_SIZE];
            item.y = newPY;
            item.x = newPX;

            map[newPY][newPX] = ITEM;
            countItens++;
        }
    }
}