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
struct Game
{
    Player player;
    map map;
    Seed seed;
    Position inSeed;
    enum ReturnTypes
    {
        exit,
        inventory,
    };
    ReturnTypes returnType;
};

Game loopPlayer(Game gameSaved)
{
    Seed seed;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    map mapteste;
    COORD newPosition;
    COORD currentPosition;
    Player player;
    Position inMap;

    setlocale(LC_ALL, "pt_BR.UTF-8");

    if (gameSaved.returnType != Game::exit)
    {
        mapteste = gameSaved.map;
        seed = gameSaved.seed;
        printMap(mapteste);
        currentPosition = {3, 3};
        newPosition = {3, 3};
        player = gameSaved.player;
        /*por algum motivo da bug se não setar o size manualmente*/
        player.inventory.size = gameSaved.player.inventory.size;
        inMap = gameSaved.inSeed;
    }
    else
    {
        generateSeed(seed);
        // selecionando a sala inicial
        mapteste = mapa(seed.loc[2][2]);
        // map mapteste = mapa(3);
        printMap(mapteste);
        currentPosition = {3, 3};
        newPosition = {3, 3};
        Player player = Player();
        player.inventory.size = 0;
        player.position = newPosition;
        inMap = {2, 2};
    }

    char playerChar = '@';
    bool swapMap;

    while (player.health > 0)
    {
        currentPosition = newPosition;

        int a = getch();
        SetConsoleCursorPosition(hConsole, {0, 0});
        if (swapMap)
            printMap(mapteste);

        if (a)
        {
            switch (a)
            {
            case 81:
                SetConsoleCursorPosition(hConsole, player.position);
                cout << "✞" << endl;
                // for (int j = 0; j < 16; j++)
                // {
                //     for (int i = 0; i < 16; i++)
                //     {
                //         SetConsoleCursorPosition(hConsole, {(SHORT)i, (SHORT)j});
                //         cout << mapteste.map[i][j];
                //     }}

                gameSaved.player = player;
                gameSaved.map = mapteste;
                gameSaved.seed = seed;
                gameSaved.inSeed = inMap;
                gameSaved.returnType = Game::exit;
                return gameSaved;
                break;
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
            case 9:
                gameSaved.player = player;
                gameSaved.map = mapteste;
                gameSaved.seed = seed;
                gameSaved.inSeed = inMap;
                gameSaved.returnType = Game::inventory;
                return gameSaved;
            default:
                cout << a << endl;
                break;
            }

            SetConsoleCursorPosition(hConsole, {(SHORT)20, (SHORT)20});
            cout << newPosition.Y << newPosition.X << mapteste.map[newPosition.Y][newPosition.X];

            switch (mapteste.map[newPosition.Y][newPosition.X])
            {
            case mapteste.entities::portaSupInf:
                if (newPosition.Y > 0 && inMap.y < 4)
                {
                    /*logic to select next map on bottom*/
                    swapMap = true;
                    inMap.y++;
                    mapteste = mapa(seed.loc[inMap.y][inMap.x]);
                    newPosition = {2, 2};
                }
                else if (inMap.y > 1)
                {
                    /* return to before room if has in room 5S*/
                    swapMap = true;
                    inMap.y--;
                    mapteste = mapa(seed.loc[inMap.y][inMap.x]);
                    newPosition = {2, 2};
                }
                break;
            case mapteste.entities::portaLat:
                if (newPosition.X > 0 && inMap.y < 4)
                {
                    /*logic to select next map on right*/
                    swapMap = true;
                    inMap.x++;
                    mapteste = mapa(seed.loc[inMap.y][inMap.x]);
                    newPosition = {2, 2};
                }
                else if (inMap.y > 1)
                {
                    /* return to before room if has in room 5S*/
                    swapMap = true;
                    inMap.x--;
                    mapteste = mapa(seed.loc[inMap.y][inMap.x]);
                    newPosition = {2, 2};
                }
                break;
            case mapteste.entities::item:
                /*item*/
                break;
            case mapteste.entities::chest:
            {
                /*chest*/
                if (player.inventory.size == 10)
                {
                    SetConsoleCursorPosition(hConsole, {(SHORT)20, (SHORT)20});
                    cout << "Inventory full";
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
                break;
            }
            }
            if (getCharAtPosition(hConsole, newPosition) != ' ')
            {
                newPosition = currentPosition;
            }
            player.setPosition(newPosition.X, newPosition.Y);
            SetConsoleCursorPosition(hConsole, currentPosition);
            cout << " ";
            SetConsoleCursorPosition(hConsole, player.position);
            cout << playerChar;
        }
    }
    gameSaved.player = player;
    gameSaved.map = mapteste;
    gameSaved.seed = seed;
    gameSaved.inSeed = inMap;
    gameSaved.returnType = Game::exit;
    return gameSaved;
}