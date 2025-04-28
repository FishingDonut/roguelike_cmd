#pragma once

#include "GameData.h"
#include "global.h"

void connectRoom(Room (&rooms)[gameData.mapData.MAX_ROOMS], int (&map)[height][width]);