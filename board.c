#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "board.h"


//function to initialise empty board - cell bridge and number of bridges
void board_init(Board *new_board){
    memset(new_board, 0, sizeof(Board));
}

//checking if input from user is a valid position
int is_valid_position(position pos) {
    if(pos.row <= BOARD_SIZE && pos.column <= BOARD_SIZE) { 
        if(!(pos.row||pos.column))
            return 1; //peg can be placed
        if(pos.row||pos.column)
            return -1; //peg can be removed
    }
    return 0;
}

void place_peg(Board *board, position pos, Player player){
    board->cell_grid[pos.row][pos.column].owner = player;
}

void remove_peg(Board *board, position pos){
    board->cell_grid[pos.row][pos.column].owner = 0;
}

//printing the board
void board_print(const Board *board){
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            if(board->cell_grid[j][i].owner == 0)

            if(board->cell_grid[j][i].owner == 1)
                printf("%c\t", );
            if(board->cell_grid[j][i].owner == -1)
            
            printf("\n\n");
        }
    }
}