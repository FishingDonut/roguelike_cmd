#pragma once

#include "include/entity/room.h"

const int maxRoom = 4;

void clearMap(int (&map)[height][width]);

bool isCollind(Room rooms[maxRoom], int &roomCount, Room &newRoom);

void createRoom(Room &newRoom, int (&map)[height][width]);

void generateEnemy(Room &newRoom, int (&map)[height][width]);

void connectRoom(Room (&rooms)[maxRoom], int (&map)[height][width]);

void printMap(int (&map)[height][width]);

int generate_rooms();