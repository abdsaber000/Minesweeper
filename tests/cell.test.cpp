#include<iostream>
#include "../header/cell.h"
#include "GameTest.h"
#include "test_case.h"

using namespace std;

GameTest *game_test;


int main(){
    game_test = new GameTest("Cell test");

    game_test->run();
}