#include "../header/boardUI.h"

void BoardUi::clear_screen() {
    cout << "\033[2J\033[1;1H";
}

void BoardUi::print_cell(Cell* cell){
    if(cell->get_is_marked() == true){
        cout << LIGHT_GREY_BACKGROUND << RED << FLAG << RESET;
        return;
    }

    if(cell->get_is_clicked() == false){
        cout << LIGHT_GREY_BACKGROUND << ' ' << RESET;
        return;
    }

    if(cell->get_has_mine() == true){
        cout << LIGHT_GREY_BACKGROUND << BLACK << MINE << RESET;
        return;
    }


    int mines_count = cell->get_neighbour_mines_number();

    if(mines_count == 0){
        cout << DARK_GREY_BACKGROUND << ' ' << RESET;
        return;
    }

    cout << LIGHT_GREY_BACKGROUND << color[mines_count] << mines_count << RESET;
    return;
}

void BoardUi::print_top_row(int columns){
    cout << LIGHT_GREY_BACKGROUND << GREY << LEFT_UPPER_CORNER << HORIZONTAL;
    for(int i = 1; i <= columns - 1; i++){
        cout << T_JOINT_TOP << HORIZONTAL;
    }
    cout << RIGHT_UPPER_CORNER << RESET << '\n';
}

void BoardUi::print_middle_row(int columns){
    cout << LIGHT_GREY_BACKGROUND << GREY << T_JOINT_LEFT << RESET;
    for(int j = 0; j < columns - 1; j++){
        cout << LIGHT_GREY_BACKGROUND << GREY << HORIZONTAL << RESET << LIGHT_GREY_BACKGROUND << GREY << CROSS << RESET;
    }
    cout << LIGHT_GREY_BACKGROUND << GREY << HORIZONTAL << T_JOINT_RIGHT << RESET;
    cout << '\n';
}
void BoardUi::print_bottom_row(int columns){
    cout << LIGHT_GREY_BACKGROUND << GREY << LEFT_LOWER_CORNER << HORIZONTAL;
    for(int i = 1; i <= columns - 1; i++) {
        cout << T_JOINT_BOTTOM << HORIZONTAL;
    }
    cout << RIGHT_LOWER_CORNER << RESET << '\n';
    
}
void BoardUi::print_board(Board* board){
    clear_screen();
    int rows = board->get_row_size(), columns = board->get_col_size();
    print_top_row(columns);
    for(int i = 0; i < rows; i++){
        cout << LIGHT_GREY_BACKGROUND << GREY << VERTICAL << RESET;
        for(int j = 0; j < columns; j++){
            print_cell(board->get_cell(i, j));
            cout << LIGHT_GREY_BACKGROUND << GREY << VERTICAL << RESET;
        }
        cout << '\n';
        if(i != rows - 1){
            print_middle_row(columns);
        }
    }
    print_bottom_row(columns);
}


