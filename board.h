#ifndef BOARD_H
#define BOARD_H
/*what do we need to know about the board to print the board?
BOARD_SIZE
Cell: is a given cell occupied, if yes by which player
Bridge: Are there bridges between two nodes? from and to where and whose?
number of bridges*/

#include "types.h"
#include <stdbool.h>
//struct for all board data
typedef struct Board{
    Cell cell_grid[BOARD_SIZE][BOARD_SIZE];
    Bridge bridges[MAX_BRIDGES];
    int bridge_count;
} Board;

//function to initialise empty board
void board_init(Board *new_board);

//checking if input from user is a valid position - returns 0/1/-1 based on owner
int is_valid_position(position pos);

void place_peg(Board *board, position pos, Player player);

void remove_peg(Board *board, position pos);

void board_print(const Board *board);

#endif
