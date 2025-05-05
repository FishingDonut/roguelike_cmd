#pragma once

#include "game_data.h"
#include "global.h"

void connectRoom(Room (&rooms)[gameData.mapData.MAX_ROOMS], int (&map)[height][width]);