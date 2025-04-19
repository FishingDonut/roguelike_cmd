#pragma once

#include "include/entity/room.h"
#include "GameData.h"

void clearMap(int (&map)[height][width]);

Room generateRandomRoom(int mapHeight, int mapWidth, int min, int max, int border);

bool isCollind(Room rooms[gameData.mapData.maxRooms], int &roomCount, Room &newRoom);

void createRoom(Room &newRoom, int (&map)[height][width]);

void generateEnemy(Room &newRoom, int (&map)[height][width]);

void connectRoom(Room (&rooms)[gameData.mapData.maxRooms], int (&map)[height][width]);

void printMap(int (&map)[height][width]);

int generate_rooms();