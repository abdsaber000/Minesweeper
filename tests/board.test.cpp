#include<iostream>
#include<cassert>
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
        "Check column size equal to easy board column size"
    ));

    game_test->add_test(new TestCase(
        board->get_col_size() == EASY_BOARD_SIZE,
        "Check row size equal to easy board row size"
    ));

    board = Board::create_board(MEDIUM);

    game_test->add_test(new TestCase(
        board->get_col_size() == MEDIUM_BOARD_SIZE,
        "Check column size equal to medium board column size"
    ));

    game_test->add_test(new TestCase(
        board->get_col_size() == MEDIUM_BOARD_SIZE,
        "Check row size equal to medium board row size"
    ));

    board = Board::create_board(HARD);

    game_test->add_test(new TestCase(
        board->get_col_size() == HARD_BOARD_SIZE,
        "Check column size equal to hard board column size"
    ));

    game_test->add_test(new TestCase(
        board->get_col_size() == HARD_BOARD_SIZE,
        "Check row size equal to hard board row size"
    ));
   
}

int main(){
    game_test = new GameTest("board test");
    test_create_board();


    game_test->run();
}