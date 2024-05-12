#include "../header/cell.h"


Cell::Cell(int x,  int y, bool has_mine, int neighbour_mines_number){
    this->x = x;
    this->y = y;
    this->has_mine = has_mine;
    this->neighbour_mines_number = neighbour_mines_number;
    is_clicked = false;
    is_marked = false;
}

int Cell::get_neighbour_mines_number(){
    return this->neighbour_mines_number;
}

bool Cell::get_has_mine(){
    return this->has_mine;
}

bool Cell::get_is_clicked(){
    return this->is_clicked;
}


void Cell::click(){
    if(is_clicked){
        throw new CellClickUsedException;
    }
    is_clicked = true;
}

void Cell::mark(){
    if(is_clicked){
        throw new CellClickUsedException;
    }
    is_marked = !is_marked;
}

bool Cell::get_is_marked(){
    return this->is_marked;
}