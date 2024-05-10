#include "../header/game.h"

void Game::create_board(int level){
    board = Board::create_board(level);
}