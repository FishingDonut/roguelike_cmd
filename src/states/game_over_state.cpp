#include <iostream>
#include <conio.h>
#include <cctype>
#include <windows.h>
#include <string.h>

#include "global.h"
#include "states/game_over_state.h"
#include "state_machine.h"
#include "game_data.h"
#include "core/color_char.h"
#include "file_manager/score/score_manager.h"
#include "file_manager/score/score_in.h"
#include "include/core/visual_length.h"

extern StateMachine nextState;
extern bool stateChanged;

void game_over_enter()
{
    COORD coord;
    coord.X = (SHORT)(width / 2) - 7;
    coord.Y = (SHORT)(height / 2);

    SetConsoleCursorPosition(gameData.hConsole, coord);
    std::cout << "[ GAME OVER ]";
    getch();
    system("cls");

    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(coord.X - 14), coord.Y});
    std::cout << "[ Insira o nome no placar ]";

    int c;
    auto &name = gameData.player.name;

    while (c != 13)
    {
        c = getch();
        SetConsoleCursorPosition(gameData.hConsole, {coord.X, (SHORT)(coord.Y + 2)});

        if (c == 8 && !name.empty())
        {
            name.pop_back();
            if (!name.empty())
            {
                cout << name << " ";
            }
            continue;
        }
        name += c;
        if (isprint(c))
        {
            cout << name;
        }
    }

    scoreManager(gameData.score, gameData.player.name);

    vector<string> scores;
    size_t i = 1;

    for (string score : scoreRead())
    {
        coord.Y = (SHORT)((height / 2) + i++);
        coord.X = (SHORT)((width / 2) - (score.length() / 2));
        SetConsoleCursorPosition(gameData.hConsole, coord);
        cout << score << endl;
    }

    getch();
    return;
}

void game_over_update()
{
    system("cls");
    SetConsoleCursorPosition(gameData.hConsole, gameData.player.position);
    cout << "✞" << colorChar(COLOR_GREEN) << gameData.seed << colorChar(COLOR_RESET) << endl;
    gameData.running = false;
    return;
}

void game_over_exit()
{
    return;
}