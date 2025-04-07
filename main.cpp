#include <iostream>
#include <conio.h>
#include <windows.h>
#include "./include/player.h"
#include "./include/menu.h"
#include "./include/itemsmenu.h"
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
    Game game;
    game.returnType = Game::exit;
    int selectMenu;
    do
    {
        selectMenu = menu();
        switch (selectMenu)
        {
        case 0:
            game = loopPlayer(game);
            if (game.returnType == Game::inventory)
            {
                ItemsMenu();
            }
            break;
        }
    } while (selectMenu != 2);
    system("cls");
    return 0;
}