#include <windows.h>

#include "game_data.h"
#include "entity/item.h"
#include "core/search_item.h"

Item searchItem(COORD position)
{
    int countItens = gameData.mapData.countItens;
    auto &itens = gameData.mapData.itens;

    for (int i = 0; i < countItens; i++)
    {
        Item &trap = itens[i];
        if (position.Y == trap.y && position.X == trap.x)
        {
            return trap;
        }
    }

    Item item = Item();
    return item;
}