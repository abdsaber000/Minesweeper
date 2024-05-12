#ifndef GAME
#define GAME

#include "board.h"
#include "boardUI.h"

#define MARK_CHOICE 'M'
#define CLICK_CHOICE 'C'

enum {LOSE, WIN, RUNNING};

class Game{
    private:
        Board *board;
        int status;
        void reveal_cell(int x, int y, bool flag);
    public:
        void create_board(int level);
        void mark_cell(int x, int y);
        void click_cell(int x, int y);
        void play();
        void display_difficulty_menu();
        void check_win();
};

#endif