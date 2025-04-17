#include <windows.h>

#include "../stateMachine.h"
#include "../GameData.h"
#include "include/playing/update_logic.h"

void update_logic()
{
    Player &player = gameData.player;
    COORD &newPosition = gameData.player.newPosition;
    COORD &oldPosition = gameData.player.oldPosition;
    int (&map)[height][width] = gameData.mapData.mapAll;
    int &currentObject = gameData.mapData.currentObject;
    int &previousObject = gameData.mapData.previousObject;


    oldPosition = player.position;
    
    currentObject = map[newPosition.Y][newPosition.X];
    if(currentObject == 2){
        return;
    }

    player.setPosition(newPosition.X, newPosition.Y);                                                                           // atualiza a posição player
    map[oldPosition.Y][oldPosition.X] = previousObject;                                                                         // atualiza a posição antiga do player colocando obj pertencente.
    map[player.position.Y][player.position.X] = player.valueMap;                                                                // atualiza a posição player na matriz
    previousObject = currentObject;                                                                                              // atualiza o obj passado pegando o futuro que agora e passado;
    // se nao colocasse o player na matriz nao presisaria ter que salvar os obj em variaveis;
    return;
}