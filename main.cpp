#include "btree.hpp"

void displayMenu();

int main(){
    AVLTree userTree;

    int userChoice = -1;

    do{
        displayMenu();
        cin >> userChoice;
        switch(userChoice){
            case 1:
                break;
            case 2:
                break;
            case 3: 
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            default: 
        }
    }while(userChoice != 6);

    return 0;
}



void displayMenu(){
    cout << "Select an action to execute: \n\n";
    cout << "1. Add student.\n";
    cout << "2. Remove student.\n";
    cout << "3. Search student by ID.\n";
    cout << "4. Search student by name.\n";
    cout << "5. Update student info.\n";
    cout << "6. Exit.\n";
    cout << "\nEnter selection: ";
}
