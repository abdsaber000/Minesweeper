#include "../header/game.h"


void Game::display_difficulty_menu() {
    cout << "\nChoose Difficulty:\n";
    cout << "1. Easy\n";
    cout << "2. Medium\n";
    cout << "3. Hard\n";
}


void Game::difficulty_screen(){
    display_difficulty_menu();

    int difficulty;
    cin >> difficulty;
    while(1){
        try{
            game_controller->create_board(difficulty);
            break;
        }catch(GameException* error){
            cout << error->error_message() << '\n';
            cin >> difficulty;
        }
    }
}

void Game::game_end_screen(){
    game_controller->reveal_all_cells();
    board_ui->print_board(game_controller->get_board());
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
    x--,y--;
    game_controller->get_board()->get_cell(x, y); // check if it's valid

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



void Game::handle_turn(){
    Position play_position = get_play_position();
    char choice = get_player_choice();
    game_controller->handle_choice(play_position,choice);
}

void Game::play(){
    game_controller = new GameController;

    difficulty_screen();

    status = RUNNING;
    
    board_ui = new BoardUi();
    board_ui->print_board(game_controller->get_board());

    while(status == RUNNING){

        try{
            handle_turn();
        }catch(ClickOnMineException* error){
            status = LOSE;
            break;
        }catch(GameException* error){
            cout << error->error_message() << '\n';
            continue;
        }
        
        if(game_controller->check_win()){
            status = WIN;
        }
        if(status == RUNNING){
            board_ui->print_board(game_controller->get_board());
        }
    }

    game_end_screen();
    
}

