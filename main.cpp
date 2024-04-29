#include "btree.hpp"
#include "linkedlist.hpp"
#include "mainHelper.cpp"

#ifndef MAIN_CPP
#define MAIN_CPP


int main(){
    AVLTree* userTree = new AVLTree();
    linkedlist* userList = new linkedlist();
    string fileName = "fakePersonData.csv";

    loadLinkedList(fileName, userList);
    loadAVL(fileName, userTree);



   int userChoice = -1;
/*
    do{
        displayMenu();
        cout << "\nEnter selection: ";
        cin >> userChoice;
        switch(userChoice){
            case 1://insert
                

                break;
            case 2://remove
                break;
            case 3://ID search
                break;
            case 4://Name search
                break;
            case 5://update
                break;
            case 6://exit
                break;
            default: 
        }
    }while(userChoice != 6);
*/

    return 0;

}


#endif