#!/bin/bash

#board tests
g++ ./source/*.cpp ./tests/board.test.cpp -o board_test

./board_test

rm board_test

#cell tests
g++ ./source/*.cpp ./tests/cell.test.cpp -o cell_test

./cell_test


rm cell_test

#boardUi tests
g++ ./source/*.cpp ./tests/boardUiTest.cpp -o board_ui_test
./board_ui_test