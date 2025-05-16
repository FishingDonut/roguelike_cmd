#include <conio.h>

#include "../state_machine.h"
#include "../game_data.h"
#include "include/playing/input.h"
#include "include/playing/player/time_player.h"
#include "tools/debug_matriz.h"

namespace Playing
{
    void handle_input()
    {
        Config config = gameData.config;
        HANDLE hConsole = gameData.hConsole;
        COORD &newPosition = gameData.player.newPosition;
        int (&map)[height][width] = gameData.mapData.world;
        int keyBoard;

        time_player(gameData.player);

        if (!kbhit() || !gameData.player.IsUpdate)
        {
            return;
        }

        while (kbhit())
        {
            keyBoard = getch();
        }
        

        if (keyBoard == 27) // ESC
        {
            nextState = STATE_PAUSED;
        }
        else if (keyBoard == 'f') // debug matriz
        {
            printMatriz(hConsole, map);
        }
        else if (keyBoard == 'q' || keyBoard == 'Q') // sair
        {
            nextState = STATE_GAME_OVER;
        }
        else if (keyBoard == 32) // attack
        {
            gameData.player.isAttackUpdate = true;
            gameData.player.isAttackFrame = true;
        }
        else if (keyBoard == config.UP)
        {
            if (newPosition.Y > 0)
                newPosition.Y--;
        }
        else if (keyBoard == config.DOWN)
        {
            if (newPosition.Y < height - 1)
                newPosition.Y++;
        }
        else if (keyBoard == config.LEFT)
        {
            if (newPosition.X > 0)
                newPosition.X--;
        }
        else if (keyBoard == config.RIGHT)
        {
            if (newPosition.X < width - 1)
                newPosition.X++;
        }
        else
        {
            SetConsoleCursorPosition(hConsole, {width / 2, 3});
            cout << keyBoard << endl;
        }
    }
}
