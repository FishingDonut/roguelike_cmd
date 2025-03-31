#include <iostream>
#include <conio.h>
#include <windows.h>
#include "./include/menu.h"
#include "./include/itemsmenu.h"
#include "./include/maps.h"
#include "./include/player.h"
#include <locale.h>
using namespace std;
int key;
int main()
{
    SetConsoleTitle("RogueLike Game");
    system("cls");
    setlocale(LC_ALL, "pt_BR.UTF-8");
    CONSOLE_SCREEN_BUFFER_INFO windowSize;
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    ItemsMenu();
    system("cls");
    GetConsoleScreenBufferInfo(out, &windowSize);
    SetConsoleCursorPosition(out, {0, 0});
    int loaded = 0;
    map mapteste = mapa();
    for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            cout << mapteste.map[j][i];
            switch (mapteste.map[j][i])
            {
            case mapteste.entities::parede:
                cout << char(219);
                break;
            case mapteste.entities::enemy:
                cout << "!";
                break;

            default:
                break;
            }
        }
        cout << endl;
    }
    if (windowSize.dwSize.X < 145)
    {
        SetConsoleTitle("Please Resize Game");
        cout << "Waiting you resize window please place in fullscreen";
        do
        {
            GetConsoleScreenBufferInfo(out, &windowSize);
            if (loaded >= 4)
            {
                loaded = 0;
            }
            else
            {
                loaded++;
            }
            SetConsoleCursorPosition(out, {52, 0});
            for (int i = 0; i < loaded; i++)
            {
                cout << ".";
            }
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {52, 0});
            cout << "     ";
        } while (windowSize.dwSize.X < 145);
    }
    // cout<<windowSize.dwSize.X;

    if (menu() == 0)
    {
        system("cls");
        setlocale(LC_ALL, "pt_BR.UTF-8");
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD currentPosition = {0, 0};
        COORD newPosition = {0, 0};
        Player player = Player();
        player.position = newPosition;

        while (true)
        {
            currentPosition = newPosition;
            int a = getch();

            if (a)
            {
                switch (a)
                {
                case 81:
                    cout << "Saida!" << endl;
                    return 0;
                    break;
                case 119:
                    newPosition.Y > 0 ? newPosition.Y-- : newPosition.Y;
                    break;
                case 115:
                    newPosition.Y++;
                    break;
                case 97:
                    newPosition.X > 0 ? newPosition.X-- : newPosition.X;
                    break;
                case 100:
                    newPosition.X++;
                    break;
                default:
                    cout << a << endl;
                    break;
                }

                SetConsoleCursorPosition(hConsole, {0, 32});
                cout << getCharAtPosition(hConsole, newPosition);

                if (getCharAtPosition(hConsole, newPosition) == '0')
                {
                    newPosition = currentPosition;
                }

                player.setPosition(newPosition.X, newPosition.Y);
                SetConsoleCursorPosition(hConsole, currentPosition);
                cout << " ";
                SetConsoleCursorPosition(hConsole, player.getPosition());
                cout << "@";
            }
        }
        return 0;
    }
    if (menu() == 2)
    {
        system("cls");
        return 0;
    }
}