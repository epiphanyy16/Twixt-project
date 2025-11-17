#ifndef TYPES_H
#define TYPES_H

#define BOARD_SIZE 10
#define MAX_LINKS 2000

//defining players to show cell ownership
typedef enum player{
    none = 0,
    player_red = 1,
    player_black = -1
} Player;

//position on the board
typedef struct position {
    int row;
    int column;
} position;

//to check if a given cell is occupied (and by who)
typedef struct Cell {
    Player owner; //if a given cell is occupied by red, black, or none
    position connected_links[8]; //there can be maximum 8 links from any given cell
    int links_count;
} Cell;

//checking for links
typedef struct link {
    position from;
    position to;
    Player owner;
} Link;

typedef enum status{
    ongoing = 1,
    red_wins = 2,
    black_wins = 3,
    draw = 4
} status;




#endif