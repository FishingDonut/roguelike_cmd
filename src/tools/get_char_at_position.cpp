#include <windows.h>
#include "../global.h"
#include "../include/tools/get_char_at_position.h"

char getCharAtPosition(HANDLE hConsole, COORD position)
{
    char c;
    DWORD read;
    ReadConsoleOutputCharacterA(hConsole, &c, 1, position, &read);
    return c;
}