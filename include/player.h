#include <iostream>
#include <conio.h>
#include "./maps.h"
#include "./items.h"
#include "./primitiveTypes.h"
#include <windows.h>

using namespace std;

struct Player
{
    COORD position;
    Inventory inventory;

    int health = 100;
    int shield = 100;
    void setPosition(int x, int y)
    {
        position.X = x;
        position.Y = y;
    }

    void setRelativePosition(int x, int y)
    {
        position.X += x;
        position.Y += y;
    }
};

char getCharAtPosition(HANDLE hConsole, COORD position)
{
    char c;
    DWORD read;
    ReadConsoleOutputCharacterA(hConsole, &c, 1, position, &read);
    return c;
}

void debugPrint(HANDLE hConsole, map mapCurrent, COORD newPosition, int a)
{
    // next char
    SetConsoleCursorPosition(hConsole, {(SHORT)22, (SHORT)22});
    cout << getCharAtPosition(hConsole, newPosition);

    // map value array
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            SetConsoleCursorPosition(hConsole, {(SHORT)j, (SHORT)i});
            if (mapCurrent.map[i][j] == 0)
            {
                cout << " ";
            }
            else
            {
                cout << mapCurrent.map[i][j];
            }
        }
    }

    // cordenada e value array map
    SetConsoleCursorPosition(hConsole, {(SHORT)20, (SHORT)20});
    cout << "row: " << newPosition.Y << " column: " << newPosition.X << " value: " << mapCurrent.map[newPosition.Y][newPosition.X];

    // value int key
    SetConsoleCursorPosition(hConsole, {(SHORT)21, (SHORT)21});
    cout << a << endl;
}

struct Game
{
    Player player;
    map map;
    Seed seed;
    enum ReturnTypes
    {
        exit,
        inventory,
    };
    ReturnTypes returnType;
};

void hudPrint(Player player){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole,{(SHORT)16,(SHORT)0});

    cout << "100 / "<< player.health << "     ";
    cout << "10 / "<< player.inventory.size << "  ";
    
}




