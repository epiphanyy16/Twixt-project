//(//placing/removing peg check whether is_valid_position is 1 or -1
/*if(is_valid_position(pos)==1){
        board->cell_grid[pos.row][pos.column].owner = player;
    }
    if(board->cell_grid[pos.row][pos.column].owner == player){
        board->cell_grid[pos.row][pos.column].owner = none;
    }

    //2KzH2G4t)*/
#include "cli.h"

int abs_diff(int a, int b) {
    if(a > b) return a - b;
    else return b - a;
}

int is_knight(Board *board, position from, position to, Player player) {
    if(board->cell_grid[from.row][from.column].owner == player) {
        if((abs_diff(from.row, to.row) == 2 && abs_diff(from.column, to.column) == 1) || (abs_diff(from.row, to.row) == 1 && abs_diff(from.column, to.column) == 2))
            return 1;
    }
    return 0;
}
void valid_link(Board *board, position pos){
    
}
void place_link(Board *board, position pos){}