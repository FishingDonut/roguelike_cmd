#include <sstream>
#include "include/core/visual_length.h"

int visualLength(std::string text, int spacing)
{
    int count = spacing;
    bool inEscape = false;

    for (char c : text)
    {
        if (c == '\x1b')
        {
            inEscape = true;
            continue;
        }

        if (inEscape)
        {
            if (c == 'm')
                inEscape = false;
            continue;
        }

        count++;
    }
    return count;
}