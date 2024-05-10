#ifndef GAME
#define GAME

#include "board.h"

class Game{
    Board *board;

public:
    void create_board(int level);
};

#endif