#include "../header/boardUI.h"
#include "../header/board.h"
#include "../header/cell.h"

int main(){
    Board *board = Board::create_board(EASY);
    BoardUi *board_ui = new BoardUi;
    for(int i = 0; i < 6; i++){
            board_ui->clear_screen();
            board_ui->print_board(board);
            int x, y;
            std::cout << "Enter the x pos: "; cin >> x;
            std::cout << "Enter the y pos: "; cin >> y;
            board->get_cell(x, y)->click();

        }

}