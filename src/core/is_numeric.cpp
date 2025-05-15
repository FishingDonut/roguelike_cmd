#include "core/is_numeric.h"

#include <string>
#include <cctype>

bool isNumeric(std::string texto)
{
    for (char c : texto)
    {
        if (c == '\n')
        {
            c = 0;
        }
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}