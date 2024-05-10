#ifndef STYLE_H
#define STYLE_H

#include <iostream>
#include <map>

using namespace std;

const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[97m";
const string DARK_BLUE = "\033[38;5;18m";
const string BROWN = "\033[38;5;130m";
const string BLACK = "\033[30m";
const string GREY = "\033[90m";
const string LIGHT_GREY = "\033[47m";
const string DARK_GREY = "\033[100m"; 


const char LEFT_UPPER_CORNER = 218;
const char RIGHT_UPPER_CORNER = 191;
const char LEFT_LOWER_CORNER = 192;
const char RIGHT_LOWER_CORNER = 217;
const char HORIZONTAL = 196;
const char VERTICAL = 124;
const char T_JOINT_LEFT = 195;
const char T_JOINT_RIGHT = 180;
const char T_JOINT_TOP = 194;
const char T_JOINT_BOTTOM = 193;
const char CROSS = 197;
const char SQUARE = 176;
const char FLAG = 63;
const char MINE = 42;
const char MIDDLE_DOT = 183;


map<int, string> color = {
    {0, WHITE},
    {1, BLUE},
    {2, GREEN},
    {3, RED},
    {4, DARK_BLUE},
    {5, BROWN},
    {6, CYAN},
    {7, BLACK},
    {8, GREY}
};

void clearScreen();

void printNumber(int number);

#endif
