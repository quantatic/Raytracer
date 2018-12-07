CC = gcc
CFLAGS = -std=c99 -Wall -Werror -g -O2
LDLIBS = -lm

SRC_DIR=src
OBJ_DIR=bin

SRC_FILES=$(wildcard $(SRC_DIR)/*.c)
OBJ_FILES=$(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $< -o $a -c $(CFLAGS)

raytrace: $(OBJ_FILES)

$(info VAR IS $(OBJ_FILES))

clean:
	rm -rf $(OBJ_FILES)
