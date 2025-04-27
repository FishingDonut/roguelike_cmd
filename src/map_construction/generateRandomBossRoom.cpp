#include "map_construction/generateRandomBossRoom.h"
#include "entity/room.h"
#include "GameData.h"

Room generateRandomBossRoom(int mapHeight, int mapWidth, int border){
    int min = 10;
    int max = 30;

    Room room;
    room.exploredRoom = false;
    room.height = min + (rand() % (max - min + 1));
    room.width = min + (rand() % (max * 2 - min + 1));
    room.y = border + (rand() % (mapHeight - room.height - border * 2));
    room.x = border + (rand() % (mapWidth - room.width - border * 2));
    return room;
};