#ifndef BOARD_UI
#define BOARD_UI

#include<iostream>
#include<map>
#include<vector>
#include"board.h"
#include"cell.h"
using namespace std;


class BoardUi{
    private:
        const string RESET = "\033[0m";
        const string RED = "\033[31m";
        const string GREEN = "\033[32m";
        const string YELLOW = "\033[33m";
        const string BLUE = "\033[34m";
        const string MAGENTA = "\033[35m";
        const string CYAN = "\033[36m";
        const string WHITE = "\033[97m";
        const string DARK_BLUE = "\033[38;5;18m";
        const string BROWN = "\033[38;5;130m";
        const string BLACK = "\033[30m";
        const string GREY = "\033[90m";
        const string DARK_GREY = "\033[38;5;239m"; 
        const string LIGHT_GREY_BACKGROUND = "\033[48;5;253m";  
        const string MEDIUM_GREY_BACKGROUND = "\033[48;5;249m"; 
        const string DARK_GREY_BACKGROUND = "\033[48;5;239m"; 

        const char LEFT_UPPER_CORNER = 218;
        const char RIGHT_UPPER_CORNER = 191;
        const char LEFT_LOWER_CORNER = 192;
        const char RIGHT_LOWER_CORNER = 217;
        const char HORIZONTAL = 196;
        const char VERTICAL = 124;
        const char T_JOINT_LEFT = 195;
        const char T_JOINT_RIGHT = 180;
        const char T_JOINT_TOP = 194;
        const char T_JOINT_BOTTOM = 193;
        const char CROSS = 197;
        const char SQUARE = 176;
        const char FLAG = 63;
        const char MINE = 42;
    
        vector<string> color = {WHITE, BLUE, GREEN, RED, DARK_BLUE, BROWN, CYAN, BLACK, GREY};
    
        void print_cell(Cell* cell);
        void print_top_row(Board* board, int rows, int columns);
        void print_middle_row(Board* board, int row_number, int rows, int columns);
        void print_bottom_row(Board* board, int rows, int columns);
        void print_coordinate_row(int columns);
        void print_coordinate_column(int row_number);
    public:
        void clear_screen();    
        void print_board(Board* board);
};
#endif
