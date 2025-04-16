#include <conio.h>
#include <locale.h>
#include <iostream>
#include <windows.h>
#include "global.h"
#include "entity/player.h"
#include "tools/getCharAtPosition.h"
#include "tools/debugMatriz.h"
#include "core/update.h"
#include "GameData.h"

using namespace std;

GameData gameData;

int update()
{
    HANDLE hConsole = gameData.hConsole;
    Player &player = gameData.player;
    COORD &newPosition = gameData.player.newPosition;
    COORD currentPosition = newPosition;
    int (&map)[height][width] = gameData.mapData.mapAll;
    int &nearbyObject = gameData.mapData.nearbyObject;
    int &previousObject = gameData.mapData.previousObject;

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

        // atualiza matriz
        map[newPosition.Y][newPosition.X] != 2 ? nearbyObject = map[newPosition.Y][newPosition.X] : nearbyObject = previousObject; // pega obg futuro
        player.setPosition(newPosition.X, newPosition.Y);                                                                          // atualiza a posição player
        map[currentPosition.Y][currentPosition.X] = previousObject;                                                                // atualiza a posição antiga do player colocando obj pertencente.
        map[player.position.Y][player.position.X] = player.valueMap;                                                               // atualiza a posição player na matriz
        // se nao colocasse o player na matriz nao presisaria ter que salvar os obj em variaveis;

        // renderiza
        SetConsoleCursorPosition(hConsole, {0, 0});
        cout << getCharAtPosition(hConsole, newPosition);

        SetConsoleCursorPosition(hConsole, {currentPosition});
        cout << previousObject;

        SetConsoleCursorPosition(hConsole, {player.position});
        cout << player.skin;

        previousObject = nearbyObject;
        return 0;
    }
}