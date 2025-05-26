#pragma once

#include <string.h>

struct Status
{
    int hp = 0;
    int spacingHp = 3;
    int gold = 0;
    int spacingGold = 0;
    int xp = 0;
    int spacingXp = 0;
    int kills = 0;
    std::string currentItem = "empty";
    int spacingKills = 0;
    int currentEnemyHp = 0;
    int spacingCurrentEnemyHp = 0;
    int currentEnemyDamage = 0;
    int spacingCurrentEnemyDamage = 0;
    int spacingItem = 0;
};
