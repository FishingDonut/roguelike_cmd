#include <iostream>
#include <conio.h>
#include <cctype>
#include <windows.h>
#include <string.h>

#include "global.h"
#include "core/color_char.h"
#include "core/render.h"
#include "states/game_over_state.h"
#include "state_machine.h"
#include "game_data.h"
#include "file_manager/score/score_manager.h"
#include "file_manager/score/score_in.h"
#include "include/core/visual_length.h"
#include "BearLibTerminal.h"

extern StateMachine nextState;
extern bool stateChanged;

// Função utilitária para imprimir centralizado
void print_centered(short y, const std::string &text)
{
    COORD coord;
    coord.X = (SHORT)(width / 2 - text.length() / 2);
    coord.Y = y;
    SetConsoleCursorPosition(gameData.hConsole, coord);
    std::cout << text;
}

// Função para capturar nome do jogador
void capture_player_name(short y)
{
    auto &name = gameData.player.name;
    int c = 0;

    while (c != 13) // Enter
    {
        c = getch();

        if (c == 8 && !name.empty()) // Backspace
        {
            name.pop_back();
        }
        else if (isprint(c))
        {
            name += c;
        }

        COORD coord = {(SHORT)(width / 2 - name.length() / 2), y};
        SetConsoleCursorPosition(gameData.hConsole, coord);
        std::cout << " " << name << " ";
    }
}

// Função para exibir placar
void show_scoreboard()
{
    terminal_clear();

    std::vector<std::string> scores = scoreRead();
    short y = (SHORT)((height / 2) - (scores.size() / 2));
    size_t i = 1;

    for (const std::string &score : scores)
    {
        print_centered(y + i++, score);
    }

    drawMargin(gameData.hConsole);
    getch();
}

void game_over_enter()
{
    terminal_clear();
    short centerY = (SHORT)(height / 2);

    print_centered(centerY, "[ GAME OVER ]");
    getch();
    terminal_clear();

    print_centered(centerY, "[ Insira o nome no placar ]");
    capture_player_name(centerY + 2);

    terminal_clear();
    scoreManager(gameData.score, gameData.player.name);
    show_scoreboard();
}

void game_over_update()
{
    terminal_clear();
    SetConsoleCursorPosition(gameData.hConsole, gameData.player.position);
    std::cout << "✞" << colorChar(COLOR_GREEN) << gameData.seed << colorChar(COLOR_RESET) << std::endl;
    gameData.running = false;
}

void game_over_exit()
{
    // Nada a fazer aqui por enquanto
}
