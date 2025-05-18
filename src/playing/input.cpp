#include "BearLibTerminal.h"

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
        COORD &newPosition = gameData.player.newPosition;
        int (&map)[gameData.height][gameData.width] = gameData.mapData.world;
        int keyBoard;

        time_player(gameData.player);

        if (!terminal_has_input() || !gameData.player.IsUpdate)
        {
            return;
        }

        while (terminal_has_input())
        {
            keyBoard = terminal_read();
        }
        

        if (keyBoard == TK_ESCAPE) // ESC
        {
            nextState = STATE_PAUSED;
        }
        else if (keyBoard == 'f') // debug matriz
        {
            printMatriz(map);
        }
        else if (keyBoard == TK_Q || keyBoard == TK_CLOSE) // sair
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
            if (newPosition.Y < gameData.height - 1)
                newPosition.Y++;
        }
        else if (keyBoard == config.LEFT)
        {
            if (newPosition.X > 0)
                newPosition.X--;
        }
        else if (keyBoard == config.RIGHT)
        {
            if (newPosition.X < gameData.width - 1)
                newPosition.X++;
        }
        else
        {
            terminal_printf(gameData.width / 2, 3, "Key: %d", keyBoard);
        }
    }
}
