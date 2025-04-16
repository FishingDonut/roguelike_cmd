#include <conio.h>
#include <locale.h>
#include <iostream>
#include <windows.h>
#include "global.h"
#include "entity/player.h"
#include "tools/getCharAtPosition.h"
#include "tools/debugMatriz.h"
#include "core/update.h"

using namespace std;

int update(HANDLE hConsole, COORD &newPosition, Player &player, int (&map)[height][width], int currentObjPosition)
{
    COORD currentPosition = newPosition;

    int keyBoard = getch();

    if (keyBoard)
    {
        switch (keyBoard)
        {
        case 102:
            printMatriz(hConsole, map);
            break;
        case 113:
        case 81:
            system("cls");
            SetConsoleCursorPosition(hConsole, player.position);
            cout << "✞" << endl;
            return 2;
            break;
        case 119:
            newPosition.Y > 0 ? newPosition.Y-- : newPosition.Y;
            break;
        case 115:
            newPosition.Y < height - 1
                ? newPosition.Y++
                : newPosition.Y;
            break;
        case 97:
            newPosition.X > 0 ? newPosition.X-- : newPosition.X;
            break;
        case 100:
            newPosition.X < width - 1 ? newPosition.X++ : newPosition.X;
            break;
        default:
            cout << keyBoard << endl;
            break;
        }

        SetConsoleCursorPosition(hConsole, {0, 0});
        cout << getCharAtPosition(hConsole, newPosition);

        currentObjPosition = map[newPosition.Y][newPosition.X];
        player.setPosition(newPosition.X, newPosition.Y);

        SetConsoleCursorPosition(hConsole, {currentPosition});

        map[currentPosition.Y][currentPosition.X] = currentObjPosition;

        cout << currentObjPosition;

        SetConsoleCursorPosition(hConsole, {player.position});

        cout << player.skin;

        map[player.position.Y][player.position.X] = player.valueMap;
        return 0;
    }
}