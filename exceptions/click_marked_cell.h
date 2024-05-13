#ifndef CLICK_MARKED_CELL_EXCEPTION
#define CLICK_MARKED_CELL_EXCEPTION
#include <string>
#include "game_exception.h"
using namespace std;
class ClickMarkedCellException : public GameException{

public:
    ClickMarkedCellException() : 
        GameException("You can't click on marked cell.") 
    {
        
    }

};


#endif