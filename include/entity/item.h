#pragma once

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
    const char* name = "empty";
    float value = 0;
    int x, y = 0;
    char skin = '*';
};

const Item ITEM_DATABASE[] = {
    { POT_HP, "Pot none", 0 },
    { POT_HP, "Pot hp", 10 },
    { POT_HP, "Pot xp", 20 },
    { POT_HP, "Pot speed", 0.05 },
    { POT_HP, "Pot money", 25 },
    { POT_HP, "Pot dist", 1 },
    { POT_HP, "Pot kill", 9999 },
    { POT_HP, "Pot trap", 1 },
};

const int ITEM_DATABASE_SIZE = sizeof(ITEM_DATABASE) / sizeof(Item);
