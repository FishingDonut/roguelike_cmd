#pragma once

#include <windows.h>

#include "game_data.h"
#include "entity/trap.h"
#include "entity/item.h"
#include "core/search_entity.h"

Trap searchTrap(COORD position);
Item searchItem(COORD position);