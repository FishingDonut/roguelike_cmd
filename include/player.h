#include <iostream>
#include <conio.h>
#include "./maps.h"
#include <windows.h>
using namespace std;


struct Items
{
    enum TypeofItems
    {
        potion = 2,
        armor,
        weapon,
        key,
    };
    TypeofItems type;
    short int quantity;
    float durability;
    enum effects
    {
        strengh,
        luck,
    };
    string art;
    short int midX, midY;
};

struct Inventory
{
    Items items[10];
    short int size;
};

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

    int updateHealth(int health)
    {
        health += health;
        return health;
    }
};

char getCharAtPosition(HANDLE hConsole, COORD position)
{
    char c;
    DWORD read;
    ReadConsoleOutputCharacterA(hConsole, &c, 1, position, &read);
    return c;
}

int loopPlayer()
{
    map mapteste = mapa();
    
    for (int j = 0; j < 16; j++)
    {
        for (int i = 0; i < 16; i++)
        {
            switch (mapteste.map[j][i])
            {
                //desenhando piso
                case 0:
                    cout << " ";
                    break;
                case mapteste.entities::parede:
                    cout<< "\u2588";
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
    
    setlocale(LC_ALL, "pt_BR.UTF-8");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD currentPosition = {3, 3};
    COORD newPosition = {3, 3};
    Player player = Player();
    player.position = newPosition;
    char test= '@';
    while (player.health > 0)
    {
        currentPosition = newPosition;
        int a = getch();
        
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
                return 0;
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
            default:
                cout << a << endl;
                break;
            }

            SetConsoleCursorPosition(hConsole, {0, 0});
            cout << getCharAtPosition(hConsole, newPosition);
            SetConsoleCursorPosition(hConsole,{(SHORT)20,(SHORT)20});
            cout<< newPosition.X << newPosition.Y << mapteste.map[newPosition.X][newPosition.Y];
            
            if (getCharAtPosition(hConsole, newPosition) != ' ')
            {
                newPosition = currentPosition;
            }
            player.setPosition(newPosition.X, newPosition.Y);
            SetConsoleCursorPosition(hConsole, currentPosition);
            cout << " ";
            SetConsoleCursorPosition(hConsole, player.position);
            cout << test;
        }
    }
    
    return 0;
}