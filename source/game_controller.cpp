#include "../header/game_controller.h"



void GameController::create_board(int level){
    board = Board::create_board(level);
}


bool GameController::check_win(){
    int total_non_mine_cells = board->get_row_size() * board->get_col_size() - board->get_mines_count();
    return total_non_mine_cells == board->get_opened_cells_count();
}



void GameController::handle_choice(Position position , char choice){
    if(choice == MARK_CHOICE){
        mark_cell(position.x, position.y);
    }
    else if(choice == CLICK_CHOICE){
        click_cell(position.x, position.y);
    }
}


bool GameController::can_move_to_neighbour(int nx , int ny){
    if(board->is_valid_position(nx , ny) == false){
        return false;
    }
    if(board->get_cell(nx, ny)->get_has_mine() == true){
        return false;
    }
    if(board->get_cell(nx, ny)->get_is_marked() == true){
        return false;
    }
    if(board->get_cell(nx, ny)->get_is_clicked() == true){
        return false;
    }
    return true;
}

void GameController::move_to_neighbour(int x, int y){
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    for(int k = 0; k < 4; k++){
        int nx = x + dx[k], ny = y + dy[k];
        if(!can_move_to_neighbour(nx,ny))
            continue;
        reveal_cell(nx, ny);
    }
}

void GameController::reveal_cell(int x, int y){
    
    board->get_cell(x, y)->click();
    board->add_one_opened_cell();

    if(board->get_cell(x, y)->get_neighbour_mines_number() > 0){
        return;
    }

    move_to_neighbour(x,y);
}

void GameController::click_cell(int x, int y){
    if(board->get_cell(x, y)->get_has_mine() == true){
        throw new ClickOnMineException;
    }
    reveal_cell(x, y);
}

void GameController::mark_cell(int x, int y){
    board->get_cell(x, y)->mark();
}

Board* GameController::get_board(){
    return board;
}

void GameController::reveal_all_cells(){
    board->reveal_all_cells();
}