#pragma once

#include "tile_map_value.h"
#include "map_construction/clear_map.h"

template <size_t height, size_t width>
void clearMap(int (&map)[height][width]) {
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            map[i][j] = WALL;
        }
    }
}