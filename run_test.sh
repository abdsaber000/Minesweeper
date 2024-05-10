#!/bin/bash

#board tests
g++ ./source/*.cpp ./tests/board.test.cpp -o board_test

./board_test

rm board_test

#cell tests
g++ ./source/*.cpp ./tests/cell.test.cpp -o cell_test

./cell_test

rm cell_test

#game tests
g++ ./source/*.cpp ./tests/game.test.cpp -o game_test

./game_test

rm game_test