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
    game.player = Player();
    int selectMenu;
    game.returnType = Game::start;
    do
    {
        if (game.returnType == Game::inventory){
                ItemsMenu();
                cout<<game.returnType;
                game.returnType = Game::saved;
        }else if (game.returnType == Game::exit)
        {
           game.returnType = Game::start;
        }
        
        selectMenu = menu();
        switch (selectMenu)
        {
        case 0:
            loopPlayer(game);
            
            break;
            case 1: // Info selected
            // info(); // Call info screen function if you have one
            system("cls");
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0,0});
            cout << "Game Information:\n";
            cout << "- Use W, A, S, D to move.\n";
            cout << "- Press SPACEBAR to attack adjacent enemies.\n";
            cout << "- Press TAB to open inventory (not fully implemented).\n";
            cout << "- Press Q to quit.\n";
            cout << "- '@' is you.\n";
            cout << "- '!' is an enemy.\n";
            cout << "- '\u00A4' is a chest (or mimic!).\n";
            cout << "- '\u2588' is a wall.\n";
            cout << "- '|' and '-' are doors.\n\n";
            cout << "Press any key to return to menu...";
            getch(); // Wait for key press
            break; // Break from switch case 1

        }
    } while (selectMenu != 2);
    system("cls");
    return 0;
}