#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>

using namespace std;

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
                break;
            default:
                cout << "?";
                break;
            }
        }
    }
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
                std::cout << ".";
                matriz[i][j] = 1;
            }
        }
    }
}

// void drawnScore(HANDLE &hConsole, int width, int height, int **matriz, Game gameSaved){
//     SetConsoleCursorPosition(hConsole, {(SHORT)(width / 2), (SHORT)((height / 2) + 0)});
//     cout << gameSaved.player.health;
// }

// void printEndGamre(Game gameSaved)
void printEndGamre()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    system("cls");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int height = csbi.srWindow.Bottom - csbi.srWindow.Top;

    // Alocação dinâmica de matriz
    int **map = new int *[width];
    for (int i = 0; i < width; i++)
    {
        map[i] = new int[height];
    }

    assembleMap(hConsole, width, height, map);
    drawnMap(hConsole, width, height, map);
    // drawnScore(hConsole, width, height, map, gameSaved);
};