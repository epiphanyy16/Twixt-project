#include <stdio.h>
#include "types.h"
#include "board.h"
#include "game.h"
#include "cli.h"

int main(){
    Board board; //int x
    board_init(&board);
    board_print(&board);
    game_loop(&board);
    return 0;
}