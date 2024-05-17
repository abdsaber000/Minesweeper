#include "../header/game.h"


string Game::read_input(){
    string s;
    fflush(stdin);
    fflush(stdout);
    getline(cin , s);
    return s;
}

void Game::display_difficulty_menu() {
    cout << "\nChoose Difficulty:\n";
    cout << "1. Easy\n";
    cout << "2. Medium\n";
    cout << "3. Hard\n";
}


void Game::difficulty_screen(){
    display_difficulty_menu();

    string difficulty = read_input();
    while(1){
        try{
            if(difficulty.size() != 1 || (difficulty[0] - '0') < 1 || (difficulty[0] - '0') > 3)
                throw new BoardTypeExecption;
            game_controller->create_board(difficulty[0] - '0');
            break;
        }catch(GameException* error){
            cout << error->error_message() << '\n';
            difficulty = read_input();
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

bool Game::invalid_input(string &x) {
    if (x.size() == 0 || x.size() >= 3)
        return true;
    else if ((x[0] - '0') < 1 || (x[0] - '0') > 9)
        return true;
    else if (x.size() == 2 && ((x[1] - '0') < 0 || (x[1] - '0') > 9))
        return true;
    return false;
}


Position Game::get_play_position(){
    string x, y;
    cout << "Enter the x position: ";
    x = read_input();
    cout << "Enter the y position: ";
    y = read_input();
    if(invalid_input(x) || invalid_input(y)) 
        throw new BoardBoundriesExecption;
    int nx = stoi(x);
    int ny = stoi(y);
    game_controller->get_board()->get_cell(nx - 1, ny - 1); // check if it's valid
    return Position(nx - 1,ny - 1);

}

char Game::get_player_choice(){
    cout << "Enter the letter 'M' for mark or 'C' for click: ";
    string choice;
    while (1)
    {
        choice = read_input();
        try
        {
            if (choice.empty() || choice.size() > 1 || toupper(choice[0]) != MARK_CHOICE && toupper(choice[0]) != CLICK_CHOICE)
            {
                throw new InvalidMoveTypeChoiceException;
            }
            return toupper(choice[0]);
        }
        catch(GameException *error)
        {
            cout << error->error_message();
        }
    }
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

