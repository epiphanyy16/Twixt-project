#include <stdio.h>
#include "types.h"
#include "board.h"
#include "game.h"

int main(){
    Board board; //int x
    board_init(&board);
    board_print(&board);
    return 0;
}