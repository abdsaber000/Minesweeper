#ifndef CELL
#define CELL

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
    bool is_releaved();
    bool get_is_marked();
    void click();
    void mark();
};

#endif