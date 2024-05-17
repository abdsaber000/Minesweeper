#ifndef CLICK_ON_MINE_EXCEPTION
#define CLICK_ON_MINE_EXCEPTION
#include <string>
#include "game_exception.h"
using namespace std;
class ClickOnMineException : public GameException{

public:
    ClickOnMineException() : 
        GameException("Game over. you clicked on mine.") 
    {
        
    }

};


#endif