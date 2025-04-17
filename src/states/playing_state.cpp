// C++
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <locale.h>

// Internos do projeto
#include "global.h"
#include "GameData.h"
#include "entity/player.h"
#include "tools/getCharAtPosition.h"
#include "tools/debugMatriz.h"
#include "core/update.h"
#include "core/render.h"
#include "stateMachine.h"
#include "states/playing_state.h"
#include "input/playing_input.h"

void playing_enter()
{
    drawMap(gameData.hConsole, gameData.mapData.mapAll);
}

void playing_update()
{
    HANDLE hConsole = gameData.hConsole;
    Player &player = gameData.player;
    COORD &newPosition = gameData.player.newPosition;
    COORD currentPosition = newPosition;
    int (&map)[height][width] = gameData.mapData.mapAll;
    int &nearbyObject = gameData.mapData.nearbyObject;
    int &previousObject = gameData.mapData.previousObject;

    handle_input();

    // atualiza matriz
    map[newPosition.Y][newPosition.X] != 2 ? nearbyObject = map[newPosition.Y][newPosition.X] : nearbyObject = previousObject; // pega obg futuro
    player.setPosition(newPosition.X, newPosition.Y);                                                                          // atualiza a posição player
    map[currentPosition.Y][currentPosition.X] = previousObject;                                                                // atualiza a posição antiga do player colocando obj pertencente.
    map[player.position.Y][player.position.X] = player.valueMap;                                                               // atualiza a posição player na matriz
    // se nao colocasse o player na matriz nao presisaria ter que salvar os obj em variaveis;

    // renderiza
    SetConsoleCursorPosition(hConsole, {0, 0});
    cout << getCharAtPosition(hConsole, newPosition);

    SetConsoleCursorPosition(hConsole, {currentPosition});
    cout << previousObject;

    SetConsoleCursorPosition(hConsole, {player.position});
    cout << player.skin;

    previousObject = nearbyObject;
    return;
}

void playing_exit()
{
    return;
}