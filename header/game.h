#ifndef GAME
#define GAME

#include "board.h"
#include "boardUI.h"
#include "position.h"
#include "../exceptions/invalid_move_type_choice.h"
#include "../exceptions/game_exception.h"
#include<iostream>

using namespace std;

#define MARK_CHOICE 'M'
#define CLICK_CHOICE 'C'

enum {LOSE, WIN, RUNNING};

class Game{
    private:
        Board *board;
        BoardUi* board_ui;
        int status;
        void reveal_cell(int x, int y);
        bool can_move_to_neighbour(int x , int y);
        void move_to_neighbour(int x,int y);
        void difficulty_screen();
        void game_end_screen();
        void handle_choice(Position position , char choice);
        void handle_turn();
        Position get_play_position();
        char get_player_choice();
        void create_board(int level);
        void mark_cell(int x, int y);
        void click_cell(int x, int y);
        void display_difficulty_menu();
        void check_win();
    public:
        void play();
};

#endif