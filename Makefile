# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude -Isrc -I. -Iinclude/tools

# Fontes existentes no projeto
SRC = \
    main.cpp \
    src/core/clearEnemy.cpp \
    src/core/init.cpp \
    src/core/render.cpp\
    src/core/colorChar.cpp\
    src/core/mapValueToChar.cpp\
    src/core/setConfigKey.cpp \
    src/tools/getCharAtPosition.cpp \
    src/tools/debugMatriz.cpp \
    src/states/menu_state.cpp \
    src/states/map_construction_state.cpp \
    src/states/playing_state.cpp \
    src/states/paused_state.cpp \
    src/states/game_over_state.cpp \
    src/playing/input.cpp \
    src/playing/render.cpp \
    src/playing/update_logic.cpp \
    src/playing/player/attack.cpp \
    src/playing/player/update_player.cpp \
    src/playing/enemies/update_enemies.cpp \
    src/playing/enemies/direction_enemy.cpp \
    src/playing/enemies/collision_enemy.cpp \
    src/menu/input.cpp \
    src/menu/render.cpp \
    src/map_construction/clearMap.cpp \
    src/map_construction/connectRoom.cpp \
    src/map_construction/createRoom.cpp \
    src/map_construction/generate_rooms.cpp \
    src/map_construction/generateEnemy.cpp \
    src/map_construction/generateRandomRoom.cpp \
    src/map_construction/isColliding.cpp \
    src/map_construction/set_position_player.cpp

# Gera nomes dos arquivos .o
OBJ = $(SRC:.cpp=.o)

# Nome do executável final
TARGET = main.exe

# Regra principal
all: $(TARGET)

# Linkagem
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Regra para compilar .cpp → .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza (Windows)
clean:
	del /Q $(subst /,\,$(OBJ)) $(TARGET)
