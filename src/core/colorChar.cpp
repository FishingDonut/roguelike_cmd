#include <string>
#include "core/colorChar.h"

std::string colorChar(Colors color)
{
    std::string textColor;
    switch (color)
    {
    case COLOR_RED:
        return "\x1b[31m";
    case COLOR_GREEN:
        return "\x1b[32m";
    case COLOR_YELLOW:
        return "\x1b[33m";
    case COLOR_BLUE:
        return "\x1b[34m";
    case COLOR_MAGENTA:
        return "\x1b[35m";
    case COLOR_CYAN:
        return "\x1b[36m";
    case COLOR_WHITE:
        return "\x1b[37m";
    case COLOR_RESET:
    default:
        return "\x1b[0m"; // Reset
    }
};