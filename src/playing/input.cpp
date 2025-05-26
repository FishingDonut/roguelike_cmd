#include <conio.h>

#include "../state_machine.h"
#include "../game_data.h"
#include "include/playing/input.h"
#include "include/playing/player/time_player.h"
#include "tools/debug_matriz.h"
#include "entity/item.h"

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
            gameData.player.moveOn = false;
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
        else if (keyBoard == 'I' || keyBoard == 'i')
        {
            auto &player = gameData.player;
            auto &item = player.inventory;

            std::cout << item.name;

            switch (item.itemType)
            {
            case POT_NONE:
                break;

            case POT_HP:
                player.updateHealth(item.value);
                item.empty();
                break;

            case POT_XP:
                player.xp += item.value;
                item.empty();
                break;

            case POT_SPEED:
                player.delay -= item.value;
                item.empty();
                break;

            case POT_MONEY:
                player.gold += item.value;
                item.empty();
                break;

            case POT_DIST:
                player.attackDistance += item.value;
                item.empty();
                break;

            case POT_KILL:
            {
                const int MAX_ROOMS = gameData.mapData.MAX_ROOMS;
                Room(&rooms)[MAX_ROOMS] = gameData.mapData.rooms;

                for (int j = 0; j < MAX_ROOMS; j++)
                {
                    Room &room = rooms[j];
                    if (room.isInRoom(player.position))
                    {
                        for (int i = 0; i < room.enemyCount; i++)
                        {
                            Enemy &enemy = room.enemies[i];
                            enemy.updateHealth(-enemy.health * 2);
                        }
                        break;
                    }
                }
                item.empty();
                break;
            }

            case POT_TRAP:
                // if (gameData.mapData.countTraps < gameData.mapData.MAX_TRAPS)
                // {
                //     player.currentObject = TRAP;
                //     gameData.mapData.traps[gameData.mapData.countTraps++] = Trap({{gameData.player.oldPosition}});
                //     item.empty();
                // }
                // else
                // {
                //     player.currentObject = TRAP;
                //     gameData.mapData.traps[0] = Trap({{gameData.player.oldPosition}});
                //     item.empty();
                // }
                break;

            case NONE:
                break;

            default:
                break;
            }
        }
        else if (keyBoard == 32) // attack
        {
            gameData.player.isAttackUpdate = true;
            gameData.player.isAttackFrame = true;
        }
        else if (keyBoard == config.UP)
        {
            if (newPosition.Y > 0)
            {
                newPosition.Y--;
                gameData.player.moveOn = true;
            }
        }
        else if (keyBoard == config.DOWN)
        {
            if (newPosition.Y < height - 1)
            {
                newPosition.Y++;
                gameData.player.moveOn = true;
            }
        }
        else if (keyBoard == config.LEFT)
        {
            if (newPosition.X > 0)
            {
                newPosition.X--;
                gameData.player.moveOn = true;
            }
        }
        else if (keyBoard == config.RIGHT)
        {
            if (newPosition.X < width - 1)
            {
                newPosition.X++;
                gameData.player.moveOn = true;
            }
        }
        else
        {
            SetConsoleCursorPosition(hConsole, {width / 2, 3});
            cout << keyBoard << endl;
        }
    }
}
