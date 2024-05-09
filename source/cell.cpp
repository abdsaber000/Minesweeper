#include "../header/cell.h"


Cell::Cell(int x,  int y, bool has_mine){
    this->x = x;
    this->y = y;
    this->has_mine = has_mine;
    is_clicked = false;
    is_marked = false;
}

bool Cell::click(){
    if(has_mine)
        return false;
    is_clicked = true;
    return true;
}

bool Cell::mark(){
    if(is_clicked)
        return false;
    is_marked = !is_marked;
    return true;
}