#ifndef BOARD
#define BOARD
#include <vector>
#include "cell.h"
#include "../exceptions/board_type_execption.h"
#include "../exceptions/board_boundries_exception.h"
#include "position.h"

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
    int mines_number;
    void preprocess_board();
    void preprocess_mines();
    void add_neighbour_mines_count();
    Position random_unused_position();
    int count_neighbour_mines(int row , int col);
    bool has_mine(int row , int col);
public:
    Board(int row_size,  int col_size , int mines_number);

    static Board* create_board(int board_type);
    int get_row_size() const{
        return board.size();
    }

    int get_col_size() const{
        return board[0].size();
    }
    bool is_valid_position(int row , int col);
    Cell* get_cell(int row , int col);
};

#endif