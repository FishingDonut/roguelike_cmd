#include"../include/map.h"
map newMap;
map mapa(){
    newMap.spawnPos[map::bottom] = {3,5};
    newMap.enemy; // Inimigo = Número 2
    int alea[10][10]={ 
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 2, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 2, 0, 0, 1},
    {1, 1, 1, 1, 99, 99, 1, 1, 1, 1}
    };
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            newMap.map[i][j] = alea[i][j];
        }
    }
    return newMap;
}