#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include "core/render.h"
#include "core/map_value_to_char.h"
#include "global.h"
#include "game_data.h"
#include "file_manager/score/score_in.h"

void drawMap(HANDLE &hConsole, int matriz[height][width])
{
    char c;
    system("cls");
    for (short i = 0; i < height; ++i)
    {
        for (short j = 0; j < width; ++j)
        {
            SetConsoleCursorPosition(hConsole, {j, i});

            c = mapValueToChar(matriz[i][j]);

            std::cout << c;
        }
    }
    return;
}

void drawMargin(HANDLE &hConsole)
{
    for (short i = 0; i < height; ++i)
    {
        for (short j = 0; j < width; ++j)
        {
            SetConsoleCursorPosition(hConsole, {j, i});

            char c = ' ';
            if (j == 0 || j == width - 1)
            {
                c = '|';
                cout << c;
            }
            else if (i == 0 || i == height - 1)
            {
                c = '-';
                cout << c;
            }
        }
    }
    return;
}

void print_centered(short y, const std::string &text)
{
    COORD coord;
    coord.X = (SHORT)(width / 2 - text.length() / 2);
    coord.Y = y;
    SetConsoleCursorPosition(gameData.hConsole, coord);
    std::cout << text;
}

void show_scoreboard()
{
    system("cls");

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