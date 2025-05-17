#include <windows.h>
#include "BearLibTerminal.h"

#include "../include/tools/get_char_at_position.h"

char getCharAtPosition(COORD position)
{
    char c;
    c = terminal_pick(position.X, position.Y);
    return c;
}