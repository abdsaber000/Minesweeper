#ifndef CLICK_USED_EXCEPTION
#define CLICK_USED_EXCEPTION
#include <string>
#include "game_exception.h"
using namespace std;
class CellClickUsedException : public GameException{

public:
    CellClickUsedException() : 
        GameException("Invalid choice, this cell is already clicked") 
    {
        
    }

};


#endif