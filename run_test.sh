#!/bin/bash

g++ ./source/*.cpp ./tests/*.cpp -o game_test

./game_test

rm game_test