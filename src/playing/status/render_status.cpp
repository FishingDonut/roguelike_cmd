#include <sstream>
#include <windows.h>

#include "include/GameData.h"
#include "include/status/render_status.h"
#include "include/core/mapValueToChar.h"
#include "include/core/colorChar.h"

int visualLength(std::string text, int spacing)
{
    int count = spacing;
    bool inEscape = false;

    for (char c : text)
    {
        if (c == '\x1b')
        {
            inEscape = true;
            continue;
        }

        if (inEscape)
        {
            if (c == 'm')
                inEscape = false;
            continue;
        }

        count++;
    }
    return count;
}

void clearStatus(stringstream &stream, int size, COORD position)
{
    HANDLE hConsole = gameData.hConsole;
    stream.str("");
    stream.clear();

    SetConsoleCursorPosition(hConsole, {position});
    for (int i = 0; i < size; i++)
    {
        cout << "-";
    }
}

void render_status()
{
    HANDLE hConsole = gameData.hConsole;
    Player &player = gameData.player;
    Status &status = gameData.status;

    std::stringstream stream;
    std::string hpText;
    std::string killsText;
    std::string goldText;
    std::string xpText;

    int spacingText = 3;

    // HP
    if (status.hp != player.health)
    {
        status.hp = player.health;

        stream << "[ HP: " << colorChar(COLOR_GREEN) << status.hp << colorChar(COLOR_RESET) << " ]";
        hpText = stream.str();
        int textLength = visualLength(hpText, spacingText);

        clearStatus(stream, textLength, {(SHORT)status.spacingHp, (SHORT)height - 1});

        status.spacingKills = status.spacingHp + textLength + spacingText;

        SetConsoleCursorPosition(hConsole, {(SHORT)status.spacingHp, (SHORT)height - 1});
        cout << hpText;
    }

    // KILLS
    if (player.kills != status.kills)
    {
        status.kills = player.kills;

        stream << "[ KILLS: " << colorChar(COLOR_REVERSE) << status.kills << colorChar(COLOR_RESET) << " ]";
        killsText = stream.str();
        int textLength = visualLength(killsText, spacingText);

        clearStatus(stream, textLength, {(SHORT)status.spacingKills, (SHORT)height - 1});

        status.spacingGold = status.spacingKills + textLength + spacingText;

        SetConsoleCursorPosition(hConsole, {(SHORT)status.spacingKills, (SHORT)height - 1});
        cout << killsText;
    }

    // GOLD
    if (player.gold != status.gold)
    {
        status.gold = player.gold;

        stream << "[ GOLD: " << colorChar(COLOR_YELLOW) << status.gold << colorChar(COLOR_RESET) << " ]";
        goldText = stream.str();
        int textLength = visualLength(goldText, spacingText);

        clearStatus(stream, textLength, {(SHORT)status.spacingGold, (SHORT)height - 1});

        status.spacingXp = status.spacingGold + textLength + spacingText;

        SetConsoleCursorPosition(hConsole, {(SHORT)status.spacingGold, (SHORT)height - 1});
        cout << goldText;
    }

    // XP
    if (player.xp != status.xp)
    {
        status.xp = player.xp;

        stream << "[ XP: " << colorChar(COLOR_CYAN) << player.xp << colorChar(COLOR_RESET) << " ]";
        xpText = stream.str();
        int textLength = visualLength(xpText, spacingText);

        clearStatus(stream, textLength, {(SHORT)status.spacingXp, (SHORT)height - 1});

        SetConsoleCursorPosition(hConsole, {(SHORT)status.spacingXp, (SHORT)height - 1});
        cout << xpText;
    }
}
