#include "cli.h"

bool get_move(Player player, position *pos){
    if (player == player_red) {
        printf("Red: Enter move:");
        if (scanf("%d %d", &(pos->row), &(pos->column)) != 2) {
            while (getchar() != '\n');
            return false;
        }
        return true;
    }
    else {
        printf("Black: Enter move:");
        if (scanf("%d %d", &(pos->row), &(pos->column)) != 2) {
            while (getchar() != '\n');
            return false;
        }
        return true;
    }
}

void game_loop(Board *board) {
    
    Player current_player = player_red;
    position move_position;
    while(1) {
        board_print(board);
        if (!get_move(current_player, &move_position)){
            printf("invalid move");
            continue;
        }
        int valid = is_valid_position(board, move_position, current_player);
        if (valid){
            if (valid == 1) {
                place_peg(board, move_position, current_player);
            }
            if (valid == -1) {
                remove_peg(board, move_position);
            }
        }
        else {
            printf("invalid position\n");
            continue;
        }
        //add function to check if current_player won here
        if (current_player == player_red) {
            current_player = player_black;
        } else {
            current_player = player_red;
        }
    }
}