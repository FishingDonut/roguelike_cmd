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


    int health = 100, shield = 100, damage = 10;
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

// void debugPrint(HANDLE hConsole, map mapCurrent, COORD newPosition, int a)
// {
//     // next char
//     SetConsoleCursorPosition(hConsole, {(SHORT)22, (SHORT)22});
//     cout << getCharAtPosition(hConsole, newPosition);

//     // map value array
//     for (int j = 0; j < 16; j++)
//     {
//         for (int i = 0; i < 16; i++)
//         {
//             SetConsoleCursorPosition(hConsole, {(SHORT)i, (SHORT)j});
//             if (mapCurrent.map[i][j] == 0)
//             {
//                 cout << " ";
//             }
//             else
//             {
//                 cout << mapCurrent.map[i][j];
//             }
//         }
//     }

//     // cordenada e value array map
//     SetConsoleCursorPosition(hConsole, {(SHORT)20, (SHORT)20});
//     cout << "row: " << newPosition.Y << " column: " << newPosition.X << " value: " << mapCurrent.map[newPosition.Y][newPosition.X];

//     // value int key
//     SetConsoleCursorPosition(hConsole, {(SHORT)21, (SHORT)21});
//     cout << a << endl;
// }

struct Game
{
    Player player;
    map map;
    Seed seed;
    enum ReturnTypes
    {
        exit,
        inventory,
        start,
        saved,
    };
    ReturnTypes returnType;
    int points = 0;
};

void hudPrint(Player player, int points){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole,{(SHORT)16,(SHORT)0});
    cout << "   |====================|";
    SetConsoleCursorPosition(hConsole,{(SHORT)16,(SHORT)1});
    cout << "   |Health: 100 / "<< player.health << "   ";
    SetConsoleCursorPosition(hConsole,{(SHORT)16,(SHORT)2});
    cout << "   |--------------------|";
    SetConsoleCursorPosition(hConsole,{(SHORT)16,(SHORT)3});
    cout << "   |Inventory: 10 / "<< player.inventory.size << "  ";
    SetConsoleCursorPosition(hConsole,{(SHORT)16,(SHORT)4});
    cout << "   |--------------------|";
    SetConsoleCursorPosition(hConsole,{(SHORT)16,(SHORT)5});
    cout << "   |Dano do jogador: " << player.damage << "   ";
    SetConsoleCursorPosition(hConsole,{(SHORT)16,(SHORT)6});
    cout << "   |--------------------|";
    SetConsoleCursorPosition(hConsole,{(SHORT)16,(SHORT)7});
    cout << "   |Pontuação: " << points;   
    SetConsoleCursorPosition(hConsole,{(SHORT)16,(SHORT)8});
    cout << "   |====================|";
    // FALTA FAZER A DO INIMIGO, SEPARADA DA DO PLAYER, AGUARDANDO O DANIEL FINALIZAR OS INIMIGOS;
}





