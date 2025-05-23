#pragma once

#include <windows.h>
#include <string>
#include "global.h"

void drawMap(HANDLE &hConsole, int matriz[height][width]);
void drawMargin(HANDLE &hConsole);
void print_centered(short y, const std::string &text);
void show_scoreboard();
void capture_player_name(short y);