Game loopPlayer(Game gameSaved)
{
    Seed seed;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    map mapCurrent;
    COORD newPosition;
    COORD currentPosition;
    Player player;
    Position inMap;

    setlocale(LC_ALL, "pt_BR.UTF-8");

    if (gameSaved.returnType != Game::exit)
    {
        mapCurrent = gameSaved.map;
        seed = gameSaved.seed;
        printMap(mapCurrent);
        currentPosition = {3, 3};
        newPosition = {3, 3};
        player = gameSaved.player;
        /*por algum motivo da bug se não setar o size manualmente*/
        player.inventory.size = 0;
        player.inventory.size = gameSaved.player.inventory.size;
    }
    else
    {
        generateSeed(seed);
        // selecionando a sala inicial
        mapCurrent = mapa(seed.loc[2][2]);
        // map mapCurrent = mapa(3);
        printMap(mapCurrent);
        currentPosition = {3, 3};
        newPosition = {3, 3};
        player = Player();
        player.inventory.size = 0;
        player.position = newPosition;
        inMap = {2, 2};
    }

    char playerChar = '@';
    bool swapMap;
    int a;

    while (player.health > 0)
    {
        currentPosition = newPosition;

        // kbhit() ? a = getch() : a = 0;
        
        a = getch();
        
        hudPrint(player);

        SetConsoleCursorPosition(hConsole, {0, 0});

        printMap(mapCurrent);
        updateMoveEnemies(mapCurrent, {player.position.X, player.position.Y}, hConsole);
        
        // if (swapMap){
        //     printMap(mapCurrent);
        //     swapMap = false;
        // }

        SetConsoleCursorPosition(hConsole, player.position);
        cout << playerChar;
        if (a)
        {
            switch (a)
            {
            case 0:
                break;
            case 81:
                SetConsoleCursorPosition(hConsole, player.position);
                cout << "✞" << endl;

                gameSaved.player = player;
                gameSaved.map = mapCurrent;
                gameSaved.seed = seed;
                gameSaved.returnType = Game::exit;
                return gameSaved;
                break;

            // start movimentação do player
            case 119:
                newPosition.Y > 0 ? newPosition.Y-- : newPosition.Y;
                break;
            case 115:
                newPosition.Y++;
                break;
            case 97:
                newPosition.X > 0 ? newPosition.X-- : newPosition.X;
                break;
            case 100:
                newPosition.X++;
                break;
                // end movimentação do player

            case 9:
                gameSaved.player = player;
                gameSaved.map = mapCurrent;
                gameSaved.seed = seed;
                gameSaved.returnType = Game::inventory;
                return gameSaved;
            default:
                    debugPrint(hConsole, mapCurrent, newPosition, a);
                break;
            }

            switch (mapCurrent.map[newPosition.Y][newPosition.X])
            {
            case mapCurrent.entities::portaSupInf:
                if (newPosition.Y > 0 && inMap.y < 4)
                {
                    /*logic to select next map on bottom*/
                    swapMap = true;
                    inMap.y++;
                    mapCurrent = mapa(seed.loc[inMap.y][inMap.x]);
                    newPosition = {2, 2};
                }
                else if (inMap.y > 1)
                {
                    /* return to before room if has in room 5S*/
                    swapMap = true;
                    inMap.y--;
                    mapCurrent = mapa(seed.loc[inMap.y][inMap.x]);
                    newPosition = {2, 2};
                }
                break;
            case mapCurrent.entities::portaLat:
                if (newPosition.X > 0 && inMap.x < 4)
                {
                    /*logic to select next map on right*/
                    swapMap = true;
                    inMap.x++;
                    mapCurrent = mapa(seed.loc[inMap.y][inMap.x]);
                    newPosition = {2, 2};
                }
                else if (inMap.x > 1)
                {
                    /* return to before room if has in room 5S*/
                    swapMap = true;
                    inMap.x--;
                    mapCurrent = mapa(seed.loc[inMap.y][inMap.x]);
                    newPosition = {2, 2};
                }
                break;
            case mapCurrent.entities::item:
                /*item*/
                break;
            case mapCurrent.entities::chest:
            {
                /*chest*/
                if (player.inventory.size == 10)
                {
                    SetConsoleCursorPosition(hConsole, {(SHORT)20, (SHORT)20});
                    cout << "Inventory full";
                    break;
                }
                else
                {
                    int itemSelect = rand() % 3 + 1;
                    switch (itemSelect)
                    {
                        case 1:
                        {
                            Items potion;
                            potion.type = Items::potion;
                            potion.art =
                                "   _\n"
                                "  |=|\n"
                                "  | |\n"
                                "  | |\n"
                                " /   \\\n"
                                ".     .\n"
                                "|-----|\n"
                                "|     |\n"
                                "|-----|\n";
                            potion.midX = 7 / 2;
                            potion.midY = 10;
                            player.inventory.items[player.inventory.size++] = potion;
                            break;
                        }
                        case 2:
                        {
                            /*weapons*/
                            Items sword;
                            sword.durability = 100;
                            sword.quantity = 1;
                            sword.type = Items::weapon;
                            sword.art = "      .         \n"
                                        "     /:\\    (\"\"\")\n"
                                        "     |:|     III\n"
                                        "     |:|     III\n"
                                        "     |:|     III\n"
                                        "     |:|   __III__\n"
                                        "     |:| /:-.___,-:\\\n"
                                        "     |:| \\]  |:|  [/\n"
                                        "     |:|     |:|\n"
                                        "     |:|     |:|\n"
                                        "     |:|     |:|\n"
                                        " /]  |:|  [\\ |:|\n"
                                        " \\:-'\"\"\"`-:/ |:|\n"
                                        "   \"\"III\"\"   |:|\n"
                                        "     III     |:|\n"
                                        "     III     |:|\n"
                                        "     III     |:|\n"
                                        "    (___)    \\:/\n"
                                        "              \"\n";
                            sword.midX = 16 / 2;
                            sword.midY = 19 / 2;
                            player.inventory.items[player.inventory.size++] = sword;
                            break;
                        }

                        default:
                            break;
                    }
                    SetConsoleCursorPosition(hConsole, {(SHORT)20, (SHORT)20});
                    cout << player.inventory.items[player.inventory.size - 1].art;
                    break;
                }
            }

            case 5:
            {
                /*mimic*/
                player.health -= 10;
                break;
            }
            }

            // Apaga o player da posição anterior
            if (newPosition.X != currentPosition.X || newPosition.Y != currentPosition.Y)
            {
                SetConsoleCursorPosition(hConsole, currentPosition);
                cout << " ";
            }

            // Verifica se a nova posição é válida antes de mover
            if (getCharAtPosition(hConsole, newPosition) != ' ')
            {
                newPosition = currentPosition; // volta se tiver parede ou obstáculo
            }

            // Atualiza posição do player
            player.setPosition(newPosition.X, newPosition.Y);

            // Desenha o player na nova posição
            SetConsoleCursorPosition(hConsole, player.position);
            cout << playerChar;

            // Pausa para dar tempo visual de ver o movimento
            Sleep(100);
        }
    }
    gameSaved.player = player;
    gameSaved.map = mapCurrent;
    gameSaved.seed = seed;
    gameSaved.returnType = Game::exit;
    return gameSaved;
}