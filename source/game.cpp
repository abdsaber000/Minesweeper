#include "../header/game.h"
#include "../header/board.h"
#include "../exceptions/game_exception.h"
#include <iostream>

using namespace std;

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

void Game::play(){
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
    status = RUNNING;
    
    BoardUi* board_ui = new BoardUi();
    board_ui->print_board(board);

    while(status == RUNNING){
        int x, y;
        cout << "Enter the x position: ";
        cin >> x;
        cout << "Enter the y position: ";
        cin >> y;
        try{
            board->get_cell(x, y);
        }catch(GameException* error){
            cout << error->error_message() << '\n';
            continue;
        }
        cout << "Enter the letter 'M' for mark or 'C' for click: ";
        char choice;
        cin >> choice;
        if(choice != MARK_CHOICE && choice != CLICK_CHOICE){
            cout << "Invalid input\n";
            continue;
        }
        try{
            if(choice == MARK_CHOICE){
                mark_cell(x, y);
            }
            else if(choice == CLICK_CHOICE){
                click_cell(x, y);
            }
        }catch(GameException* error){
            cout << error->error_message() << "\n";
            continue;
        }
        
        check_win();
        if(status == RUNNING){
            board_ui->print_board(board);
        }
    }

    board->reveal_all_cells();
    board_ui->print_board(board);
    if(status == LOSE){
        cout << "Uh-oh! You've stumbled upon a minefield. Game over.\n";
    }
    else{
        cout << "Good job\n";
    }
}

void Game::reveal_cell(int x, int y, bool flag){
    if(flag == true){
        board->get_cell(x, y)->mark();
        return;
    }


    if(board->get_cell(x, y)->get_has_mine() == true){
        status = LOSE;
        return;
    }
    
    
    board->get_cell(x, y)->click();
    if(board->get_cell(x, y)->get_neighbour_mines_number() > 0){
        return;
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    for(int k = 0; k < 4; k++){
        int nx = x + dx[k], ny = y + dy[k];
        if(board->is_valid_position(nx , ny) == false){
            continue;
        }
        if(board->get_cell(nx, ny)->get_has_mine() == true){
            continue;
        }
        if(board->get_cell(nx, ny)->get_is_marked() == true){
            continue;
        }
        if(board->get_cell(nx, ny)->get_is_clicked() == true){
            continue;
        }
        reveal_cell(nx, ny, flag);
    }
}

void Game::click_cell(int x, int y){
    reveal_cell(x, y, false);
}

void Game::mark_cell(int x, int y){
    reveal_cell(x, y, true);
}