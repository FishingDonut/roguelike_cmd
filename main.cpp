// libs
#include <conio.h>
#include <locale.h>
#include <iostream>
#include <windows.h>
// person libs
#include "global.h"
#include "./include/core/init.h"
#include "./include/core/update.h"
#include "./include/entity/player.h"

using namespace std;

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD newPosition = {10, 10};
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    Player player = Player();

    int nearbyObject;
    int previousObject;

    system("cls");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    // matriz fixa
    int map[height][width];

    player.position = newPosition;

    init(hConsole, map);

    nearbyObject = map[player.position.X][player.position.Y];
    previousObject = nearbyObject;
    map[player.position.X][player.position.Y] = player.valueMap;

    while (player.health > 0)
    {
        if (update(hConsole, newPosition, player, map, nearbyObject, previousObject) == 2)
        {
            return 0;
        }
    }
    return 0;
}