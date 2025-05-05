#include <string>
#include "core/color_char.h"
#include "core/colors.h"

std::string colorChar(Colors color)
{
    switch (color)
    {
    case COLOR_REVERSE: return "\x1b[7m";
    case COLOR_RED: return "\x1b[31m";
    case COLOR_GREEN: return "\x1b[32m";
    case COLOR_YELLOW: return "\x1b[33m";
    case COLOR_BLUE: return "\x1b[34m";
    case COLOR_MAGENTA: return "\x1b[35m";
    case COLOR_CYAN: return "\x1b[36m";
    case COLOR_WHITE: return "\x1b[37m";

    case COLOR_BRIGHT_BLACK: return "\x1b[90m";
    case COLOR_BRIGHT_RED: return "\x1b[91m";
    case COLOR_BRIGHT_GREEN: return "\x1b[92m";
    case COLOR_BRIGHT_YELLOW: return "\x1b[93m";
    case COLOR_BRIGHT_BLUE: return "\x1b[94m";
    case COLOR_BRIGHT_MAGENTA: return "\x1b[95m";
    case COLOR_BRIGHT_CYAN: return "\x1b[96m";
    case COLOR_BRIGHT_WHITE: return "\x1b[97m";

    case COLOR_BG_BLACK: return "\x1b[40m";
    case COLOR_BG_RED: return "\x1b[41m";
    case COLOR_BG_GREEN: return "\x1b[42m";
    case COLOR_BG_YELLOW: return "\x1b[43m";
    case COLOR_BG_BLUE: return "\x1b[44m";
    case COLOR_BG_MAGENTA: return "\x1b[45m";
    case COLOR_BG_CYAN: return "\x1b[46m";
    case COLOR_BG_WHITE: return "\x1b[47m";

    case COLOR_RESET:
    default:
        return "\x1b[0m";
    }
}