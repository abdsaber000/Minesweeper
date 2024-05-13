#include "../header/game.h"


void Game::display_difficulty_menu() {
    cout << "\nChoose Difficulty:\n";
    cout << "1. Easy\n";
    cout << "2. Medium\n";
    cout << "3. Hard\n";
}


void Game::create_board(int level){
    board = Board::create_board(level);
}


void Game::check_win(){
    bool all_clicked_except_mines = true;
    for(int i = 0; i < board->get_row_size(); i++){
        for(int j = 0; j < board->get_col_size(); j++){
            Cell* current_cell;
            try{
                current_cell = board->get_cell(i, j);
                if(current_cell->get_has_mine() == false){
                    all_clicked_except_mines = false;
                }
            }catch(GameException* error){
                if(current_cell->get_has_mine() == true){
                    all_clicked_except_mines = false;
                }    
            }
            
        }
    }
    if(all_clicked_except_mines == true){
        status = WIN;
    }
}

void Game::difficulty_screen(){
    display_difficulty_menu();

    int difficulty;
    cin >> difficulty;
    while(1){
        try{
            create_board(difficulty);
            break;
        }catch(GameException* error){
            cout << error->error_message() << '\n';
            cin >> difficulty;
        }
    }
}

void Game::game_end_screen(){
    board->reveal_all_cells();
    board_ui->print_board(board);
    if(status == LOSE){
        cout << "Uh-oh! You've stumbled upon a minefield. Game over.\n";
    }
    else{
        cout << "Good job\n";
    }
}

Position Game::get_play_position(){
    int x, y;
    cout << "Enter the x position: ";
    cin >> x;
    cout << "Enter the y position: ";
    cin >> y;

    board->get_cell(x, y); // check if it's valid

    return Position(x,y);

}

char Game::get_player_choice(){
    cout << "Enter the letter 'M' for mark or 'C' for click: ";
    char choice;
    cin >> choice;
    if(choice != MARK_CHOICE && choice != CLICK_CHOICE){
        throw new InvalidMoveTypeChoiceException;
    }
    return choice;
}

void Game::handle_choice(Position position , char choice){
    if(choice == MARK_CHOICE){
        mark_cell(position.x, position.y);
    }
    else if(choice == CLICK_CHOICE){
        click_cell(position.x, position.y);
    }
}

void Game::handle_turn(){
    Position play_position = get_play_position();
    char choice = get_player_choice();
    handle_choice(play_position,choice);
}

void Game::play(){
    difficulty_screen();

    status = RUNNING;
    
    board_ui = new BoardUi();
    board_ui->print_board(board);

    while(status == RUNNING){

        try{
            handle_turn();
        }catch(GameException* error){
            cout << error->error_message() << '\n';
            continue;
        }
        
        check_win();
        if(status == RUNNING){
            board_ui->print_board(board);
        }
    }

    game_end_screen();
    
}

bool Game::can_move_to_neighbour(int nx , int ny){
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

void Game::move_to_neighbour(int x, int y){
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    for(int k = 0; k < 4; k++){
        int nx = x + dx[k], ny = y + dy[k];
        if(!can_move_to_neighbour(nx,ny))
            continue;
        reveal_cell(nx, ny);
    }
}

void Game::reveal_cell(int x, int y){


    if(board->get_cell(x, y)->get_has_mine() == true){
        status = LOSE;
        return;
    }
    
    
    board->get_cell(x, y)->click();
    if(board->get_cell(x, y)->get_neighbour_mines_number() > 0){
        return;
    }

    move_to_neighbour(x,y);
}

void Game::click_cell(int x, int y){
    reveal_cell(x, y);
}

void Game::mark_cell(int x, int y){
    board->get_cell(x, y)->mark();
}