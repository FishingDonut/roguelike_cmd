#pragma once

#include "GameData.h"
#include "global.h"

void connectRoom(Room (&rooms)[gameData.mapData.maxRooms], int (&map)[height][width]);