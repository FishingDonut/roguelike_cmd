#include <windows.h>

#include "include/stateMachine.h"
#include "include/GameData.h"
#include "include/core/mapValueToChar.h"
#include "include/playing/render.h"
#include "include/tools/getCharAtPosition.h"

void render_frame()
{
    HANDLE hConsole = gameData.hConsole;
    Player &player = gameData.player;
    COORD &newPos = gameData.player.newPosition;
    COORD &oldPos = gameData.player.oldPosition;
    int &previousObject = gameData.mapData.previousObject;

    // SetConsoleCursorPosition(hConsole, {0, 0});
    // cout << getCharAtPosition(hConsole, newPos);

    SetConsoleCursorPosition(hConsole, {oldPos});
    cout << mapValueToChar(previousObject);

    SetConsoleCursorPosition(hConsole, {player.position});
    cout << player.skin;
}