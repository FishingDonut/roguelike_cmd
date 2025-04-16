# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude -Isrc -I. -Iinclude/tools

# Fontes existentes no projeto
SRC = \
    main.cpp \
    src/core/update.cpp \
    src/core/init.cpp \
    src/tools/getCharAtPosition.cpp \
    src/tools/debugMatriz.cpp 

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
