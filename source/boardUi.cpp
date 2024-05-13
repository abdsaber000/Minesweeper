#include "../header/boardUI.h"

void BoardUi::clear_screen() {
    cout << "\033[2J\033[1;1H";
}

void BoardUi::print_cell(Cell* cell){
    if(cell->get_is_marked() == true){
        cout << LIGHT_GREY_BACKGROUND << RED << ' ' << FLAG << ' ' << RESET;
        return;
    }

    if(cell->get_is_clicked() == false){
        cout << LIGHT_GREY_BACKGROUND << "   " << RESET;
        return;
    }

    if(cell->get_has_mine() == true){
        cout << MEDIUM_GREY_BACKGROUND << BLACK << ' ' << MINE << ' ' << RESET;
        return;
    }


    int mines_count = cell->get_neighbour_mines_number();

    if(mines_count == 0){
        cout << MEDIUM_GREY_BACKGROUND << "   " << RESET;
        return;
    }

    cout << MEDIUM_GREY_BACKGROUND << color[mines_count] << ' ' << mines_count << ' ' << RESET;
    return;
}

void BoardUi::print_top_row(Board* board, int rows, int columns){
    print_coordinate_column(-1);
    string BACKGROND_COLOR = LIGHT_GREY_BACKGROUND;
    cout << BACKGROND_COLOR << DARK_GREY << LEFT_UPPER_CORNER << HORIZONTAL << HORIZONTAL << HORIZONTAL << RESET;
    for(int i = 1; i <= columns - 1; i++){
        string T_JOIN_BACKGROUND_COLOR = LIGHT_GREY_BACKGROUND;
        string HORIZONTAL_BACKGROUND_COLOR = LIGHT_GREY_BACKGROUND;
        cout << T_JOIN_BACKGROUND_COLOR << DARK_GREY << T_JOINT_TOP << RESET;
        cout << HORIZONTAL_BACKGROUND_COLOR << DARK_GREY << HORIZONTAL << HORIZONTAL << HORIZONTAL << RESET;
    }
    cout << BACKGROND_COLOR << DARK_GREY << RIGHT_UPPER_CORNER << RESET << '\n';
}

void BoardUi::print_middle_row(Board* board, int row_number, int rows, int columns){
    print_coordinate_column(-1);
    string BACKGROND_COLOR = LIGHT_GREY_BACKGROUND;
    cout << BACKGROND_COLOR << DARK_GREY << T_JOINT_LEFT << RESET;
    for(int i = 1; i <= columns - 1; i++){
        string HORIZONTAL_BACKGROUND_COLOR = LIGHT_GREY_BACKGROUND;
        string CROSS_BACKGROUND_COLOR = LIGHT_GREY_BACKGROUND;
        if(board->get_cell(row_number, i - 1)->get_is_clicked() == true && board->get_cell(row_number + 1, i - 1)->get_is_clicked() == true){
            HORIZONTAL_BACKGROUND_COLOR = MEDIUM_GREY_BACKGROUND;
            if(board->get_cell(row_number, i)->get_is_clicked() == true && board->get_cell(row_number + 1, i)->get_is_clicked() == true){
                CROSS_BACKGROUND_COLOR = MEDIUM_GREY_BACKGROUND;
            }
        }
        cout << HORIZONTAL_BACKGROUND_COLOR << DARK_GREY << HORIZONTAL << HORIZONTAL << HORIZONTAL << RESET;
        cout << CROSS_BACKGROUND_COLOR << DARK_GREY << CROSS << RESET;
    }
    BACKGROND_COLOR = LIGHT_GREY_BACKGROUND;
       
    if(board->get_cell(row_number, columns - 1)->get_is_clicked() == true && board->get_cell(row_number + 1, columns - 1)->get_is_clicked() == true){
        BACKGROND_COLOR = MEDIUM_GREY_BACKGROUND;
    }
    cout << BACKGROND_COLOR << DARK_GREY << HORIZONTAL << HORIZONTAL << HORIZONTAL << RESET;
    cout << LIGHT_GREY_BACKGROUND << DARK_GREY << T_JOINT_RIGHT << RESET;
    cout << '\n';
}
void BoardUi::print_bottom_row(Board* board, int rows, int columns){
    print_coordinate_column(-1);
    string BACKGROND_COLOR = LIGHT_GREY_BACKGROUND;
    cout << BACKGROND_COLOR << DARK_GREY << LEFT_LOWER_CORNER << HORIZONTAL << HORIZONTAL << HORIZONTAL << RESET;
    for(int i = 1; i <= columns - 1; i++){
        string T_JOIN_BACKGROUND_COLOR = LIGHT_GREY_BACKGROUND;
        string HORIZONTAL_BACKGROUND_COLOR = LIGHT_GREY_BACKGROUND;
        cout << T_JOIN_BACKGROUND_COLOR << DARK_GREY << T_JOINT_BOTTOM << RESET;
        cout << HORIZONTAL_BACKGROUND_COLOR << DARK_GREY << HORIZONTAL << HORIZONTAL << HORIZONTAL << RESET;
    }
    BACKGROND_COLOR = LIGHT_GREY_BACKGROUND;
    cout << BACKGROND_COLOR << DARK_GREY << RIGHT_LOWER_CORNER << RESET << '\n';
    
}

void BoardUi::print_coordinate_row(int columns){
    cout << LIGHT_GREY_BACKGROUND << BLACK;
    cout << "     ";
    for(int i = 1; i <= columns; i++){
        cout << ' ';
        cout << i << ' ';
        if(i <= 9) cout << ' ';
    }
    cout << RESET;
    cout << '\n';
}

void BoardUi::print_coordinate_column(int row_number){
    cout << LIGHT_GREY_BACKGROUND << BLACK;
    cout << ' ';
    if(row_number <= 9) cout << ' ';
    if(row_number == -1){
        cout << "  " << RESET;
    }
    else{
        cout << row_number << ' ' << RESET;
    }
}
void BoardUi::print_board(Board* board){
    clear_screen();
    int rows = board->get_row_size(), columns = board->get_col_size();
    print_coordinate_row(columns);
    print_top_row(board, rows, columns);
    for(int i = 0; i < rows; i++){
        print_coordinate_column(i + 1);
        cout << LIGHT_GREY_BACKGROUND << GREY << VERTICAL << RESET;
        for(int j = 0; j < columns; j++){
            print_cell(board->get_cell(i, j));
            string BACKGROUND_COLOR = LIGHT_GREY_BACKGROUND;
            if(j + 1 < columns){
                if(board->get_cell(i, j)->get_is_clicked() == true && board->get_cell(i, j + 1)->get_is_clicked() == true){
                    BACKGROUND_COLOR = MEDIUM_GREY_BACKGROUND;
                }
            }
            cout << BACKGROUND_COLOR << GREY << VERTICAL << RESET;
        }
        cout << '\n';
        if(i != rows - 1){
            print_middle_row(board, i, rows, columns);
        }
    }
    print_bottom_row(board, rows, columns);
}


