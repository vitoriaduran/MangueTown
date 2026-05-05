# 1. Nome do executável
TARGET = MangueTown

# 2. Caminhos
SRC_DIR = src
INC_DIR = include
RAYLIB_PATH = C:/raylib/raylib/src

# 3. COMANDO COMPATÍVEL (Funciona no terminal do w64devkit/bash)
# Procura todos os arquivos .c em src e suas subpastas
SOURCES = $(shell find $(SRC_DIR) -name "*.c")

# 4. Flags e Bibliotecas
# Adicionamos -mconsole para garantir que ele use o main() e não WinMain
CFLAGS = -Wall -std=c99 -I$(INC_DIR) -I$(RAYLIB_PATH)
LDFLAGS = -L$(RAYLIB_PATH) -lraylib -lopengl32 -lgdi32 -lwinmm -lcomdlg32 -lole32 -mconsole

# 5. Regra de Compilação
all:
	gcc $(SOURCES) -o $(TARGET).exe $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(TARGET).exe