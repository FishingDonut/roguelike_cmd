#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>

#include "global.h"
#include "states/game_over_state.h"
#include "state_machine.h"
#include "game_data.h"
#include "core/color_char.h"
#include "file_manager/score/score_manager.h"
#include "file_manager/score/score_in.h"

extern StateMachine nextState;
extern bool stateChanged;

void game_over_enter()
{
    COORD coord;
    coord.X = (SHORT)(width / 2) - 7;
    coord.Y = (SHORT)(height / 2);

    SetConsoleCursorPosition(gameData.hConsole, coord);
    std::cout << "[ GAME OVER ]";

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