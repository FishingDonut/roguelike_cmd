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
                ItemsMenu(game.player.inventory,game.player);
                cout<<game.returnType;
                game.returnType = Game::saved;
        }else if (game.returnType == Game::exit)
        {
           game.returnType = Game::start;
        }
        game.returnType == Game::saved ? selectMenu = 0 : selectMenu = menu();
        switch (selectMenu)
        {
        case 0:
            loopPlayer(game);
            
            break;
            case 1: // "Informações" foi selecionadas
            system("cls");
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0,0});
            cout << "Game Information:\n";
            cout << "- Use W, A, S, D para se mover.\n";
            cout << "- Pressione ESPAÇO para dar um ataque em área.\n";
            cout << "- Pressione TAB para abrir o inventário.\n";
            cout << "- Pressione Q para sair do jogo.\n";
            cout << "- '@' é você.\n";
            cout << "- '!' são inimigos.\n";
            cout << "- '#' é armadilha.\n";
            cout << "- '\u00A4' é um baú (ou um mímico!).\n";
            cout << "- '\u2588' são paredes (você não pode passar delas).\n";
            cout << "- '|' e '-' são portas.\n\n";
            cout << "Objetivo: Sobreviva ao máximo de tempo possível (quanto mais tempo se passa dentro da dungeon, mais difícil fica), \n";
            cout << "mate o máximo de inimigos possíveis e derrote o Boss para conseguir a maior quantidade de pontos possível\n\n";
            cout << "Pressione qualquer tecla para retornar ao menu...";
            getch(); // Aguardando uma tecla ser pressionada
            break;

        }
    } while (selectMenu != 2);
    system("cls");
    return 0;
}