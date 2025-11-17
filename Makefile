# ===============================
#   Makefile for Twixt Project
# ===============================

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

TARGET = twixt

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

.PHONY: all clean run dirs
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TARGET = twixt
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
.PHONY: all clean run dirs
all: dirs $(BIN_DIR)/$(TARGET)
dirs:
	mkdir -p $(OBJ_DIR) $(BIN_DIR)
$(BIN_DIR)/$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
run: all
	./$(BIN_DIR)/$(TARGET)
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
all: dirs $(BIN_DIR)/$(TARGET)
dirs:
	mkdir -p $(OBJ_DIR) $(BIN_DIR)
$(BIN_DIR)/$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
run: all
	./$(BIN_DIR)/$(TARGET)
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
