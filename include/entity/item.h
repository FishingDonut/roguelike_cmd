#pragma once

#include <string.h>

enum ItemType
{
    NONE,
    POT_NONE,
    POT_HP,
    POT_XP,
    POT_SPEED,
    POT_MONEY,
    POT_DIST,
    POT_KILL,
    POT_TRAP,
};

struct Item
{
    ItemType itemType = NONE;
    std::string name = "none";
    float value = 0;
    int x, y = 0;
    char skin = '*';

    void empty()
    {
        itemType = POT_NONE;
        name = "Pot empty";
        value = 0;
    }
};

const Item ITEM_DATABASE[] = {
    {POT_NONE,  "Pot none",  0},
    {POT_HP,    "Pot hp",    10},
    {POT_HP,    "Pot hp",    10},
    {POT_HP,    "Pot hp",    10},
    {POT_XP,    "Pot xp",    20},
    {POT_SPEED, "Pot speed", 0.05},
    {POT_MONEY, "Pot money", 25},
    {POT_DIST,  "Pot dist",  1},
    {POT_KILL,  "Pot kill",  9999},
    {POT_TRAP,  "Pot trap",  1},
};


const int ITEM_DATABASE_SIZE = sizeof(ITEM_DATABASE) / sizeof(Item);
