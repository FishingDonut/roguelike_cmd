#include <sstream>
#include <windows.h>

#include "include/game_data.h"
#include "include/status/render_status.h"
#include "include/core/map_value_to_char.h"
#include "include/core/color_char.h"
#include "include/core/visual_length.h"

// void clearStatus(int size, COORD position)
// {
//     HANDLE hConsole = gameData.hConsole;

//     SetConsoleCursorPosition(hConsole, position);
//     for (int i = -2; i < size; i++)
//     {
//         std::cout << "-";
//     }
// }

// void updateStatus(std::stringstream& stream, const std::string& label, Colors color, int& currentValue, int newValue, int& spacing, int& nextSpacing, int spacingText)
// {
//     HANDLE hConsole = gameData.hConsole;

//     stream.str("");
//     stream.clear();

//     stream << "[ " << label << ": " << colorChar(color) << newValue << colorChar(COLOR_RESET) << " ]";
//     std::string text = stream.str();
//     int textLength = visualLength(text, spacingText);

//     if (currentValue != newValue)
//     {
//         currentValue = newValue;
//         clearStatus(textLength, {(SHORT)spacing, (SHORT)height - 1});

//         SetConsoleCursorPosition(hConsole, {(SHORT)spacing, (SHORT)height - 1});
//         std::cout << text;
//     }

//     nextSpacing = spacing + textLength + spacingText;
// }

void render_status()
{
    return;
    // Player& player = gameData.player;
    // Status& status = gameData.status;

    // std::stringstream stream;
    // int spacingText = 3;

    // updateStatus(stream, "HP", COLOR_GREEN, status.hp, player.health, status.spacingHp, status.spacingKills, spacingText);
    // updateStatus(stream, "KILLS", COLOR_MAGENTA, status.kills, player.kills, status.spacingKills, status.spacingGold, spacingText);
    // updateStatus(stream, "GOLD", COLOR_YELLOW, status.gold, player.gold, status.spacingGold, status.spacingXp, spacingText);
    // updateStatus(stream, "XP", COLOR_CYAN, status.xp, player.xp, status.spacingXp, status.spacingCurrentEnemyHp, spacingText);
    // updateStatus(stream, "EHP", COLOR_RED, status.currentEnemyHp, gameData.currentEnemy.health, status.spacingCurrentEnemyHp, status.spacingCurrentEnemyDamage, spacingText);
    // updateStatus(stream, "DMG", COLOR_YELLOW, status.currentEnemyDamage, gameData.currentEnemy.damage, status.spacingCurrentEnemyDamage, status.spacingCurrentEnemyDamage, spacingText);
}
