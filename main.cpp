#include <iostream>
#include <conio.h>
#include <windows.h>
#include "./include/menu.h"
#include "./include/itemsmenu.h"
#include "./include/maps.h"
#include <locale.h>

using namespace std;

int main()
{
    SetConsoleTitle("RogueLike Game");
    system("cls");
    SetConsoleOutputCP(CP_UTF8); // Definindo o console para usar caracteres UTF-8 (SAÍDA)
    SetConsoleCP(CP_UTF8);       // Definindo o console para usar caracteres UTF-8 (ENTRADA)
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
    
    for (int j = 0; j < 16; j++)
    {
        for (int i = 0; i < 16; i++)
        {
            switch (mapteste.map[j][i])
            {
                //desenhando piso
                case 0:
                    cout << " ";
                    break;
                case mapteste.entities::parede:
                    cout<< "\u2588";
                    break;
                case mapteste.entities::enemy:
                    cout << "!";
                    break;
                case mapteste.entities::portaLat:
                    cout << "\u007C";
                    break;
                case mapteste.entities::portaSupInf:
                    cout << "\u2014";
                    break;
                case mapteste.entities::chest:
                    cout << "\u00A4";
                    break;
                case mapteste.entities::mimic:
                    cout << "\u00A4";
                    break;
                case mapteste.entities::vazio:
                    cout << " ";
                    break;
                case mapteste.entities::fakewall:
                    cout << "\u2588";
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
        loopPlayer();
        return 0;
    }
    if (menu() == 2)
    {
        system("cls");
        return 0;
    }
}