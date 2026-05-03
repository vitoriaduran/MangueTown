# Nome do seu jogo
PROJECT_NAME = MangueKids

# Localização dos arquivos
SRC_DIR = src
OBJ_DIR = obj

# Encontra todos os arquivos .c
SOURCES = $(wildcard src/*.c)

# Define o compilador e as bibliotecas da Raylib
CC = gcc
CFLAGS = -Wall -std=c99 -Wno-missing-braces
LIBS = -lraylib -lopengl32 -lgdi32 -lwinmm

# Comando principal
all:
	$(CC) $(SOURCES) -o $(PROJECT_NAME).exe $(CFLAGS) $(LIBS)

# Limpar arquivos gerados
clean:
	del $(PROJECT_NAME).exe