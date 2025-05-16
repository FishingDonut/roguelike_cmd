# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude -Isrc -I. -Iinclude/tools
LDFLAGS = -mconsole

# Fontes existentes no projeto
SRC = \
    main.cpp \
    src/core/clear_enemy.cpp \
    src/core/init.cpp \
    src/core/render.cpp\
    src/core/color_char.cpp\
    src/core/map_value_to_char.cpp\
    src/core/set_config_key.cpp \
    src/core/search_entity.cpp \
    src/core/visual_length.cpp \
    src/core/is_numeric.cpp \
    src/file_manager/score/score_in.cpp \
    src/file_manager/score/score_out.cpp \
    src/file_manager/score/score_manager.cpp \
    src/tools/get_char_at_position.cpp \
    src/tools/debug_matriz.cpp \
    src/states/credits_state.cpp \
    src/states/menu_state.cpp \
    src/states/info_state.cpp \
    src/states/map_construction_state.cpp \
    src/states/playing_state.cpp \
    src/states/paused_state.cpp \
    src/states/game_over_state.cpp \
    src/playing/status/render_status.cpp \
    src/playing/input.cpp \
    src/playing/render.cpp \
    src/playing/update_logic.cpp \
    src/playing/player/attack.cpp \
    src/playing/player/update_player.cpp \
    src/playing/player/render_attack_frame.cpp \
    src/playing/enemies/update_enemies.cpp \
    src/playing/enemies/direction_enemy.cpp \
    src/playing/enemies/collision_enemy.cpp \
    src/playing/enemies/render_frame_enemy.cpp \
    src/playing/boss/collision_boss.cpp \
    src/playing/boss/update_boss.cpp \
    src/playing/boss/render_frame_boss.cpp \
    src/playing/boss/direction_boss.cpp \
    src/playing/traps/render_frame_trap.cpp \
    src/menu/input.cpp \
    src/menu/render.cpp \
    src/map_construction/clear_map.cpp \
    src/map_construction/connect_room.cpp \
    src/map_construction/create_room.cpp \
    src/map_construction/generate_random_boss_room.cpp \
    src/map_construction/generate_rooms.cpp \
    src/map_construction/generate_boss.cpp \
    src/map_construction/generate_enemy.cpp \
    src/map_construction/generate_trap.cpp \
    src/map_construction/generate_random_room.cpp \
    src/map_construction/is_colliding.cpp \
    src/map_construction/set_position_player.cpp \
    src/map_construction/set_position_stair.cpp

# Gera nomes dos arquivos .o
OBJ = $(SRC:.cpp=.o)

# Nome do executável final
TARGET = main.exe

# Regra principal
all: $(TARGET)

# Linkagem
$(TARGET): $(OBJ)
	$(CXX) $(LDFLAGS) $(OBJ) -o $(TARGET)

# Regra para compilar .cpp → .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza (Windows)
clean:
	rm -f $(OBJ) $(TARGET)
