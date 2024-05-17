#include "../header/game.h"


void Game::display_difficulty_menu() {
    cout << "\nChoose Difficulty:\n";
    cout << "1. Easy\n";
    cout << "2. Medium\n";
    cout << "3. Hard\n";
}


void Game::difficulty_screen(){
    display_difficulty_menu();

    string difficulty;
    fflush(stdin);
    fflush(stdout);
    getline(cin , difficulty);
    while(1){
        try{
            if(difficulty.size() != 1 && (difficulty[0] - '0') < 1 && (difficulty[0] - '0') > 3)
                throw new BoardTypeExecption;
            create_board(difficulty[0] - '0');
            game_controller->create_board(difficulty);
            break;
        }catch(GameException* error){
            cout << error->error_message() << '\n';
            fflush(stdin);
            fflush(stdout);
            getline(cin, difficulty);
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
    string x, y;
    cout << "Enter the x position: ";
    fflush(stdin);
    fflush(stdout);
    getline(cin, x);
    cout << "Enter the y position: ";
    cin >> y;
    x--,y--;
    game_controller->get_board()->get_cell(x, y); // check if it's valid
    fflush(stdin);
    fflush(stdout);
    getline(cin, y);
    if(x.size() == 0 || x.size() >= 3)
        throw new BoardBoundriesExecption;
    else if ((x[0] - '0') < 1 || (x[0] - '0') > 9)
        throw new BoardBoundriesExecption;
    else if (x.size() == 2 && ((x[1] - '0') < 0 || (x[1] - '0') > 9))
        throw new BoardBoundriesExecption;
    if (y.size() == 0 || y.size() >= 3)
        throw new BoardBoundriesExecption;
    else if ((y[0] - '0') < 1 || (y[0] - '0') > 9)
        throw new BoardBoundriesExecption;
    else if (y.size() == 2 && ((y[1] - '0') < 0 || (y[1] - '0') > 9))
        throw new BoardBoundriesExecption;
    int nx = stoi(x);
    int ny = stoi(y);
    board->get_cell(nx - 1, ny - 1); // check if it's valid

    return Position(nx - 1,ny - 1);

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

