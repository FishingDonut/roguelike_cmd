#pragma once

#include "game_data.h"


void connectRoom(Room (&rooms)[gameData.mapData.MAX_ROOMS], int (&map)[gameData.height][gameData.width]);