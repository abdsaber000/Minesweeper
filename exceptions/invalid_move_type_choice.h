#ifndef INVALID_MOVE_TYPE_CHOICE_EXCEPTION
#define INVALID_MOVE_TYPE_CHOICE_EXCEPTION
#include <string>
#include "game_exception.h"
using namespace std;
class InvalidMoveTypeChoiceException : public GameException{

public:
    InvalidMoveTypeChoiceException() : 
        GameException("Invalid choice. Type 'M' to mark or 'C' to click.") 
    {
        
    }

};


#endif