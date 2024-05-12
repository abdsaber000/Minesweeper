#include "../header/board.h"


#include <chrono>
#include <random>
// write this line once in top
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * ((uint64_t) new char | 1));
// use this instead of rand()
template <typename T>
T Rand(T low, T high)
{
	return uniform_int_distribution<T>(low, high)(rng);
}

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
    this->mines_number = mines_number;
    preprocess_board();
}

Position Board::random_unused_position(){
    int row_size = get_row_size() , col_size = get_col_size();
    int x = -1, y = -1;
    do{
        x = Rand(0 , row_size - 1);
        y = Rand(0 , col_size - 1);
    }while(board[x][y] != nullptr);
    return Position(x , y);
}

void Board::preprocess_mines(){
    
    for(int _ = 0; _ < mines_number; _++){
        auto random_position = random_unused_position();
        board[random_position.x][random_position.y] = 
            new Cell(random_position.x, random_position.y, true, -1);
    }
}

bool Board::has_mine(int row ,int col){
    return board[row][col] != nullptr && board[row][col]->get_has_mine();
}

int Board::count_neighbour_mines(int i , int j){
    int count_neighbour_mines = 0;
    for(int dx = -1; dx <= 1; dx++){
        for(int dy = -1; dy <= 1; dy++){
            if(dx == 0 && dy == 0){
                continue;
            }
            if(is_valid_position(i + dx, j + dy) && has_mine(i + dx, j + dy)){
                count_neighbour_mines++;
            }
        }
    }
    return count_neighbour_mines;
}

void Board::add_neighbour_mines_count(){
    int row_size = get_row_size() , col_size = get_col_size();
    for(int i = 0; i < row_size; i++){
        for(int j = 0; j < col_size; j++){
            if(board[i][j] != nullptr){
                continue;
            }
            board[i][j] = new Cell(i, j, false, count_neighbour_mines(i,j));
        }
    }
}

void Board::preprocess_board(){
    preprocess_mines();
    add_neighbour_mines_count();
}

bool Board::is_valid_position(int row , int col){
    return row >= 0 && col >= 0 && row < board.size() && col < board[0].size();
}

Cell* Board::get_cell(int row , int col){
    if(!is_valid_position(row, col))
        throw new BoardBoundriesExecption;
    // if(board[row][col]->get_is_clicked() == true){
    //     throw new CellClickUsedException;
    // }
    return board[row][col];
}

void Board::reveal_all_cells(){
    for(int i = 0; i < get_row_size(); i++){
        for(int j = 0; j < get_col_size(); j++){
            if(board[i][j]->get_is_marked() == true){
                board[i][j]->mark();
            }
            if(board[i][j]->get_is_clicked() == true){
                continue;
            }
            board[i][j]->click();
        }
    }
}