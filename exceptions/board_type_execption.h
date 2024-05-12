#ifndef BOARD_TYPE_EXCEPTION
#define BOARD_TYPE_EXCEPTION
#include <string>
#include "game_exception.h"
using namespace std;
class BoardTypeExecption : public GameException{

public:
    BoardTypeExecption() : 
        GameException("Invalid board type, should be between 1 and 3") 
    {
        
    }

};


#endif