void loopPlayer(Game &gameSaved)
{
    int StartTime = time(NULL);
    Seed seed;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    map mapCurrent;
    COORD newPosition;
    COORD currentPosition;
    Player player;
    Position inMap;

    setlocale(LC_ALL, "pt_BR.UTF-8");

    if (gameSaved.returnType != Game::start)
    {
        mapCurrent = gameSaved.map;
        seed = gameSaved.seed;
        printMap(mapCurrent);
        currentPosition = gameSaved.player.position;
        newPosition = gameSaved.player.position;
        player = gameSaved.player;
        /*por algum motivo da bug se não setar o size manualmente*/
        player.inventory.size = 0;
        player.inventory.size = gameSaved.player.inventory.size;
    }
    else
    {
        generateSeed(seed);
        // selecionando a sala inicial
        mapa(mapCurrent,seed.loc[2][2]);
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
    bool passado,armadilha = false;
    while (player.health > 0 && gameSaved.returnType != Game::exit && gameSaved.returnType != Game::inventory)
    {
        
        if (armadilha){
            passado = true;
        }
        
        
        currentPosition = newPosition;
        hudPrint(player,gameSaved.points);

        
        // printMap(mapCurrent);
        
        SetConsoleCursorPosition(hConsole, {0, 0});
        if (swapMap){
            //updateMoveEnemies(mapCurrent, {player.position.X, player.position.Y}, hConsole);
            printMap(mapCurrent);
            swapMap = false;
            SetConsoleCursorPosition(hConsole, player.position);
            cout << playerChar;
        }
        a = getch();
        updateMoveEnemies(mapCurrent, {player.position.X, player.position.Y}, hConsole);

        if (a)
        {
            //cout<<player.inventory.size;
            switch (a)
            {
            case 81:
                SetConsoleCursorPosition(hConsole, player.position);
                cout << "✞" << endl;

                gameSaved.player = player;
                gameSaved.map = mapCurrent;
                gameSaved.seed = seed;
                gameSaved.points += (StartTime - time(NULL) )% 30;
                gameSaved.returnType = Game::exit;
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
                gameSaved.points += (StartTime - time(NULL) )% 30;
                gameSaved.returnType = Game::inventory;
            default:
                    // debugPrint(hConsole, mapCurrent, newPosition, a);
                break;
            }

            switch (mapCurrent.map[newPosition.Y][newPosition.X])
            {
            case mapCurrent.entities::enemy:
                //newPosition = currentPosition; // volta se tiver parede ou obstáculo
                break;
            case mapCurrent.entities::portaSupInf:
                if (newPosition.Y > 0 && inMap.y < 4)
                {
                    /*logic to select next map on bottom*/
                    swapMap = true;
                    inMap.y++;
                    mapa(mapCurrent,seed.loc[inMap.y][inMap.x]);
                    currentPosition = {2, 2};
                }
                else if (inMap.y > 1)
                {
                    /* return to before room if has in room 5S*/
                    swapMap = true;
                    inMap.y--;
                    mapa(mapCurrent,seed.loc[inMap.y][inMap.x]);
                    currentPosition = {2, 2};
                }
                break;
            case mapCurrent.entities::portaLat:
                if (newPosition.X > 0 && inMap.x < 4)
                {
                    /*logic to select next map on right*/
                    swapMap = true;
                    inMap.x++;
                    mapa(mapCurrent,seed.loc[inMap.y][inMap.x]);
                    currentPosition = {2, 2};
                }
                else if (inMap.x > 1)
                {
                    /* return to before room if has in room 5S*/
                    swapMap = true;
                    inMap.x--;
                    mapa(mapCurrent,seed.loc[inMap.y][inMap.x]);
                    currentPosition = {2, 2};
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
                            player.damage += (rand() % 100);
                            break;
                        }

                        default:
                            break;
                    }
                    SetConsoleCursorPosition(hConsole, {(SHORT)20, (SHORT)20});
                    cout << player.inventory.items[player.inventory.size - 1].art;
                    break;
                }
                break;
            }

            case 5:
            {
                /*mimic*/
                player.health -= 10;
                break;
            }

            case mapCurrent.entities::armadilha:
            {
                player.health -= 10;
                armadilha = true;
                break;
            }

            default:
                break;
            }
            // Apaga o player da posição anterior
            if (newPosition.X != currentPosition.X || newPosition.Y != currentPosition.Y)
            {
                SetConsoleCursorPosition(hConsole, currentPosition);
                cout << " ";
            }
            
            //verifica se o player colidiu com o inimigo
            for (short int i = 0; i < mapCurrent.maxEnemy; i++)
            {
                if (mapCurrent.enemyList[i].position.x == newPosition.X && mapCurrent.enemyList[i].position.y == newPosition.Y)
                {
                    
                    player.health -= 10; // Adicionando dano do inimigo ao player
                }
            }
            //verifica se o player atacou o inimigo
            if (a == 32)//spacebar | barra de espaço
            {
                for(int x = -1;x<2;x++){
                    for(int y = -1;y<2;y++){
                        if(mapCurrent.map[currentPosition.X + x][currentPosition.Y + y] == mapCurrent.entities::fakewall){
                            SetConsoleCursorPosition(hConsole,{(SHORT)(currentPosition.X + x),(SHORT)(currentPosition.Y + y)});
                            cout << ' ';
                        }
                    }
                }
            
                for (short int i = 0; i < mapCurrent.maxEnemy; i++)
                {
                    for(int x = -1;x<2;x++){
                        for(int y = -1;y<2;y++){
                            if (mapCurrent.enemyList[i].position.x == currentPosition.X + x && mapCurrent.enemyList[i].position.y == currentPosition.Y + y){
                                mapCurrent.enemyList[i].health -= 10;
                                if(mapCurrent.enemyList[i].health <= 0 || mapCurrent.entities::fakewall == currentPosition.X + x || mapCurrent.entities::fakewall == currentPosition.Y + y ){
                                    SetConsoleCursorPosition(hConsole, {(SHORT)mapCurrent.enemyList[i].position.x, (SHORT)mapCurrent.enemyList[i].position.y});
                                    cout << ' ';
                                    
                                    gameSaved.points+=10;
                                    mapCurrent.enemyList[i].position.x = 1;
                                    mapCurrent.enemyList[i].position.y = 1;
                                    mapCurrent.enemyList[i]={};
                                }
                            }
                        }
                    }
                }
            }

            // Verifica se a nova posição é válida antes de mover

            if (getCharAtPosition(hConsole, newPosition) != ' ' && getCharAtPosition(hConsole, newPosition) != '\u0023')
            {
                newPosition = currentPosition;
            }            else if (mapCurrent.map[newPosition.Y][newPosition.X] == mapCurrent.entities::chest)
            {
                mapCurrent.map[newPosition.Y][newPosition.X] = mapCurrent.entities::floor;
            }
            else if (mapCurrent.map[newPosition.Y][newPosition.X] == mapCurrent.entities::mimic)
            {
                mapCurrent.map[newPosition.Y][newPosition.X] = mapCurrent.entities::floor;
            }
            else if (mapCurrent.map[newPosition.Y][newPosition.X] == mapCurrent.entities::armadilha)
            {
                mapCurrent.map[newPosition.Y][newPosition.X] = mapCurrent.entities::floor;
            }

            
            // Atualiza posição do player

            player.setPosition(newPosition.X, newPosition.Y);

            // SetConsoleCursorPosition(hConsole, currentPosition);
            // if (!armadilha)
            // {
            //     cout << " ";
            // }
            
            
            
            SetConsoleCursorPosition(hConsole, player.position);
            cout << playerChar;


            // Pausa para dar tempo visual de ver o movimento
            // Sleep(100);
            if (armadilha && passado)
            {
                SetConsoleCursorPosition(hConsole,currentPosition);
                cout << "\u0023";
                armadilha = false;
                passado = false;
            }
        }
    }
    // gameSaved.player = player;
    // gameSaved.map = mapCurrent;
    // gameSaved.seed = seed;
    // gameSaved.returnType = Game::exit;
}