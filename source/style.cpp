#include "../header/style.h"
#include <iostream>
#include <map>
#include <bits/stdc++.h>

using namespace std;

void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

void printNumber(int number){
    cout << LIGHT_GREY << color[number] << number << RESET;
}

int main(){
    cout << LIGHT_GREY << GREY;
    cout << LEFT_UPPER_CORNER << HORIZONTAL;
    for(int i = 1; i <= 9; i++) {
        cout << T_JOINT_TOP << HORIZONTAL;
    }
    cout << RIGHT_UPPER_CORNER;
    cout << RESET << '\n';
    for(int i = 1; i <= 10; i++){
        cout << LIGHT_GREY << GREY << VERTICAL << RESET;
        for(int j = 0; j < 10; j++){
            if(i == 9) cout << LIGHT_GREY << RED << FLAG << RESET << LIGHT_GREY << GREY << VERTICAL << RESET;
            if(i == 10) cout << LIGHT_GREY << BLACK << MINE << RESET << LIGHT_GREY << GREY << VERTICAL << RESET;
            if(i <= 8) cout << LIGHT_GREY << color[i] << i << RESET << LIGHT_GREY << GREY << VERTICAL << RESET;
        }   
        cout << '\n';
        if(i != 10){
            cout << LIGHT_GREY << GREY << T_JOINT_LEFT << RESET;
            for(int j = 0; j < 9; j++){
                cout << LIGHT_GREY << GREY << HORIZONTAL << RESET << LIGHT_GREY << GREY << CROSS << RESET;
            }
            cout << LIGHT_GREY << GREY << HORIZONTAL << T_JOINT_RIGHT << RESET;
            cout << '\n';
        }
    }
    cout << LIGHT_GREY << GREY;
    cout << LEFT_LOWER_CORNER << HORIZONTAL;
    for(int i = 1; i <= 9; i++) {
        cout << T_JOINT_BOTTOM << HORIZONTAL;
    }
    cout << RIGHT_LOWER_CORNER;
    cout << RESET << '\n';
    
    while(1){

    }
}
