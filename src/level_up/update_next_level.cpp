#include "./level_up/update_next_level.h"

void update_next_level(int &level, int &xp, int &next_level)
{
    xp -= next_level;
    next_level *= 1.5;
    level += 1;
    return;
}