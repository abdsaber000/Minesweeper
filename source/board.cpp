#include "../header/board.h"
#include "../exceptions/board_type_execption.h"

Board * Board::create_board(int board_type){
    if(board_type == EASY)
        return new Board(EASY_BOARD_SIZE , EASY_BOARD_SIZE , EASY_MINES_NUMBER);
    
    if(board_type == MEDIUM)
        return new Board(MEDIUM_BOARD_SIZE , MEDIUM_BOARD_SIZE , MEDIUM_MINES_NUMBER);

    if(board_type == HARD)
        return new Board(HARD_BOARD_SIZE , HARD_BOARD_SIZE , HARD_MINES_NUMBER);

    throw new BoardTypeExecption;
}

Board::Board(int row_size, int col_size, int mines_number){
    board = vector<vector<Cell*>> (row_size, vector<Cell*> (col_size , nullptr));
}