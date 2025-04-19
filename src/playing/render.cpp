#include <windows.h>

#include "include/stateMachine.h"
#include "include/GameData.h"
#include "include/core/mapValueToChar.h"
#include "include/playing/render.h"
#include "include/tools/getCharAtPosition.h"

void render_frame()
{
    const int maxRooms = gameData.mapData.maxRooms;

    HANDLE hConsole = gameData.hConsole;
    Player &player = gameData.player;
    Room(&rooms)[maxRooms] = gameData.mapData.rooms;

    // SetConsoleCursorPosition(hConsole, {0, 0});
    // cout << getCharAtPosition(hConsole, newPos);

    SetConsoleCursorPosition(hConsole, {player.oldPosition});
    cout << mapValueToChar(player.previousObject);
    
    for (int j = 0; j < maxRooms; j++)
    {
        Room &room = rooms[j];
        for (int i = 0; i < room.enemyCount; i++)
        {
            Enemy &enemy = room.enemies[i];
            SetConsoleCursorPosition(hConsole, {enemy.oldPosition});
            cout << mapValueToChar(enemy.previousObject);
            SetConsoleCursorPosition(hConsole, {enemy.position});
            cout << enemy.skin;
        }
    }

    SetConsoleCursorPosition(hConsole, {player.position});
    cout << player.skin;
}