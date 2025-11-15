#ifndef cli_h
#define cli_h

#include "types.h"
#include "board.h"

bool get_move(Player player, position *pos);

void game_loop(Board *board);

#endif