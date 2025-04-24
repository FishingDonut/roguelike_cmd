#include <conio.h>

#include "../stateMachine.h"
#include "../GameData.h"
#include "include/playing/input.h"
#include "tools/debugMatriz.h"

namespace Playing
{
    void handle_input()
    {
        HANDLE hConsole = gameData.hConsole;
        COORD &newPosition = gameData.player.newPosition;
        int (&map)[height][width] = gameData.mapData.world;

        int keyBoard = getch();

        switch (keyBoard)
        {
        case 27:
            nextState = STATE_PAUSED;
            break;
        case 102:
            printMatriz(hConsole, gameData.mapData.explored);
            break;
        case 13:
            printMatriz(hConsole, gameData.screenBuffer);
            break;
        case 113:
        case 81:
            nextState = STATE_GAME_OVER;
            break;
        case 119:
            newPosition.Y > 0 ? newPosition.Y-- : 0;
            break;
        case 115:
            newPosition.Y < height - 1 ? newPosition.Y++ : 0;
            break;
        case 97:
            newPosition.X > 0 ? newPosition.X-- : 0;
            break;
        case 100:
            newPosition.X < width - 1 ? newPosition.X++ : 0;
            break;
        default:
            cout << keyBoard << endl;
            break;
        }
    }
}