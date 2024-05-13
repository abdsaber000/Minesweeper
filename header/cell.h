#ifndef CELL
#define CELL

#include "../exceptions/cell_click_used_exception.h"
#include "../exceptions/click_marked_cell.h"

class Cell{
    int x;
    int y;
    int neighbour_mines_number;
    bool is_clicked;
    bool is_marked;
    bool has_mine;
public:
    Cell(int x,  int y, bool has_mine, int neighbour_mines_number);
    int get_neighbour_mines_number();
    bool get_has_mine();
    bool get_is_clicked();
    bool get_is_marked();
    void click();
    void mark();
};

#endif