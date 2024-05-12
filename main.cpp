#include <iostream>
#include "header/game.h"

#define START_NEW_GAME 1
#define EXIT_GAME 2

using namespace std;

void displayMenu() {
    cout << "Main Menu:\n";
    cout << "1. Start New Game\n";
    cout << "2. Exit\n";
}

int main() {
    while(1){
        displayMenu();
        int choice;
        cout << "\nEnter the number of your choice: ";
        do{
            cin >> choice;
            if(choice == START_NEW_GAME){
                cout << "Starting new game...\n";
                Game* game = new Game();
                game->play();
                break;
            }
            if(choice == EXIT_GAME){
                cout << "Exiting game...\n";
                return 0;
            }
            cout << "Invalid choice. Please enter either 1 or 2.\n";
        }while(1);
    }

    return 0;
}