#ifndef TYPES_H
#define TYPES_H

#define BOARD_SIZE 24
#define MAX_BRIDGES 2000

//defining players to show cell ownership
typedef enum player{
    none = 0,
    player_red = 1,
    player_black = -1
} Player;

//position on the board
typedef struct pos {
    int row;
    int column;
} position;

//to check if a given cell is occupied (and by who)
typedef struct owner {
    Player owner; //if a given cell is occupied by red, black, or none
} Cell;

//checking for bridges
typedef struct bridge {
    position from;
    position to;
    Player owner;
} Bridge;

typedef enum status{
    ongoing = 1,
    red_wins = 2,
    black_wins = 3,
    draw = 4
} gameStatus;



#endif