#pragma once
#include "entity/player.h"

int update(HANDLE hConsole, COORD &newPosition, Player &player, int (&map)[height][width], int &currentObjPosition);