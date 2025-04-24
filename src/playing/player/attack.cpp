#include <windows.h>

#include "../stateMachine.h"
#include "../GameData.h"
#include "include/playing/player/attack.h"

void attack()
{
    const int maxRooms = gameData.mapData.maxRooms;
    auto& player = gameData.player;
    auto& oldPosition = player.oldPosition;
    auto& position = gameData.player.position;
    auto& world = gameData.mapData.world;
    auto& rooms = gameData.mapData.rooms;


    for (int i = 1; i <= 3; i++)
    {
        SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(player.position.X + player.dirX * i), (SHORT)(player.position.Y + player.dirY * i)});
        cout << i;
    }

    return;
    for (int i = 0; i < maxRooms; i++)
    {
        auto& enemyCount = rooms[i].enemyCount;
        auto& enemies = rooms[i].enemies;

        if(enemyCount <= 0){
            continue;
        }

        for (int j = 0; j < enemyCount; j++)
        {
            auto& enemy = enemies[j];
        }
        
    }
    
}
