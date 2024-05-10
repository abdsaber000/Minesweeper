#ifndef CELL
#define CELL

class Cell{
    int x;
    int y;
    int mines_number;
    bool is_clicked;
    bool is_marked;
    bool has_mine;
public:
    Cell(int x,  int y, bool has_mine);
    bool click();
    bool mark();
};

#endif