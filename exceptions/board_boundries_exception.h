#ifndef BOARD_BOUNDRIES_EXCEPTION
#define BOARD_BOUNDRIES_EXCEPTION
#include <string>
#include "game_exception.h"
using namespace std;
class BoardBoundriesExecption : public GameException{

public:
    BoardBoundriesExecption() : 
        GameException("Invalid position, the row and column value should be inside the board") 
    {
        
    }

};


#endif