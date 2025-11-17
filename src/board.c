#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "board.h"


//function to initialise empty board - cell link and number of links
void board_init(Board *new_board){
    memset(new_board, 0, sizeof(Board));
}

//checking if input from user is a valid position
int is_valid_position(Board *board, position pos, Player player) {
    if(pos.row < BOARD_SIZE && pos.column < BOARD_SIZE) { 
        if(board->cell_grid[pos.row][pos.column].owner == none)
            return 1; //peg can be placed
        if(board->cell_grid[pos.row][pos.column].owner == player)
            return -1; //if input position already has a peg from the same user, it may be removed.
    }
    return 0;
}

void place_peg(Board *board, position pos, Player player){
    board->cell_grid[pos.row][pos.column].owner = player;
}

void remove_peg(Board *board, position pos){
    board->cell_grid[pos.row][pos.column].owner = 0;
}

void add_link(Board *board, position from, position to, Player player) {
    //adding to cell_1's connection array
    Cell* cell_1 = &board->cell_grid[from.row][from.column];
    cell_1->connected_links[cell_1->links_count] = to;
    cell_1->links_count++;

    //adding to cell_2's connection array
    Cell* cell_2 = &board->cell_grid[to.row][to.column];
    cell_2->connected_links[cell_2->links_count] = from;
    cell_2->links_count++;

    board->links[board->link_count++] = (Link){from, to, player};

    return;
}

void remove_link(Board* board, position from, position to, Player player) {
    int flag = 0;
    Cell* cell_1 = &(board->cell_grid[from.row][from.column]);
    for(int i = 0; i < cell_1->links_count; i++) {
        if(cell_1->connected_links[i].row == to.row && cell_1->connected_links[i].column == to.column){
            for(int j = i; j < cell_1->links_count; j++) {
                cell_1->connected_links[j].row = cell_1->connected_links[j+1].row;
                cell_1->connected_links[j].column = cell_1->connected_links[j+1].column; 
            }
            flag = 1;
            break;
        }
    }
    if(flag == 0) printf("invalid link");
}

//printing the board
void board_print(const Board *board){
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            if(board->cell_grid[j][i].owner == none)
                printf("o\t");
            if(board->cell_grid[j][i].owner == player_red)
                printf("●\t");  
            if(board->cell_grid[j][i].owner == player_black)
                printf("●\t");    
        }
        printf("\n\n\n");
    }
}