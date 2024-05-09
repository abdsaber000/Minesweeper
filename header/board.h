#ifndef BOARD
#define BOARD
#include <vector>
#include "cell.h"
using namespace std;

enum {EASY, MEDIUM, HARD};
#define EASY_BOARD_SIZE 8
#define MEDIUM_BOARD_SIZE 10
#define HARD_BOARD_SIZE 12

#define EASY_MINES_NUMBER 10
#define MEDIUM_MINES_NUMBER 20
#define HARD_MINES_NUMBER 30


class Board{
    vector<vector<Cell*>> board;

public:
    Board(int row_size,  int col_size , int mines_number);

    static Board* create_board(int board_type);
};

#endif