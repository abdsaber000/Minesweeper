#include "../header/board.h"

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
    for(int i = 0; i < mines_number; i++){
        int x = -1, y = -1;
        do{
            x = rand() % row_size;
            y = rand() % col_size;
        }while(board[x][y] != nullptr);

        board[x][y] = new Cell(x, y, true, -1);
    }
    for(int i = 0; i < row_size; i++){
        for(int j = 0; j < col_size; j++){
            if(board[i][j] != nullptr){
                continue;
            }
            int count_neighbour_mines = 0;
            for(int dx = -1; dx <= 1; dx++){
                for(int dy = -1; dy <= 1; dy++){
                    if(dx == 0 && dy == 0){
                        continue;
                    }
                    if(is_valid_position(i + dx, j + dy)){
                        if(board[i + dx][j + dy] != nullptr && board[i + dx][j + dy]->get_has_mine() == true){
                            count_neighbour_mines++;
                        }
                    }
                }
            }
            board[i][j] = new Cell(i, j, false, count_neighbour_mines);
        }
    }
}

bool Board::is_valid_position(int row , int col){
    return row >= 0 && col >= 0 && row < board.size() && col < board[0].size();
}

Cell* Board::get_cell(int row , int col){
    if(!is_valid_position(row, col))
        throw new BoardBoundriesExecption;
    return board[row][col];
}