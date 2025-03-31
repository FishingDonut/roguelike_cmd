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

void drawnMap(HANDLE &hConsole, int width, int height)
{
    for (short i = 0; i < width; ++i)
    {
        for (short j = 0; j < height; ++j)
        {
            if(i == 0 || i == width -1 || j == 0 || j == height -1){
                SetConsoleCursorPosition(hConsole, {i, j});
                cout << ".";
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
    
    system("cls");
    SetConsoleOutputCP(CP_UTF8); // Definindo o console para usar caracteres UTF-8 (SAÍDA)
    SetConsoleCP(CP_UTF8);       // Definindo o console para usar caracteres UTF-8 (ENTRADA)
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    
    int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    
    player.position = newPosition;

    drawnMap(hConsole, width, height);

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
                newPosition.Y < height-1
                 ? newPosition.Y++ : newPosition.Y;
                break;
            case 97:
                newPosition.X > 0 ? newPosition.X-- : newPosition.X;
                break;
            case 100:
                newPosition.X < width-1 ? newPosition.X++ : newPosition.X;
                break;
            default:
                cout << keyBoard << endl;
                break;
            }

            SetConsoleCursorPosition(hConsole, {0, 0});
            cout << getCharAtPosition(hConsole, newPosition);

            if (getCharAtPosition(hConsole, newPosition) != ' ')
            {
                // newPosition = currentPosition;
            }

            player.setPosition(newPosition.X, newPosition.Y);
            SetConsoleCursorPosition(hConsole, currentPosition);
            cout << " ";
            SetConsoleCursorPosition(hConsole, player.position);
            cout << "@";
        }
    }
    return 0;
}