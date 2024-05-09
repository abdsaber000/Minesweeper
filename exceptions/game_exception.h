#ifndef GAME_EXCEPTION
#define GAME_EXCEPTION
#include <string>
using namespace std;
class GameException{
    string message;

public:
    GameException(string message){
        this->message = message;
    }

    string error_message(){
        return message;
    }
};


#endif