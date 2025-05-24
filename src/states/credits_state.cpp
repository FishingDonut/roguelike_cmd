#include <iostream>
#include <windows.h>
#include <conio.h>

#include "file_manager/score/score_manager.h"
#include "file_manager/score/score_in.h"
#include "states/credits_state.h"
#include "core/map_value_to_char.h"
#include "core/render.h"
#include "state_machine.h"
#include "game_data.h"

extern StateMachine nextState;
extern bool stateChanged;

void credits_enter()
{
    HANDLE hConsole = gameData.hConsole;
    system("cls");
    drawMargin(hConsole);
    int centerY = height / 2;
    int centerX = width / 2;

    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(centerX - 11), (SHORT)(centerY - 2)});
    std::cout << "Parabens voce ganhou!";
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(centerX - 5), (SHORT)(centerY - 1)});
    std::cout << "score: " << gameData.score;
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(centerX - 5), (SHORT)(centerY)});
    Sleep(1);
    std::cout << "kills: " << gameData.status.kills;
    getch();

    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(centerX - 10), (SHORT)(centerY - 2)});
    std::cout << "                     ";
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(centerX - 4), (SHORT)(centerY - 1)});
    std::cout << "                   " << gameData.score;
    SetConsoleCursorPosition(gameData.hConsole, {(SHORT)(centerX - 4), (SHORT)(centerY)});
    Sleep(1);
    std::cout << "            " << gameData.status.kills;

    print_centered(centerY, "[ Insira o nome no placar ]");
    capture_player_name(centerY + 2);

    system("cls");
    scoreManager(gameData.score, gameData.player.name);
    show_scoreboard();

    getch();
    gameData.running = false;
    return;
}

void credits_update()
{
    return;
}

void credits_exit()
{
    return;
}