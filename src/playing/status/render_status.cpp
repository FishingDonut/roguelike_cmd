#include <sstream>
#include <windows.h>

#include "include/GameData.h"
#include "include/status/render_status.h"
#include "include/core/mapValueToChar.h"
#include "include/core/colorChar.h"

void clearStatus(stringstream &stream, int size, COORD position){
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
        clearStatus(stream, hpText.size(), {(SHORT)status.spacingHp, (SHORT)height - 1});

        status.spacingKills = status.spacingHp + hpText.size() + spacingText;

        SetConsoleCursorPosition(hConsole, {(SHORT)status.spacingHp, (SHORT)height - 1});
        cout << hpText;
    }

    // KILLS
    if (player.kills != status.kills)
    {
        status.kills = player.kills;

        stream << "[ KILLS: " << colorChar(COLOR_REVERSE) << status.kills << colorChar(COLOR_RESET) << " ]";
        killsText = stream.str();
        clearStatus(stream, killsText.size(), {(SHORT)status.spacingKills, (SHORT)height - 1});


        status.spacingGold = status.spacingKills + killsText.size() + spacingText;

        SetConsoleCursorPosition(hConsole, {(SHORT)status.spacingKills, (SHORT)height - 1});
        cout << killsText;
    }

    // GOLD
    if (player.gold != status.gold)
    {
        status.gold = player.gold;

        stream << "[ GOLD: " << colorChar(COLOR_YELLOW) << status.gold << colorChar(COLOR_RESET) << " ]";
        goldText = stream.str();
        clearStatus(stream, goldText.size(), {(SHORT)status.spacingGold, (SHORT)height - 1});


        status.spacingXp = status.spacingGold + goldText.size() + spacingText;

        SetConsoleCursorPosition(hConsole, {(SHORT)status.spacingGold, (SHORT)height - 1});
        cout << goldText;
    }

    // XP
    if (player.xp != status.xp)
    {
        status.xp = player.xp;

        stream << "[ XP: " << colorChar(COLOR_CYAN) << player.xp << colorChar(COLOR_RESET) << " ]";
        xpText = stream.str();
        clearStatus(stream, xpText.size(), {(SHORT)status.spacingXp, (SHORT)height - 1});


        SetConsoleCursorPosition(hConsole, {(SHORT)status.spacingXp, (SHORT)height - 1});
        cout << xpText;
    }
}
