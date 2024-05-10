#include<iostream>
#include "../header/game.h"
#include "GameTest.h"
#include "test_case.h"

using namespace std;

GameTest *game_test;



void test_create_board(){
    Game* game = new Game;
    try{
        game->create_board(EASY);
        game_test->add_test(new TestCase(
            true,
            "should create easy board"
        ));
    }catch(GameException *error){
        game_test->add_test(new TestCase(
            false,
            "should create easy board"
        ));
    }

    try{
        game->create_board(MEDIUM);
        game_test->add_test(new TestCase(
            true,
            "should create medium board"
        ));
    }catch(GameException *error){
        game_test->add_test(new TestCase(
            false,
            "should create medium board"
        ));
    }

    try{
        game->create_board(HARD);
        game_test->add_test(new TestCase(
            true,
            "should create hard board"
        ));
    }catch(GameException *error){
        game_test->add_test(new TestCase(
            false,
            "should create hard board"
        ));
    }

    try{
        game->create_board(3);
        game_test->add_test(new TestCase(
            false,
            "should not create invalid board"
        ));
    }catch(GameException *error){
        game_test->add_test(new TestCase(
            true,
            "should not create invalid board"
        ));
    }

}


int main(){
    game_test = new GameTest("Game test");
    test_create_board();
    game_test->run();
}