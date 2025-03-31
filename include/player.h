#include <iostream>
#include <conio.h>
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

    COORD getPosition()
    {
        return position;
    }

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
    system("cls");
    setlocale(LC_ALL, "pt_BR.UTF-8");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD currentPosition = {0, 0};
    COORD newPosition = {0, 0};
    Player player = Player();
    player.position = newPosition;

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

            SetConsoleCursorPosition(hConsole, {0, 32});
            cout << getCharAtPosition(hConsole, newPosition);

            if (getCharAtPosition(hConsole, newPosition) == '0')
            {
                newPosition = currentPosition;
            }

            player.setPosition(newPosition.X, newPosition.Y);
            SetConsoleCursorPosition(hConsole, currentPosition);
            cout << " ";
            SetConsoleCursorPosition(hConsole, player.getPosition());
            cout << "@";
        }
    }
    return 0;
}