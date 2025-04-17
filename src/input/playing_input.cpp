#include <conio.h>

#include "../stateMachine.h"
#include "../GameData.h"
#include "include/input/playing_input.h"
#include "tools/debugMatriz.h"

void handle_input()
{
    HANDLE hConsole = gameData.hConsole;
    Player &player = gameData.player;
    COORD &newPosition = gameData.player.newPosition;
    int (&map)[height][width] = gameData.mapData.mapAll;

    int keyBoard = getch();

    switch (keyBoard)
    {
    case 27:
        nextState = STATE_PAUSED;
        break;
    case 102:
        printMatriz(hConsole, map);
        break;
    case 113:
    case 81:
        system("cls");
        SetConsoleCursorPosition(hConsole, player.position);
        cout << "✞" << endl;
        gameData.running = false;
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