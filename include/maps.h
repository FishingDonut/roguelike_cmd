#include "./map.h"
#include <ctime>

struct Seed
{
    int loc[5][5];
};
void generateSeed(Seed &seed)
{
    srand(time(NULL));

    for (short int i = 0; i < 5; i++)
    {
        for (short int j = 0; j < 5; j++)
        {
            if (i == 2 && j == 2)
            {
                seed.loc[i][j] = rand() % 4 + 1;
            }
            else
            {
                do
                {
                    seed.loc[i][j] = rand() % 13 + 1;
                } while (seed.loc[i][j] <= 4);
            }
        }
    }

    // for (short int i = 0; i < 5; i++){
    //     for (short int j = 0; j < 5; j++){
    //      cout<<seed[i][j]<<",";
    //     }
    //     cout<<endl;
    //  }
}

void definedMap(map &currentMap, int newMap[16][16])
{
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            currentMap.map[i][j] = newMap[i][j];
        }
    }
}

void printMap(map mapteste)
{

    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            if (rand() % 100 < 1 && mapteste.map[j][i] == 0)
            {
                mapteste.map[j][i] = mapteste.entities::enemy;
            }

            switch (mapteste.map[j][i])
            {
            // desenhando piso
            case 0:
                cout << " ";
                break;
            case mapteste.entities::parede:
                cout << "\u2588";
                break;
            case mapteste.entities::enemy:
                cout << "!";
                break;
            case mapteste.entities::portaLat:
                cout << "\u007C";
                break;
            case mapteste.entities::portaSupInf:
                cout << "-";
                break;
            case mapteste.entities::chest:
                cout << "\u00A4";
                break;
            case mapteste.entities::mimic:
                cout << "\u00A4";
                break;
            case mapteste.entities::vazio:
                cout << " ";
                break;
            case mapteste.entities::fakewall:
                cout << "\u2588";
                break;
            default:
                break;
            }
        }
        cout << endl;
    }
}

map newMap;
map mapa(int mapSelect)
{
    newMap.spawnPos[map::bottom] = {5, 5};
    newMap.enemy; // Inimigo = Número 2
    int inicial1[16][16] = {
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
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9}};

    int inicial2[16][16] = {
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
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9}};

    int inicial3[16][16] = {
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
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9}};

    int inicial4[16][16] = {
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
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9}};

    int SalaP1[16][16] = {
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
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9}};

    int SalaP2[16][16] = {
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
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9}};

    int SalaM1[16][16] = {
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
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9}};

    int SalaM2[16][16] = {
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
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9}};

    int SalaG1[16][16] = {
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
        {1, 1, 1, 1, 1, 1, 1, 91, 91, 1, 1, 1, 1, 1, 1, 1}};

    int SalaG2[16][16] = {
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
        {1, 1, 1, 1, 1, 1, 1, 91, 91, 1, 1, 1, 1, 1, 1, 1}};

    int SalaG3[16][16] = {
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
        {1, 1, 1, 1, 1, 1, 1, 91, 1, 1, 1, 1, 1, 1, 1, 1}};

    int SalaL1[16][16] = {
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
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9}};

    int SalaL2[16][16] = {
        {1, 1, 91, 1, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 9, 9, 9},
        {92, 0, 0, 0, 0, 0, 0, 1, 4, 1, 0, 0, 92, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 1, 9, 9, 9},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 9, 9, 9},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9}};

    int Template[16][16] = {
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
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9}};

    switch (mapSelect)
    {
    case 1:
        definedMap(newMap, inicial1);
        break;
    case 2:
        definedMap(newMap, inicial2);
        break;
    case 3:
        definedMap(newMap, inicial3);
    case 4:
        definedMap(newMap, inicial4);
        break;
    case 5:
        definedMap(newMap, SalaP1);
        break;
    case 6:
        definedMap(newMap, SalaP2);
        break;
    case 7:
        definedMap(newMap, SalaM1);
        break;
    case 8:
        definedMap(newMap, SalaM2);
        break;
    case 9:
        definedMap(newMap, SalaG1);
        break;
    case 10:
        definedMap(newMap, SalaG2);
        break;
    case 11:
        definedMap(newMap, SalaG3);
        break;
    case 12:
        definedMap(newMap, SalaL1);
        break;
    case 13:
        definedMap(newMap, SalaL2);
        break;
    default:
        break;
    }
    return newMap;
}