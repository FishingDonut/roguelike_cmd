#include <iostream>
#include <conio.h>
#include <windows.h>
#include "./include/player.h"
#include <locale.h>

using namespace std;

char getCharAtPosition(HANDLE hConsole, COORD position)
{
    char c;
    DWORD read;
    ReadConsoleOutputCharacterA(hConsole, &c, 1, position, &read);
    return c;
}

void assembleMap(HANDLE &hConsole, int width, int height, int **matriz)
{
    for (short i = 0; i < width; ++i)
    {
        for (short j = 0; j < height; ++j)
        {
            matriz[i][j] = 0;

            if (i == 0 || i == width - 1 || j == 0 || j == height - 1)
            {
                SetConsoleCursorPosition(hConsole, {i, j});
                cout << ".";
                matriz[i][j] = 1;
            }
        }
    }
}

void drawnMap(HANDLE &hConsole, int width, int height, int **matriz)
{
    system("cls");
    for (short i = 0; i < width; ++i)
    {
        for (short j = 0; j < height; ++j)
        {
            SetConsoleCursorPosition(hConsole, {i, j});
            switch (matriz[i][j])
            {
            case 0:
                cout << " ";
                break;
            case 1:
                cout << "-";
            case 2:
                cout << "@";
                break;
            default:
                cout << "?";
                break;
            }
        }
    }
}
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

    int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    // Alocação dinâmica de matriz
    int **map = new int *[width];
    for (int i = 0; i < width; i++)
        map[i] = new int[height];

    player.position = newPosition;

    assembleMap(hConsole, width, height, map);
    drawnMap(hConsole, width, height, map);

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
            case 81:
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