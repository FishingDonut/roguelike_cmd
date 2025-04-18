#include <iostream>
#include <algorithm>
#include <windows.h>
#include <random>
#include <ctime>

const int h = 44;
const int w = 156;
const int maxRoom = 4;

void clearMap(int (&map)[h][w])
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            map[i][j] = 1;
        }
    }
    return;
}

void printMap(int (&map)[h][w])
{
    int c;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            c = map[i][j];
            switch (c)
            {
            case 0:
                std::cout << "Z";
                break;
            case 1:
                std::cout << " ";
                break;
            default:
                std::cout << "?";
                break;
            }
        }
    }
    return;
}

struct Room
{
    int x;
    int y;
    int h;
    int w;

    bool connect = false;

    int centerX() { return x + w / 2; }
    int centerY() { return y + h / 2; }
};

void connectRoom(Room (&rooms)[maxRoom], int (&map)[h][w])
{
    Room room, nearest;

    for (int i = 0; i < maxRoom; i++)
    {
        room = rooms[i];
        nearest = rooms[i];
        for (int j = i + 1; j < maxRoom; j++)
        {
            if (!rooms[j].connect)
            {
                nearest = rooms[j];
            }
        }

        if (room.connect)
        {
            return;
        }

        nearest.connect = true;

        int ax = room.centerX();
        int bx = nearest.centerX();

        int ay = room.centerY();
        int by = nearest.centerY();

        if (rand() % 2)
        {
            for (int x = std::min(ax, bx); x <= std::max(ax, bx); x++)
            {
                map[ay][x] = 0;
            }
            for (int y = std::min(ay, by); y <= std::max(ay, by); y++)
            {
                map[y][bx] = 0;
            }
        }
        else
        {
            for (int x = std::min(ax, bx); x <= std::max(ax, bx); x++)
            {
                map[by][x] = 0;
            }
            for (int y = std::min(ay, by); y <= std::max(ay, by); y++)
            {
                map[y][ax] = 0;
            }
        }
    }
    return;
}

void createRoom(Room newRoom, int (&map)[h][w])
{
    for (int i = newRoom.y; i < newRoom.y + newRoom.h; i++)
    {
        for (int j = newRoom.x; j < newRoom.x + newRoom.w; j++)
        {
            map[i][j] = 0;
        }
    }
}

bool isCollind(Room rooms[maxRoom], int roomCount, Room newRoom)
{
    Room otherRoom;

    for (int i = 0; i < roomCount; i++)
    {
        otherRoom = rooms[i];
        if (newRoom.x < otherRoom.x + otherRoom.w &&
            newRoom.x + newRoom.w > otherRoom.x &&
            newRoom.y < otherRoom.y + otherRoom.h &&
            newRoom.y + newRoom.h > otherRoom.y)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    system("cls");
    srand(time(0));

    int map[h][w];
    Room listRoom[maxRoom];
    int coutRoom = 0;
    int min = 5;
    int max = 20;

    clearMap(map);

    for (int i = 0; i < maxRoom; i++)
    {
        Room room;

        room.h = min + (rand() % (max - min + 1));
        room.w = min + (rand() % (max - min + 1));

        room.y = (rand() % (h - room.h - 1));
        room.x = (rand() % (w - room.w - 1));

        if (isCollind(listRoom, coutRoom, room))
        {
            i--;
            continue;
        }

        createRoom(room, map);
        listRoom[coutRoom++] = room;
    }
    connectRoom(listRoom, map);

    printMap(map);
    return 0;
}
