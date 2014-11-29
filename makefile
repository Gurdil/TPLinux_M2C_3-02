DEBUG=yes
CC=g++
ifeq ($(DEBUG),yes)
	CFLAGS=-W -Wall -ansi -pedantic -g
	LDFLAGS= -lpthread
else
	CFLAGS=-W -Wall -ansi -pedantic
	LDFLAGS= -lpthread
endif

EXEC=DLlinux

ROOT_DIR := $(shell pwd)
BIN_DIR = $(ROOT_DIR)/bin
SRC_DIR = $(ROOT_DIR)/src
INC_DIR = $(ROOT_DIR)/include
EXISTE := $(wildcard $(BIN_DIR))

SRC= $(wildcard $(SRC_DIR)/*.cpp)
NAME = $(basename $(notdir $(SRC)))
OBJ= $(addprefix $(BIN_DIR)/, $(addsuffix .o, $(NAME)))


all: makedir $(EXEC)
ifeq ($(DEBUG),yes)
	@echo "Génération en mode debug"
else
	@echo "Génération en mode release"
endif

ifeq ($(strip $(EXISTE)),)
makedir:
	mkdir $(BIN_DIR)
else
makedir:
endif

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

$(BIN_DIR)/main.o: $(INC_DIR)/puce.h

$(BIN_DIR)/thread.o: $(INC_DIR)/thread.h

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -o $@ -c $< -I$(INC_DIR) $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf $(BIN_DIR)/*.o
	-rmdir $(BIN_DIR)

mrproper: clean
	rm -rf $(EXEC)