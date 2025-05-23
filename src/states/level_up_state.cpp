#include "states/level_up_state.h"
#include <windows.h>
#include <conio.h>

#include "game_data.h"
#include "entity/player.h"
#include "level_up/update_next_level.h"

extern StateMachine nextState;
extern bool stateChanged;

void level_up_enter()
{
    Player player = gameData.player;
    auto &xp = player.xp;
    auto &nextXpLevel = player.nextXpLevel;

    if (xp < nextXpLevel)
    {
        nextState = STATE_PLAYING;
        stateChanged = true;
        return;
    }

    HANDLE HConsole = gameData.hConsole;
    system("cls");
    SetConsoleCursorPosition(HConsole, {(SHORT){width / 2} - 12, (SHORT)(height / 2) - 1});
    cout << "[Distribua seus pontos]";
    SetConsoleCursorPosition(HConsole, {(SHORT){width / 2} - 18, (SHORT)(height / 2)});
    cout << "[Heart[0] Damage[1] Speed[2] Exit[Q]";
    return;
}

void level_up_update()
{
    HANDLE HConsole = gameData.hConsole;
    Player &player = gameData.player;
    auto &xp = player.xp;
    auto &nextXpLevel = player.nextXpLevel;
    auto &level = player.level;
    auto &health = player.health;
    auto &speed = player.delay;
    auto &power = player.damage;

    if (xp < nextXpLevel)
    {
        nextState = STATE_PLAYING;
        stateChanged = true;
        return;
    }

    if (!_kbhit())
        return;

    char c = getch();

    switch (c)
    {
    case '0':
        health += 1;
        break;
    case '1':
        power += 1;
        break;
    case '2':
        speed -= 0.02f;
        break;
    case 'q':
    case 'Q':
        nextState = STATE_PLAYING;
        stateChanged = true;
        return;
        break;
    default:
        return;
        break;
    }

    update_next_level(level, xp, nextXpLevel);

    SetConsoleCursorPosition(HConsole, {(SHORT){width / 2} - 18, (SHORT)(height / 2) + 2});
    cout << "[Heart: " << health << " Damage: " << power << " Speed: " << speed << "]";

    SetConsoleCursorPosition(HConsole, {(SHORT){width / 2} - 5, (SHORT)(height / 2) + 3});
    cout << "Level: " << level;
    return;
}

void level_up_exit()
{
    return;
}