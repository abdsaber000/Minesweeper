#ifndef GAME
#define GAME

#include "board.h"
#include "boardUI.h"
#include "position.h"
#include "game_controller.h"
#include "../exceptions/invalid_move_type_choice.h"
#include "../exceptions/game_exception.h"
#include<iostream>

using namespace std;

#define MARK_CHOICE 'M'
#define CLICK_CHOICE 'C'

enum {LOSE, WIN, RUNNING};

class Game{
    private:
        GameController* game_controller;
        BoardUi* board_ui;
        int status;
        void difficulty_screen();
        void game_end_screen();
        void handle_turn();
        Position get_play_position();
        char get_player_choice();
        void display_difficulty_menu();
        bool invalid_input(string &x);
        string read_input();
    public:
        void play();
};

#endif