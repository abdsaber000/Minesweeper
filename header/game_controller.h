#ifndef GAME_CONTROLLER
#define GAME_CONTROLLER

#include "board.h"
#include "boardUI.h"
#include "position.h"
#include "../exceptions/invalid_move_type_choice.h"
#include "../exceptions/game_exception.h"
#include "../exceptions/click_on_mine_exception.h"
#include<iostream>

using namespace std;

#define MARK_CHOICE 'M'
#define CLICK_CHOICE 'C'


class GameController{
    private:
        Board *board;
        void reveal_cell(int x, int y);
        bool can_move_to_neighbour(int x , int y);
        void move_to_neighbour(int x,int y);
        void mark_cell(int x, int y);
        void click_cell(int x, int y);
    public:
        void handle_choice(Position position , char choice);
        bool check_win();
        void create_board(int level);
        Board* get_board();
        void reveal_all_cells();
};

#endif