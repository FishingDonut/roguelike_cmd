#include"../include/map.h"
map newMap;
map mapa(){
    newMap.spawnPos[map::bottom] = {5,5};
    newMap.enemy; // Inimigo = Número 2
    int inicial1[16][16]={ 
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 9, 9, 9, 9, 9},
        {1, 4, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 1, 1, 1, 91, 91, 1, 1, 1, 1, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9}
    };
    int inicial2[16][16]={ 
        {1, 1, 1, 1, 91, 91, 1, 1, 1, 1, 9, 9, 9, 9, 9, 9},
        {1, 4, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 1, 1, 1, 91, 91, 1, 1, 1, 1, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9}
    };
    int inicial3[16][16]={ 
        {1, 1, 1, 1, 91, 91, 1, 1, 1, 1, 9, 9, 9, 9, 9, 9},
        {1, 4, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {92, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {92, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 1, 1, 1, 91, 91, 1, 1, 1, 1, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9}
    };
    int inicial4[16][16]={ 
        {1, 1, 1, 1, 91, 91, 1, 1, 1, 1, 9, 9, 9, 9, 9, 9},
        {1, 4, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {92, 0, 0, 0, 0, 0, 0, 0, 0, 92, 9, 9, 9, 9, 9, 9},
        {92, 0, 0, 0, 0, 0, 0, 0, 0, 92, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 1, 1, 1, 91, 91, 1, 1, 1, 1, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9}
    };
    int SalaP1[16][16]={ 
        {1, 1, 1, 1, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {1, 1, 91, 1, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9}
    };
    int SalaP2[16][16]={ 
        {1, 1, 91, 1, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {1, 0, 4, 0, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {1, 1, 91, 1, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9}
    };
    int SalaM1[16][16]={ 
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 1, 1, 1, 91, 91, 1, 1, 1, 1, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9}
    };
    int SalaM2[16][16]={ 
        {1, 1, 1, 1, 91, 91, 1, 1, 1, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 4, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9},
        {1, 1, 1, 1, 91, 91, 1, 1, 1, 1, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9}
    };                
    int SalaG1[16][16]={ 
        {1, 1, 1, 1, 1, 1, 1, 91, 91, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {92, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 92},
        {92, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 92},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 91, 91, 1, 1, 1, 1, 1, 1, 1}
    };
    int SalaG2[16][16]={ 
        {1, 1, 1, 1, 1, 1, 1, 91, 91, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 4, 1},
        {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {92, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 92},
        {92, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 92},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
        {1, 0, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 1},
        {1, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 91, 91, 1, 1, 1, 1, 1, 1, 1}
    };
    int SalaG3[16][16]={ 
        {1, 1, 1, 1, 1, 1, 1, 91, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 4, 1},
        {1, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 2, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 2, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
        {1, 0, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 1},
        {1, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 91, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    int SalaL1[16][16]={ 
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9},
        {1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 92, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 9, 9, 9},
        {1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 9, 9},
        {1, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {1, 0, 1, 0, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {1, 1, 91, 1, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9}
    };
    int SalaL2[16][16]={ 
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 1, 1, 91, 1, 1},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 1, 0, 0, 0, 1},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 1, 0, 0, 0, 1},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 1, 0, 0, 0, 1},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 1, 0, 0, 0, 1},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 1, 0, 0, 0, 1},
        {9, 9, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1},
        {9, 9, 9, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {9, 9, 9, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {9, 9, 9, 92, 0, 0, 0, 1, 4, 1, 0, 0, 0, 0, 0, 1},
        {9, 9, 9, 1, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 1},
        {9, 9, 9, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {9, 9, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9}
    };
    int Template[16][16]={ 
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9}
    };









    for (int i = 0; i < 16; i++){
        for (int j = 0; j < 16; j++){
<<<<<<< HEAD
            newMap.map[i][j] = SalaG3[i][j];
=======
            newMap.map[i][j] = SalaL1[i][j];
>>>>>>> 6d9fbb3ebeb7a7ac4f89bf7e8a8a3a278da0c348
        }
    }
    return newMap;
}