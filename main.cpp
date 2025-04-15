//libs
#include <conio.h>
#include <locale.h>
#include <iostream>
#include <windows.h>
// person libs
#include "global.h"
#include "./include/entity/player.h"
#include "./include/tools/drawnMap.h"
#include "./include/tools/assembleMap.h"
#include "./include/tools/getCharAtPosition.h"

using namespace std;

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD currentPosition = {0, 0};
    COORD newPosition = {10, 10};
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    Player player = Player();

    int currentObjPosition;

    system("cls");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    
    // matriz fixa
    int map[height][width];

    player.position = newPosition;
    
    assembleMap(hConsole, map);
    drawnMap(hConsole, map);
    
    currentObjPosition = map[player.position.X][player.position.Y];
    map[player.position.X][player.position.Y] = 2;

    while (player.health > 0)
    {
        currentPosition = newPosition;
        int keyBoard = getch();
        
        if (keyBoard)
        {
            switch (keyBoard)
            {
                case 113:
                case 81:
                system("cls");
                SetConsoleCursorPosition(hConsole, player.position);
                cout << "✞" << endl;
                return 0;
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

            currentObjPosition = map[newPosition.X][newPosition.Y];
            player.setPosition(newPosition.X, newPosition.Y);

            SetConsoleCursorPosition(hConsole, {currentPosition});

            map[currentPosition.X][currentPosition.Y] = currentObjPosition;

            cout << currentObjPosition;

            SetConsoleCursorPosition(hConsole, {player.position});

            cout << "@";

            map[player.position.X][player.position.Y] = 2;
        }
    }
    return 0;
}