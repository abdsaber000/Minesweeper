#include<iostream>
#include "../header/board.h"
#include "../exceptions/game_exception.h"
#include "GameTest.h"
#include "test_case.h"

using namespace std;

GameTest *game_test;

void test_create_board(){
    
    auto board = Board::create_board(EASY); 
    game_test->add_test(new TestCase(
        board->get_col_size() == EASY_BOARD_SIZE,
        "should equal easy board column size"
    ));

    game_test->add_test(new TestCase(
        board->get_col_size() == EASY_BOARD_SIZE,
        "should equal easy board row size"
    ));

    board = Board::create_board(MEDIUM);

    game_test->add_test(new TestCase(
        board->get_col_size() == MEDIUM_BOARD_SIZE,
        "should equal medium board column size"
    ));

    game_test->add_test(new TestCase(
        board->get_col_size() == MEDIUM_BOARD_SIZE,
        "should equal medium board row size"
    ));

    board = Board::create_board(HARD);

    game_test->add_test(new TestCase(
        board->get_col_size() == HARD_BOARD_SIZE,
        "should equal hard board column size"
    ));

    game_test->add_test(new TestCase(
        board->get_col_size() == HARD_BOARD_SIZE,
        "should equal hard board row size"
    ));
   
}

void try_cell(int row , int col, bool status , Board* board){
    try{
        board->get_cell(row, col);
        game_test->add_test(new TestCase(
            status,
            "should access valid cell"
        ));
    }catch(GameException *error){
        game_test->add_test(new TestCase(
            !status,
            error->error_message()
        ));
    }
}

void try_valid_cell(int row, int col , Board* board){
    try_cell(row , col , true, board);
}

void try_wrong_cell(int row, int col , Board* board){
    try_cell(row , col , false, board);
}

void test_get_cell(){
    auto board = Board::create_board(EASY);

    try_valid_cell(0,0,board);
    try_valid_cell(5,5,board);
    try_valid_cell(EASY_BOARD_SIZE - 1,0,board);
    try_valid_cell(0,EASY_BOARD_SIZE - 1,board);
    try_valid_cell(EASY_BOARD_SIZE - 1,EASY_BOARD_SIZE - 1,board);


    try_wrong_cell(-1,0,board);
    try_wrong_cell(0,-1,board);
    try_wrong_cell(-1,-1,board);
    try_wrong_cell(EASY_BOARD_SIZE,0,board);
    try_wrong_cell(0,EASY_BOARD_SIZE,board);
}

int main(){
    game_test = new GameTest("board test");
    test_create_board();
    test_get_cell();

    game_test->run();
}